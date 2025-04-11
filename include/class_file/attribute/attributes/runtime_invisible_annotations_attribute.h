#ifndef RUNTIME_INVISIBLE_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_INVISIBLE_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/annotation/annotation.h"
#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct RuntimeInvisibleAnnotationsAttribute
{
  struct AttributeHeader header;
  uint16_t num_annotations;
  struct Annotation* annotations;
};

enum StatusCode
RuntimeInvisibleAnnotationsAttribute_parse(
  struct RuntimeInvisibleAnnotationsAttribute* attribute,
  FILE* file);

void
RuntimeInvisibleAnnotationsAttribute_free(
  struct RuntimeInvisibleAnnotationsAttribute* attribute);

#endif
