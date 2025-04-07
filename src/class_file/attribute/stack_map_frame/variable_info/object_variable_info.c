#include "class_file/attribute/stack_map_frame/variable_info/object_variable_info.h"

enum StatusCode ObjectVariableInfo_init(
    struct ObjectVariableInfo* info,
    uint16_t constant_pool_index) {
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_OBJECT;
  info->constant_pool_index = constant_pool_index;
  return STATUS_OK;
}
