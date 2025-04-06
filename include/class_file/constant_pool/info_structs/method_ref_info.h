#ifndef METHOD_REF_INFO_H
#define METHOD_REF_INFO_H

#include <stdint.h>

#include "class_file/constant_pool/constant_pool_tag.h"

struct MethodRefInfo {
  enum ConstantPoolTag tag;
  uint16_t class_index;
  uint16_t name_and_type_index;
};

#endif //METHOD_REF_INFO_H
