#ifndef RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_H
#define RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct RuntimeVisibleParameterAnnotationsAttribute
{
  struct AttributeHeader header;
  uint8_t num_parameters;
  struct RuntimeVisibleParameterAnnotationsAttributeInfo* parameter_annotations;
};

enum StatusCode
RuntimeVisibleParameterAnnotationsAttribute_parse(
  struct RuntimeVisibleParameterAnnotationsAttribute* attribute,
  FILE* file);

void
RuntimeVisibleParameterAnnotationsAttribute_free(
  struct RuntimeVisibleParameterAnnotationsAttribute* attribute);

#endif
