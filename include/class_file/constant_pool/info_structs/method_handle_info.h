#ifndef METHOD_HANDLE_INFO_H
#define METHOD_HANDLE_INFO_H

#include <stdint.h>

#include "class_file/constant_pool/constant_pool_tag.h"

struct MethodHandleInfo
{
  enum ConstantPoolTag tag;
  uint8_t reference_kind;
  uint16_t reference_index;
};

#endif // METHOD_HANDLE_INFO_H
