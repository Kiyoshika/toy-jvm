#ifndef INNER_CLASSES_ATTRIBUTE_H
#define INNER_CLASSES_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "class_file/attribute/attributes/inner_classes_attribute_info.h"
#include "status/status_code.h"

struct InnerClassesAttribute
{
  struct AttributeHeader header;
  uint16_t number_of_classes;
  struct InnerClassesAttributeInfo* classes;
};

enum StatusCode
InnerClassesAttribute_init(struct InnerClassesAttribute* attribute);

enum StatusCode
InnerClassesAttribute_parse(struct InnerClassesAttribute* attribute,
                            FILE* file);
void
InnerClassesAttribute_free(struct InnerClassesAttribute* attribute);

#endif
