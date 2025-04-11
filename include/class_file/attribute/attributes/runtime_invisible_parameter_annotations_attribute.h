#ifndef RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct RuntimeInvisibleParameterAnnotationsAttribute
{
  struct AttributeHeader header;
  uint8_t num_parameters;
  struct RuntimeInvisibleParameterAnnotationsAttributeInfo*
    parameter_annotations;
};

enum StatusCode
RuntimeInvisibleParameterAnnotationsAttribute_parse(
  struct RuntimeInvisibleParameterAnnotationsAttribute* attribute,
  FILE* file);

void
RuntimeInvisibleParameterAnnotationsAttribute_free(
  struct RuntimeInvisibleParameterAnnotationsAttribute* attribute);

#endif
