#include "../../../../include/Switch/System/Diagnostics/TraceSource.hpp"

using namespace System;
using namespace System::Diagnostics;

void TraceSource::TraceData(const TraceEventType& traceEventType, int32 id, const object& data)  {
  TraceEventCache eventCache;
  for (TraceListener& listener : Listeners())
    listener.TraceData(eventCache, this->data->name, traceEventType, id, data);
}

void TraceSource::TraceData(const TraceEventType& traceEventType, int32 id, const Array<refptr<object>>& data) {
  TraceEventCache eventCache;
  for (auto& listener : Listeners())
    listener.TraceData(eventCache, this->data->name, traceEventType, id, data);
}

void TraceSource::TraceEvent(const TraceEventType& traceEventType, int32 id) {
  TraceEventCache eventCache;
  for (auto& listener : Listeners())
    listener.TraceEvent(eventCache, this->data->name, traceEventType, id);
}

void TraceSource::TraceEvent(const TraceEventType& traceEventType, int32 id, const String& message) {
  TraceEventCache eventCache;
  for (auto& listener : Listeners())
    listener.TraceEvent(eventCache, this->data->name, traceEventType, id, message);
}
