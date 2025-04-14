#ifndef RUNTIME_VISIBLE_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_VISIBLE_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/annotation/annotation.h"
#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct RuntimeVisibleAnnotationsAttribute
{
  struct AttributeHeader header;
  uint16_t num_annotations;
  struct Annotation* annotations;
};

enum StatusCode
RuntimeVisibleAnnotationsAttribute_parse(
  struct RuntimeVisibleAnnotationsAttribute* attribute,
  FILE* file);

void
RuntimeVisibleAnnotationsAttribute_free(
  struct RuntimeVisibleAnnotationsAttribute* attribute);

#endif
