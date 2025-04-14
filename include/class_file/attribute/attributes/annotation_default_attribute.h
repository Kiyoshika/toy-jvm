#ifndef ANNOTATION_DEFAULT_ATTRIBUTE_H
#define ANNOTATION_DEFAULT_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "class_file/element_value/element_value.h"
#include "status/status_code.h"

struct AnnotationDefaultAttribute
{
  struct AttributeHeader header;
  struct ElementValue default_value;
};

enum StatusCode
AnnotationDefaultAttribute_parse(struct AnnotationDefaultAttribute* attribute,
                                 FILE* file);

void
AnnotationDefaultAttribute_free(struct AnnotationDefaultAttribute* attribute);

#endif
