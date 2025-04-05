#ifndef DOUBLE_INFO_H
#define DOUBLE_INFO_H

#include <stdint.h>

#include "constant_pool/constant_pool_tag.h"

struct DoubleInfo {
  enum ConstantPoolTag tag;
  uint32_t high_bytes;
  uint32_t low_bytes;
};

#endif //DOUBLE_INFO_H
