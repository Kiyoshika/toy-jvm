#ifndef CODE_ATTRIBUTE_H
#define CODE_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "class_file/constant_pool/constant_pool.h"
#include "status/status_code.h"

struct CodeAttribute
{
  struct AttributeHeader header;
  uint16_t max_stack;
  uint16_t max_locals;
  uint32_t code_length;
  uint8_t* code;
  uint16_t exception_table_length;
  struct ExceptionTable* exceptions;
  uint16_t attributes_count;
  struct AttributeInfo* attributes;
};

enum StatusCode
CodeAttribute_parse(struct CodeAttribute* attribute,
                    FILE* file,
                    const struct ConstantPool* constant_pool);

void
CodeAttribute_free(struct CodeAttribute* attribute);

#endif
