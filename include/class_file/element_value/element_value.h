#ifndef ELEMENT_VALUE_H
#define ELEMENT_VALUE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/annotation/annotation.h"
#include "class_file/element_value/element_value_array.h"
#include "class_file/element_value/element_value_enum.h"
#include "class_file/element_value/element_value_tag.h"
#include "status/status_code.h"

struct ElementValue
{
  enum ElementValueTag tag;
  union value
  {
    uint16_t const_value_index;
    struct ElementValueEnum enum_const_value;
    uint16_t class_info_index;
    struct Annotation annotation_value;
    struct ElementValueArray array_value;
  } value;
};

enum StatusCode
ElementValue_parse(struct ElementValue* element_value, FILE* file);

void
ElementValue_free(struct ElementValue* element_value);

#endif
