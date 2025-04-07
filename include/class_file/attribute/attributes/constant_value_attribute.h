#ifndef CONSTANT_VALUE_ATTRIBUTE_H
#define CONSTANT_VALUE_ATTRIBUTE_H

#include <stdint.h>

struct ConstantValueAttribute {
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t constantvalue_index;
};

#endif
