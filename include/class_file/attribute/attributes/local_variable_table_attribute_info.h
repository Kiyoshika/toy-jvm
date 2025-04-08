#ifndef LOCAL_VARIABLE_TABLE_ATTRIBUTE_INFO_H
#define LOCAL_VARIABLE_TABLE_ATTRIBUTE_INFO_H

#include <stdint.h>

struct LocalVariableTableAttributeInfo
{
  uint16_t start_pc;
  uint16_t length;
  uint16_t name_index;
  uint16_t descriptor_index;
  uint16_t index;
};

#endif
