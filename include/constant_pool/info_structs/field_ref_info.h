#ifndef FIELD_REF_H
#define FIELD_REF_H

#include <stdint.h>

#include "constant_pool/constant_pool_tag.h"

struct FieldRefInfo {
  enum ConstantPoolTag tag;
  uint16_t class_index;
  uint16_t name_and_type_index;
};

#endif //FIELD_REF_H
