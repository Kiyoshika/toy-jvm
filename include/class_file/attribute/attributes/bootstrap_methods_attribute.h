#ifndef BOOTSTRAP_METHODS_ATTRIBUTE_H
#define BOOTSTRAP_METHODS_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "class_file/attribute/attributes/bootstrap_methods_attribute_info.h"
#include "status/status_code.h"

struct BootstrapMethodsAttribute
{
  struct AttributeHeader header;
  uint16_t num_bootstrap_methods;
  struct BootstrapMethodsAttributeInfo* bootstrap_methods;
};

enum StatusCode
BootstrapMethodsAttribute_parse(struct BootstrapMethodsAttribute* attribute,
                                FILE* file);
void
BootstrapMethodsAttribute_free(struct BootstrapMethodsAttribute* attribute);

#endif
