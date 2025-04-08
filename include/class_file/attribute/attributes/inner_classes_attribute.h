#ifndef INNER_CLASSES_ATTRIBUTE_H
#define INNER_CLASSES_ATTRIBUTE_H

#include <stdint.h>
#include <stdlib.h>

#include "class_file/attribute/attributes/inner_classes_attribute_info.h"

struct InnerClassesAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t number_of_classes;
  struct InnerClassesAttributeInfo* classes;
};

void
InnerClassesAttribute_free(struct InnerClassesAttribute* attribute);

#endif
