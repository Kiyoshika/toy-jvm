#ifndef SIGNATURE_ATTRIBUTE_H
#define SIGNATURE_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct SignatureAttribute
{
  struct AttributeHeader header;
  uint16_t signature_index;
};

enum StatusCode
SignatureAttribute_parse(struct SignatureAttribute* attribute, FILE* file);

#endif
