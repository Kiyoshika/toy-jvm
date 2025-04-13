#ifndef LINE_NUMBER_TABLE_ATTRIBUTE_H
#define LINE_NUMBER_TABLE_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "class_file/attribute/attributes/line_number_table_attribute_info.h"
#include "status/status_code.h"

struct LineNumberTableAttribute
{
  struct AttributeHeader header;
  uint16_t line_number_table_length;
  struct LineNumberTableAttributeInfo* line_number_table;
};

enum StatusCode
LineNumberTableAttribute_parse(struct LineNumberTableAttribute* attribute,
                               FILE* file);

void
LineNumberTableAttribute_free(struct LineNumberTableAttribute* attribute);

#endif
