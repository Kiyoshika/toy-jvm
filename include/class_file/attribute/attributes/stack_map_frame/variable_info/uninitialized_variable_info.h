#ifndef UNINITIALIZED_VARIABLE_INFO_H
#define UNINITIALIZED_VARIABLE_INFO_H

#include <stdint.h>

#include "class_file/attribute/attributes/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct UninitializedVariableInfo
{
  enum VariableInfoItemType tag;
  uint16_t offset;
};

enum StatusCode
UninitializedVariableInfo_init(struct UninitializedVariableInfo* info,
                               uint16_t offset);

#endif
