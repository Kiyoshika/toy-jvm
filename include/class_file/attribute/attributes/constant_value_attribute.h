#ifndef CONSTANT_VALUE_ATTRIBUTE_H
#define CONSTANT_VALUE_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct ConstantValueAttribute
{
  struct AttributeHeader header;
  uint16_t constantvalue_index;
};

enum StatusCode
ConstantValueAttribute_parse(struct ConstantValueAttribute* attribute,
                             FILE* file);

#endif
