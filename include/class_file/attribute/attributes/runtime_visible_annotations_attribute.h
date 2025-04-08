#ifndef RUNTIME_VISIBLE_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_VISIBLE_ANNOTATIONS_ATTRIBUTE_H

#include "class_file/annotation/annotation.h"
#include <stdint.h>

struct RuntimeVisibleAnnotationsAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t num_annotations;
  struct Annotation* annotations;
};

void
RuntimeVisibleAnnotationsAttribute_free(
  struct RuntimeVisibleAnnotationsAttribute* attribute);

#endif
