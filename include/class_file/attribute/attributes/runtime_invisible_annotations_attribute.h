#ifndef RUNTIME_INVISIBLE_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_INVISIBLE_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>

#include "class_file/annotation/annotation.h"

struct RuntimeInvisibleAnnotationsAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t num_annotations;
  struct Annotation* annotations;
};

void
RuntimeInvisibleAnnotationsAttribute_free(
  struct RuntimeInvisibleAnnotationsAttribute* attribute);

#endif
