#ifndef ELEMENT_VALUE_ARRAY_H
#define ELEMENT_VALUE_ARRAY_H

#include <stdint.h>
#include <stdio.h>

#include "status/status_code.h"

// forward declaration
struct ElementValue;

struct ElementValueArray
{
  uint16_t num_values;
  struct ElementValue* values;
};

enum StatusCode
ElementValueArray_parse(struct ElementValueArray* array, FILE* file);

void
ElementValueArray_free(struct ElementValueArray* array);

#endif
