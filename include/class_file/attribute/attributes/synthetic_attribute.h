#ifndef SYNTHETIC_ATTRIBUTE_H
#define SYNTHETIC_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct SyntheticAttribute
{
  struct AttributeHeader header;
};

enum StatusCode
SyntheticAttribute_parse(struct SyntheticAttribute* attribute, FILE* file);

#endif
