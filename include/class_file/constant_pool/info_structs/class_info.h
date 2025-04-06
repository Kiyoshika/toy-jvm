#ifndef CLASS_INFO_H
#define CLASS_INFO_H

#include <stdint.h>

#include "class_file/constant_pool/constant_pool_tag.h"

struct ClassInfo {
  enum ConstantPoolTag tag;
  uint16_t name_index;
};

#endif //CLASS_INFO_H
