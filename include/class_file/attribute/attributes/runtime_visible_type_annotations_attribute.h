#ifndef RUNTIME_VISIBLE_TYPE_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_VISIBLE_TYPE_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>

struct RuntimeVisibleTypeAnnotationsAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t num_annotations;
  struct TypeAnnotation* annotations;
};

void
RuntimeVisibleTypeAnnotationsAttribute_free(
  struct RuntimeVisibleTypeAnnotationsAttribute* attribute);

#endif
