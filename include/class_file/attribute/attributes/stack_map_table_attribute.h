#ifndef STACK_MAP_TABLE_ATTRIBUTE_H
#define STACK_MAP_TABLE_ATTRIBUTE_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "class_file/attribute/attributes/stack_map_frame/stack_map_frame.h"
#include "status/status_code.h"

struct StackMapTableAttribute
{
  struct AttributeHeader header;
  uint16_t number_of_entries;
  struct StackMapFrame* entries;
};

void
StackMapTableAttribute_init(struct StackMapTableAttribute* attribute);

enum StatusCode
StackMapTableAttribute_parse(struct StackMapTableAttribute* attribute,
                             FILE* file);

void
StackMapTableAttribute_free(struct StackMapTableAttribute* attribute);

#endif
