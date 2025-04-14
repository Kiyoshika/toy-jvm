#ifndef METHOD_PARAMETERS_ATTRIBUTE_H
#define METHOD_PARAMETERS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct MethodParametersAttribute
{
  struct AttributeHeader header;
  uint8_t parameters_count;
  struct MethodParametersAttributeInfo* parameters;
};

enum StatusCode
MethodParametersAttribute_parse(struct MethodParametersAttribute* attribute,
                                FILE* file);

void
MethodParametersAttribute_free(struct MethodParametersAttribute* attribute);

#endif
