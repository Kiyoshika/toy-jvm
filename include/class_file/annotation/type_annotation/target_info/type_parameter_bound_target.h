#ifndef TYPE_PARAMETER_BOUND_TARGET_H
#define TYPE_PARAMETER_BOUND_TARGET_H

#include <stdint.h>

struct TypeParameterBoundTarget
{
  uint8_t type_parameter_index;
  uint8_t bound_index;
};

#endif
