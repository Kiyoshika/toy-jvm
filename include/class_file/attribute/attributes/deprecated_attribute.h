#ifndef DEPRECATED_ATTRIBUTE_H
#define DEPRECATED_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct DeprecatedAttribute
{
  struct AttributeHeader header;
};

enum StatusCode
DeprecatedAttribute_parse(struct DeprecatedAttribute* attribute, FILE* file);

#endif
