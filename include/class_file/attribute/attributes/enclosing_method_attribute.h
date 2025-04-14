#ifndef ENCLOSING_METHOD_ATTRIBUTE_H
#define ENCLOSING_METHOD_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct EnclosingMethodAttribute
{
  struct AttributeHeader header;
  uint16_t class_index;
  uint16_t method_index;
};

enum StatusCode
EnclosingMethodAttribute_parse(struct EnclosingMethodAttribute* attribute,
                               FILE* file);

#endif
