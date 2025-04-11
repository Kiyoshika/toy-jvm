#ifndef RUNTIME_VISIBLE_TYPE_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_VISIBLE_TYPE_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct RuntimeVisibleTypeAnnotationsAttribute
{
  struct AttributeHeader header;
  uint16_t num_annotations;
  struct TypeAnnotation* annotations;
};

enum StatusCode
RuntimeVisibleTypeAnnotationsAttribute_parse(
  struct RuntimeVisibleTypeAnnotationsAttribute* attribute,
  FILE* file);

void
RuntimeVisibleTypeAnnotationsAttribute_free(
  struct RuntimeVisibleTypeAnnotationsAttribute* attribute);

#endif
