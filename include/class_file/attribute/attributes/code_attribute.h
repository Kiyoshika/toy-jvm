#ifndef CODE_ATTRIBUTE_H
#define CODE_ATTRIBUTE_H

#include <stdint.h>
#include <stdlib.h>

struct CodeAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t max_stack;
  uint16_t max_locals;
  uint32_t code_length;
  uint8_t* code;
  uint16_t exception_table_length;
  struct ExceptionTable* exceptions;
  uint16_t attributes_count;
  struct AttributeInfo* attributes;
};

void
CodeAttribute_free(struct CodeAttribute* attribute);

#endif
