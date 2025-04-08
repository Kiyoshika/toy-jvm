#ifndef LOCAL_VARIABLE_TYPE_TABLE_ATTRIBUTE_H
#define LOCAL_VARIABLE_TYPE_TABLE_ATTRIBUTE_H

#include <stdint.h>
#include <stdlib.h>

struct LocalVariableTypeTableAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  struct LocalVariableTypeTableAttributeInfo* local_variable_type_table;
};

void
LocalVariableTypeTableAttribute_free(
  struct LocalVariableTypeTableAttribute* attribute);

#endif
