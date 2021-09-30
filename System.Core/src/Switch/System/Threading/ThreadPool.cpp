#include "../../../../include/Switch/System/Threading/ThreadPool.hpp"
#include "../../../../include/Switch/System/Convert.hpp"
#include "../../../../include/Switch/System/Environment.hpp"
#include "../../../../include/Switch/System/Threading/Mutex.hpp"
#include "../../../../include/Switch/System/Threading/ThreadInterruptedException.hpp"
#include "../../../../include/Switch/System/Threading/Timeout.hpp"
#include "NamedHandleCollection.hpp"

using namespace System;
using namespace System::Threading;

namespace {
  class Semaphore: public WaitHandle {
  public:
    Semaphore() {}
    Semaphore(int32 initialCount, int32 maximumCount) : count(ref_new<int32>(initialCount)), maxCount(ref_new<int32>(maximumCount)) {}
    Semaphore(const Semaphore& semaphore) : guard(semaphore.guard), signal(semaphore.signal), count(semaphore.count), maxCount(semaphore.maxCount), name(semaphore.name) {}
    ~Semaphore() {this->Close();}
    Semaphore& operator =(const Semaphore& semaphore) {
      this->guard = semaphore.guard;
      this->signal = semaphore.signal;
      this->count = semaphore.count;
      this->maxCount = semaphore.maxCount;
      this->name = semaphore.name;
      return *this;
    }

    void Close() override {
      if (this->guard == null)
        return;
      if (this->name() != "")
        this->name.Reset();
      this->guard.Reset();
      this->signal.Reset();
      this->count.Reset();
      this->maxCount.Reset();
    }

    bool Equals(const Semaphore& value) const {return this->guard == value.guard && this->signal == value.signal && this->count == value.count &&  this->maxCount == value.maxCount && this->name == value.name;}
    bool Equals(const Object& obj) const override {return is<Semaphore>(obj) && this->Equals((const Semaphore&)obj);}

    int32 Release() {return this->Release(1);}
    int32 Release(int32 releaseCount) {
      if (this->guard == null)
        throw ObjectDisposedException(caller_);
      std::unique_lock<std::mutex> lock(*this->guard);
      if (*this->count + releaseCount > *this->maxCount)
        throw InvalidOperationException(caller_);
      *this->count += releaseCount;
      this->signal->notify_all();
      return *this->count - releaseCount;
    }

  private:
    bool Signal() override {
      this->Release();
      return true;
    }

    bool Wait(int32 millisecondsTimeOut) override {
      if (this->guard == null)
        throw ObjectDisposedException(caller_);
      if (millisecondsTimeOut < -1)
        throw AbandonedMutexException(caller_);

      std::unique_lock<std::mutex> lock(*this->guard);
      while (*this->count == 0) {
        if (millisecondsTimeOut == -1)
          this->signal->wait(lock);
        else if (this->signal->wait_for(lock, std::chrono::milliseconds(millisecondsTimeOut)) == std::cv_status::timeout)
          return false;
      }

      *this->count -= 1;
      return true;
    }

    refptr<std::mutex> guard = ref_new<std::mutex>();
    refptr<std::condition_variable> signal = ref_new<std::condition_variable>();
    refptr<int32> count = ref_new<int32>(0);
    refptr<int32> maxCount = ref_new<int32>(Int32::MaxValue);
    refptr<string> name = ref_new<string>();
  };
}

int32 ThreadPool::maxThreads = 800;
int32 ThreadPool::maxAsynchronousIOThreads = 800;
int32 ThreadPool::minThreads = int32(std::thread::hardware_concurrency());
int32 ThreadPool::minAsynchronousIOThreads = int32(std::thread::hardware_concurrency());
bool ThreadPool::closed = false;
ThreadPool::ThreadPoolItemCollection ThreadPool::threadPoolItems;
ThreadPool::ThreadPoolAsynchronousIOItemCollection ThreadPool::threadPoolAsynchronousIOItems;

Semaphore semaphore = Semaphore(0, Int32::MaxValue);
Semaphore asynchronousIOSemaphore = Semaphore(0, Int32::MaxValue);
ThreadPool::ThreadArray ThreadPool::threads;
ThreadPool::AsynchronousThreadArray ThreadPool::asynchronousIOThreads;

ThreadPool::ThreadArray::~ThreadArray() {
  closed = true;
  for (Thread& thread : *this)
    if (thread.ThreadState != ThreadState::Unstarted)
      semaphore.Release();

  for (Thread& thread : *this)
    if (thread.ThreadState != ThreadState::Unstarted)
      thread.Join();
  closed = false;
}

ThreadPool::AsynchronousThreadArray::~AsynchronousThreadArray() {
  closed = true;
  for (Thread& thread : *this)
    if (thread.ThreadState != ThreadState::Unstarted)
      asynchronousIOSemaphore.Release();

  for (Thread& thread : *this)
    if (thread.ThreadState != ThreadState::Unstarted)
      thread.Join();
  closed = false;
}

void ThreadPool::GetAvailableThreads(int32& workerThreads, int32& completionPortThreads) {
  workerThreads = maxThreads - threadPoolItems.Count;
  completionPortThreads = maxAsynchronousIOThreads - threadPoolAsynchronousIOItems.Count;
}

void ThreadPool::GetMaxThreads(int32& workerThreads, int32& completionPortThreads) {
  workerThreads = maxThreads;
  completionPortThreads = maxAsynchronousIOThreads;
}

void ThreadPool::GetMinThreads(int32& workerThreads, int32& completionPortThreads) {
  workerThreads = minThreads;
  completionPortThreads = minAsynchronousIOThreads;
}

bool ThreadPool::QueueUserWorkItem(const WaitCallback& callBack) {
  if (threads.Count == 0)
    CreateThreads();
  lock_(threadPoolItems.SyncRoot) {
    if (threadPoolItems.Count() == maxThreads)
      return false;
    threadPoolItems.Add(new ThreadPoolItem(callBack));
    semaphore.Release();
  }
  return true;
}

bool ThreadPool::QueueUserWorkItem(const WaitCallback& callBack, object& state) {
  if (threads.Count == 0)
    CreateThreads();
  lock_(threadPoolItems.SyncRoot) {
    if (threadPoolItems.Count() == maxThreads)
      return false;
    threadPoolItems.Add(new ThreadPoolItem(callBack, state));
    semaphore.Release();
  }
  return true;
}

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle& waitObject, const WaitOrTimerCallback& callBack, object& state, int32 millisecondsTimeoutInterval, bool executeOnlyOnce) {
  if (asynchronousIOThreads.Count == 0)
    CreateAsynchronousIOThreads();
  RegisteredWaitHandle result;
  lock_(threadPoolAsynchronousIOItems.SyncRoot) {
    if (threadPoolAsynchronousIOItems.Count() == maxAsynchronousIOThreads)
      return result;
    refptr<ThreadPoolAsynchronousIOItem> item = new ThreadPoolAsynchronousIOItem(callBack, state, waitObject, millisecondsTimeoutInterval, executeOnlyOnce);
    result.item = item.ToPointer();
    threadPoolAsynchronousIOItems.Add(item);
    asynchronousIOSemaphore.Release();
  }
  return result;
}

bool ThreadPool::SetMaxThreads(int32 workerThreads, int32 completionPortThreads) {
  if (workerThreads < Environment::ProcessorCount || completionPortThreads < Environment::ProcessorCount)
    return false;

  maxThreads = workerThreads;
  maxAsynchronousIOThreads = completionPortThreads;

  lock_(threadPoolItems.SyncRoot)
  semaphore = Semaphore(semaphore.Release(), maxThreads);
  lock_(threadPoolAsynchronousIOItems.SyncRoot)
  asynchronousIOSemaphore = Semaphore(asynchronousIOSemaphore.Release(), maxAsynchronousIOThreads);

  return true;
}

bool ThreadPool::SetMinThreads(int32 workerThreads, int32 completionPortThreads) {
  if (workerThreads < 0 || completionPortThreads < 0 || workerThreads >= maxThreads || completionPortThreads >= maxAsynchronousIOThreads)
    return false;

  minThreads = workerThreads;
  minAsynchronousIOThreads = completionPortThreads;

  if (threads.Count != 0)
    CreateThreads();

  if (asynchronousIOThreads.Count != 0)
    CreateAsynchronousIOThreads();

  return true;
}

void ThreadPool::CreateThreads() {
  threads = ThreadArray(minThreads);
  for (int32 i = 0; i < minThreads; i++) {
    threads[i] = Thread(ThreadStart(&ThreadPool::Run));
    threads[i].Name = "Thread Pool";
    threads[i].data->isThreadPoolThread = true;
    threads[i].IsBackground = true;
    threads[i].Start();
  }
}

void ThreadPool::CreateAsynchronousIOThreads() {
  asynchronousIOThreads = AsynchronousThreadArray(minAsynchronousIOThreads);
  for (int32 i = 0; i < minAsynchronousIOThreads; i++) {
    asynchronousIOThreads[i] = Thread(ThreadStart(&ThreadPool::AsynchronousIORun));
    asynchronousIOThreads[i].Name = "Thread Pool";
    asynchronousIOThreads[i].data->isThreadPoolThread = true;
    asynchronousIOThreads[i].IsBackground = true;
    asynchronousIOThreads[i].Start();
  }
}

void ThreadPool::Run() {
  while (!closed) {
    semaphore.WaitOne();
    if (!closed) {
      refptr<ThreadPoolItem> item;
      lock_(threadPoolItems.SyncRoot)
      item = threadPoolItems[0];
      threadPoolItems.RemoveAt(0);
      item->callback(*item->state);
    }
  }
}

void ThreadPool::AsynchronousIORun() {
  while (!closed) {
    asynchronousIOSemaphore.WaitOne();
    if (!closed) {
      refptr<ThreadPoolAsynchronousIOItem> item;
      lock_(threadPoolAsynchronousIOItems.SyncRoot)
      item = threadPoolAsynchronousIOItems[0];
      threadPoolAsynchronousIOItems.RemoveAt(0);

      do {
        bool timeout = !item->waitObject->WaitOne(item->millisecondsTimeoutInterval);
        if (!item->unregistered)
          item->callback(*item->state, timeout);
      } while (!item->executeOnlyOnce && !item->unregistered);
    }
  }
}

bool RegisteredWaitHandle::Unregister() {
  if (item == null)
    return false;

  ThreadPool::ThreadPoolAsynchronousIOItem& item = *((ThreadPool::ThreadPoolAsynchronousIOItem*)this->item);
  item.unregistered = true;
  return item.waitObject->Signal();
}

bool RegisteredWaitHandle::Unregister(WaitHandle& waitObject) {
  if (item == null)
    return false;

  ThreadPool::ThreadPoolAsynchronousIOItem& item = *((ThreadPool::ThreadPoolAsynchronousIOItem*)this->item);
  item.unregistered = true;
  return waitObject.Signal();
}

