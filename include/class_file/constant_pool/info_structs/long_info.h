#ifndef LONG_INFO_H
#define LONG_INFO_H

#include <stdint.h>

#include "class_file/constant_pool/constant_pool_tag.h"

struct LongInfo {
  enum ConstantPoolTag tag;
  uint32_t high_bytes;
  uint32_t low_bytes;
};

#endif //LONG_INFO_H
