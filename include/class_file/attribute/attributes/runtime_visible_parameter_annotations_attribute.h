#ifndef RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdlib.h>

struct RuntimeVisibleParameterAnnotationsAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint8_t num_parameters;
  struct RuntimeVisibleParameterAnnotationsAttributeInfo* parameter_annotations;
};

void
RuntimeVisibleParameterAnnotationsAttribute_free(
  struct RuntimeVisibleParameterAnnotationsAttribute* attribute);

#endif
