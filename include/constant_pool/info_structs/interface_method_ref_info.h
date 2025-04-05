#ifndef INTERFACE_METHOD_REF_INFO_H
#define INTERFACE_METHOD_REF_INFO_H

#include <stdint.h>

#include "constant_pool/constant_pool_tag.h"

struct InterfaceMethodRefInfo {
  enum ConstantPoolTag tag;
  uint16_t class_index;
  uint16_t name_and_type_index;
};

#endif //INTERFACE_METHOD_REF_INFO_H
