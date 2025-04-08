#ifndef OBJECT_VARIABLE_INFO_H
#define OBJECT_VARIALE_INFO_H

#include <stdint.h>

#include "class_file/attribute/attributes/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct ObjectVariableInfo
{
  enum VariableInfoItemType tag;
  uint16_t constant_pool_index;
};

enum StatusCode
ObjectVariableInfo_init(struct ObjectVariableInfo* info,
                        uint16_t constant_pool_index);

#endif
