#ifndef INTEGER_INFO_H
#define INTEGER_INFO_H

#include <stdint.h>

#include "class_file/constant_pool/constant_pool_tag.h"

struct IntegerInfo
{
  enum ConstantPoolTag tag;
  uint32_t bytes;
};

#endif // INTEGER_INFO_H
