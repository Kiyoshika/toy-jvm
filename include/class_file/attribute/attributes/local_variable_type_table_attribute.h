#ifndef LOCAL_VARIABLE_TYPE_TABLE_ATTRIBUTE_H
#define LOCAL_VARIABLE_TYPE_TABLE_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct LocalVariableTypeTableAttribute
{
  struct AttributeHeader header;
  uint16_t local_variable_type_table_length;
  struct LocalVariableTypeTableAttributeInfo* local_variable_type_table;
};

enum StatusCode
LocalVariableTypeTableAttribute_parse(
  struct LocalVariableTypeTableAttribute* attribute,
  FILE* file);

void
LocalVariableTypeTableAttribute_free(
  struct LocalVariableTypeTableAttribute* attribute);

#endif
