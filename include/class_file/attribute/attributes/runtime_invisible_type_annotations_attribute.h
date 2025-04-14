#ifndef RUNTIME_INVISIBLE_TYPE_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_INVISIBLE_TYPE_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/annotation/type_annotation/type_annotation.h"
#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct RuntimeInvisibleTypeAnnotationsAttribute
{
  struct AttributeHeader header;
  uint16_t num_annotations;
  struct TypeAnnotation* annotations;
};

enum StatusCode
RuntimeInvisibleTypeAnnotationsAttribute_parse(
  struct RuntimeInvisibleTypeAnnotationsAttribute* attribute,
  FILE* file);

void
RuntimeInvisibleTypeAnnotationsAttribute_free(
  struct RuntimeInvisibleTypeAnnotationsAttribute* attribute);

#endif
