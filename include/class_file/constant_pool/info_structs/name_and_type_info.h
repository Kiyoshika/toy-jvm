#ifndef NAME_AND_TYPE_INFO_H
#define NAME_AND_TYPE_INFO_H

#include <stdint.h>

#include "class_file/constant_pool/constant_pool_tag.h"

struct NameAndTypeInfo
{
  enum ConstantPoolTag tag;
  uint16_t name_index;
  uint16_t descriptor_index;
};

#endif // NAME_AND_TYPE_INFO_H
