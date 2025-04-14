#ifndef ELEMENT_VALUE_ENUM_H
#define ELEMENT_VALUE_ENUM_H

#include <stdint.h>
#include <stdio.h>

#include "status/status_code.h"

struct ElementValueEnum
{
  uint16_t type_name_index;
  uint16_t const_name_index;
};

enum StatusCode
ElementValueEnum_parse(struct ElementValueEnum* element_value_enum, FILE* file);

#endif
