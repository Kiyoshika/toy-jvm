#ifndef FIELD_H
#define FIELD_H

#include <stdint.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_info.h"

struct Field
{
  uint16_t access_flags;
  uint16_t name_index;
  uint16_t descriptor_index;
  uint16_t attributes_count;
  struct AttributeInfo* attributes;
};

void
field_free(struct Field* field);

#endif // FIELD_H
