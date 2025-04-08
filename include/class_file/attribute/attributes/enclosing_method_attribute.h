#ifndef ENCLOSING_METHOD_ATTRIBUTE_H
#define ENCLOSING_METHOD_ATTRIBUTE_H

#include <stdint.h>

struct EnclosingMethodAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t class_index;
  uint16_t method_index;
};

#endif
