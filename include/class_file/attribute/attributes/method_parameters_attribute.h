#ifndef METHOD_PARAMETERS_ATTRIBUTE_H
#define METHOD_PARAMETERS_ATTRIBUTE_H

#include <stdint.h>

struct MethodParametersAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint8_t parameters_count;
  struct MethodParametersAttributeInfo* parameters;
};

void
MethodParametersAttribute_free(struct MethodParametersAttribute* attribute);

#endif
