#ifndef RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS_INFO_H
#define RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS_INFO_H

#include <stdint.h>

#include "class_file/annotation.h"

struct RuntimeVisibleParameterAnnotationsInfo
{
  uint16_t num_annotations;
  struct Annotation* annotations;
};

void
RuntimeVisibleParameterAnnotationsInfo_free(
  struct RuntimeVisibleParameterAnnotationsInfo* attribute);

#endif
