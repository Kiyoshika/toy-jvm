#ifndef METHOD_PARAMETERS_ATTRIBUTE_INFO_H
#define METHOD_PARAMETERS_ATTRIBUTE_INFO_H

#include <stdint.h>
#include <stdio.h>

struct MethodParametersAttributeInfo
{
  uint16_t name_index;
  uint16_t access_flags; // references MethodParametersAttributeAccessFlag
};

enum StatusCode
MethodParametersAttributeInfo_parse(
  struct MethodParametersAttributeInfo* attribute,
  FILE* file);

#endif
