#ifndef STRING_INFO_H
#define STRING_INFO_H

#include <stdint.h>

#include "class_file/constant_pool/constant_pool_tag.h"

struct StringInfo
{
  enum ConstantPoolTag tag;
  uint16_t class_index;
};
#endif // STRING_INFO_H
