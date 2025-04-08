#ifndef LINE_NUMBER_TABLE_ATTRIBUTE_H
#define LINE_NUMBER_TABLE_ATTRIBUTE_H

#include <stdint.h>
#include <stdlib.h>

#include "class_file/attribute/attributes/line_number_table_attribute_info.h"

struct LineNumberTableAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t line_number_table_length;
  struct LineNumberTableAttributeInfo line_number_table;
};

void
LineNumberTableAttribute_free(struct LineNumberTableAttribute* attribute);

#endif
