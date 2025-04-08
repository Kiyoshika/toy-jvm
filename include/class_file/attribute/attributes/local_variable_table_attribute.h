#ifndef LOCAL_VARIABLE_TABLE_ATTRIBUTE_H
#define LOCAL_VARIABLE_TABLE_ATTRIBUTE_H

#include <stdint.h>
#include <stdlib.h>

#include "class_file/attribute/attributes/local_variable_table_attribute_info.h"

struct LocalVariableTableAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t local_variable_table_length;
  struct LocalVariableTableAttributeInfo* local_variable_table;
};

void
LocalVariableTableAttribute_free(struct LocalVariableTableAttribute* attribute);

#endif
