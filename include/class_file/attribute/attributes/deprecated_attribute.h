#ifndef DEPRECATED_ATTRIBUTE_H
#define DEPRECATED_ATTRIBUTE_H

#include <stdint.h>

struct DeprecatedAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
};

#endif
