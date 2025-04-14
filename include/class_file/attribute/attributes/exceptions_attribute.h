#ifndef EXCEPTIONS_ATTRIBUTE_H
#define EXCEPTIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct ExceptionsAttribute
{
  struct AttributeHeader header;
  uint16_t number_of_exceptions;
  uint16_t* exception_index_table;
};

void
ExceptionsAttribute_init(struct ExceptionsAttribute* attribute);

enum StatusCode
ExceptionsAttribute_parse(struct ExceptionsAttribute* attribute, FILE* file);

void
ExceptionsAttribute_free(struct ExceptionsAttribute* attribute);

#endif
