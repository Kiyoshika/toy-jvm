#ifndef METHOD_PARAMETERS_ATTRIBUTE_INFO_H
#define METHOD_PARAMETERS_ATTRIBUTE_INFO_H

#include <stdint.h>

struct MethodParametersAttributeInfo
{
  uint16_t name_index;
  uint16_t access_flags; // references MethodParametersAttributeAccessFlag
};

#endif
