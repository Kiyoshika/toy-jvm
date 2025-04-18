#ifndef BOOTSTRAP_METHODS_ATTRIBUTE_INFO_H
#define BOOTSTRAP_METHODS_ATTRIBUTE_INFO_H

#include <stdint.h>

struct BootstrapMethodsAttributeInfo
{
  uint16_t bootstrap_method_ref;
  uint16_t num_bootstrap_arguments;
  uint16_t* bootstrap_arguments;
};

void
BootstrapMethodsAttributeInfo_free(struct BootstrapMethodsAttributeInfo* info);

#endif
