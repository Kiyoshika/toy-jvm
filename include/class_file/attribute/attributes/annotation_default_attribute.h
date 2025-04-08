#ifndef ANNOTATION_DEFAULT_ATTRIBUTE_H
#define ANNOTATION_DEFAULT_ATTRIBUTE_H

#include <stdint.h>

#include "class_file/element_value/element_value.h"

struct AnnotationDefaultAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  struct ElementValue default_value;
};

void
AnnotationDefaultAttribute_free(struct AnnotationDefaultAttribute* attribute);

#endif
