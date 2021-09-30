#include <cstring>

#include "../../../include/Switch/System/Buffer.hpp"

using namespace System;

int32 Buffer::BlockCompare(const void* blk1, int64 blk1Length, int64 blk1Offset, const void* blk2, int64 blk2Length, int64 blk2Offset, int64 count) {
  if (blk1 == null || blk2 == null)
    throw ArgumentNullException(caller_);
  if (blk2Offset < 0 || count < 0 || blk2Length < 0 || blk1Offset < 0 || blk1Length < 0)
    throw ArgumentOutOfRangeException(caller_);
  if (blk2Offset + count > blk2Length || blk1Offset + count > blk1Length)
    throw ArgumentException(caller_);

  return memcmp(reinterpret_cast<const char*>(blk1) + blk1Offset, reinterpret_cast<const char*>(blk2) + blk2Offset, size_t(count));
}

void Buffer::BlockCopy(const void* src, int64 srcLength, int64 srcOffset, void* dst, int64 dstLenth, int64 dstOffset, int64 count) {
  if (src == null || dst == null)
    throw ArgumentNullException(caller_);
  if (dstOffset < 0 || count < 0 || dstLenth < 0 || srcOffset < 0 || srcLength < 0)
    throw ArgumentOutOfRangeException(caller_);
  if (dstOffset + count > dstLenth || srcOffset + count > srcLength)
    throw ArgumentException(caller_);

  memmove(reinterpret_cast<char*>(dst) + dstOffset, reinterpret_cast<const char*>(src) + srcOffset, size_t(count));
}

void Buffer::BlockFill(byte filler, void* dst, int64 dstLenth, int64 dstOffset, int64 count) {
  if (dst == null)
    throw ArgumentNullException(caller_);
  if (dstOffset < 0 || count < 0 || dstLenth < 0)
    throw ArgumentOutOfRangeException(caller_);
  if (dstOffset + count > dstLenth)
    throw ArgumentException(caller_);

  memset(reinterpret_cast<char*>(dst) + dstOffset, filler, size_t(count));
}
