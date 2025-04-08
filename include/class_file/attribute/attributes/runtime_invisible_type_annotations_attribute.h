#ifndef RUNTIME_INVISIBLE_TYPE_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_INVISIBLE_TYPE_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>

#include "class_info/annotation/type_annotation/type_annotation.h"

struct RuntimeInvisibleTypeAnnotationsAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t num_annotations;
  struct TypeAnnotation* annotations;
};

void
RuntimeInvisibleTypeAnnotationsAttribute_free(
  struct RuntimeInvisibleTypeAnnotationsAttribute* attribute);

#endif
