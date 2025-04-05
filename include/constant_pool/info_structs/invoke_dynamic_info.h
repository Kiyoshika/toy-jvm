#ifndef INVOKE_DYNAMIC_INFO_H
#define INVOKE_DYNAMIC_INFO_H

#include <stdint.h>

#include "constant_pool/constant_pool_tag.h"

struct InvokeDynamicInfo {
  enum ConstantPoolTag tag;
  uint16_t bootstrap_method_attr_index;
  uint16_t name_and_type_index;
};

#endif //INVOKE_DYNAMIC_INFO_H
