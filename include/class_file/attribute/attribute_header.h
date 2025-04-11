#ifndef ATTRIBUTE_HEADER_H
#define ATTRIBUTE_HEADER_H

#include <stdint.h>
#include <stdio.h>

#include "status/status_code.h"

struct AttributeHeader
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
};

enum StatusCode
AttributeHeader_parse(struct AttributeHeader* attribute_header, FILE* file);

#endif
