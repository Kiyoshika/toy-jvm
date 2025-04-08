#ifndef RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_INFO_H
#define RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_INFO_H

#include <stdint.h>

#include "class_file/annotation.h"

struct RuntimeInvisibleParameterAnnotationsAttributeInfo
{
  uint16_t num_annotations;
  struct Annotation* annotations;
};

void
RuntimeInvisibleParameterAnnotationsAttributeInfo_free(
  struct RuntimeInvisibleParameterAnnotationsAttributeInfo* attribute);

#endif
