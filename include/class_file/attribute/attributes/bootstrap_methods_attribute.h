#ifndef BOOTSTRAP_METHODS_ATTRIBUTE_H
#define BOOTSTRAP_METHODS_ATTRIBUTE_H

#include <stdint.h>

#include "class_file/attribute/attributes/bootstrap_methods_attribute_info.h"

struct BootstrapMethodsAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t num_bootstrap_methods;
  struct BootstrapMethodsAttributeInfo* bootstrap_methods;
};

void
BootstrapMethodsAttribute_free(struct BootstrapMethodsAttribute* attribute);

#endif
