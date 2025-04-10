#ifndef FIELD_H
#define FIELD_H

#include <stdint.h>
#include <stdlib.h>

#include "class_file/class_file.h"
#include "status/status_code.h"

// forward declaration
struct AttributeInfo;

struct Field
{
  uint16_t access_flags; // maps to field_access_flags.h
  uint16_t name_index;
  uint16_t descriptor_index;
  uint16_t attributes_count;
  struct AttributeInfo* attributes;
};

enum StatusCode
field_init(struct Field* field);

enum StatusCode
field_parse(struct Field* field, FILE* file, struct ClassFile* class_file);

enum StatusCode
field_parse_attributes(struct Field* field,
                       FILE* file,
                       struct ClassFile* class_file);

void
field_free(struct Field* field);

#endif // FIELD_H
