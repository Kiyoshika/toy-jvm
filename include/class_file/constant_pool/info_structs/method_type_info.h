#ifndef METHOD_TYPE_INFO_H
#define METHOD_TYPE_INFO_H

#include <stdint.h>

#include "class_file/constant_pool/constant_pool_tag.h"

struct MethodTypeInfo {
  enum ConstantPoolTag tag;
  uint16_t descriptor_index;
};

#endif //METHOD_TYPE_INFO_H
