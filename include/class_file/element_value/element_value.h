#ifndef ELEMENT_VALUE_H
#define ELEMENT_VALUE_H

#include <stdint.h>

#include "class_file/annotation/annotation.h"
#include "class_file/element_value/element_value_tag.h"

struct ElementValue
{
  enum ElementValueTag tag;
  union value
  {
    uint16_t const_value_index;
    struct enum_const_value
    {
      uint16_t type_name_index;
      uint16_t const_name_index;
    } enum_const_value;
    uint16_t class_info_index;
    struct Annotation annotation_value;
    struct array_value
    {
      uint16_t num_values;
      struct ElementValue* values;
    } array_value;
  } value;
};

void
ElementValue_free(struct ElementValue* element_value);

#endif
