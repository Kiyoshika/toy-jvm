#ifndef FLOAT_INFO_H
#define FLOAT_INFO_H

#include <stdint.h>

#include "constant_pool/constant_pool_tag.h"

struct FloatInfo {
  enum ConstantPoolTag tag;
  uint32_t bytes;
};

#endif //FLOAT_INFO_H
