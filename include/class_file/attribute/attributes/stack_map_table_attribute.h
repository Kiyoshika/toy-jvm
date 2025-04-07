#ifndef STACK_MAP_TABLE_ATTRIBUTE_H
#define STACK_MAP_TABLE_ATTRIBUTE_H

#include <stddef.h>
#include <stdint.h>

#include "class_file/attribute/stack_map_frame/stack_map_frame.h"

struct StackMapTableAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t number_of_entries;
  struct StackMapFrame* entries;
};

void
StackMapTableAttribute_init(struct StackMapTableAttribute* attribute);
void
StackMapTableAttribute_free(struct StackMapTableAttribute* attribute);

#endif
