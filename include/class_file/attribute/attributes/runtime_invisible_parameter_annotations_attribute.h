#ifndef RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>

struct RuntimeInvisibleParameterAnnotationsAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint8_t num_parameters;
  struct RuntimeInvisibleParameterAnnotationsAttributeInfo*
    parameter_annotations;
};

void
RuntimeInvisibleParameterAnnotationsAttribute_free(
  struct RuntimeInvisibleParameterAnnotationsAttribute* attribute);

#endif
