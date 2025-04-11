#ifndef LOCAL_VARIABLE_TABLE_ATTRIBUTE_H
#define LOCAL_VARIABLE_TABLE_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "class_file/attribute/attributes/local_variable_table_attribute_info.h"
#include "status/status_code.h"

struct LocalVariableTableAttribute
{
  struct AttributeHeader header;
  uint16_t local_variable_table_length;
  struct LocalVariableTableAttributeInfo* local_variable_table;
};

enum StatusCode
LocalVariableTableAttribute_parse(struct LocalVariableTableAttribute* attribute,
                                  FILE* file);

void
LocalVariableTableAttribute_free(struct LocalVariableTableAttribute* attribute);

#endif
