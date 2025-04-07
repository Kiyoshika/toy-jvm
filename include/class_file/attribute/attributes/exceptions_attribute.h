#ifndef EXCEPTIONS_ATTRIBUTE_H
#define EXCEPTIONS_ATTRIBUTE_H

#include <stdint.h>
#include <stdlib.h>

struct ExceptionsAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t number_of_exceptions;
  uint16_t* exception_index_table;
};

void
ExceptionsAttribute_init(struct ExceptionsAttribute* attribute);
void
ExceptionsAttribute_free(struct ExceptionsAttribute* attribute);

#endif
