#include "class_file/attribute/stack_map_frame/variable_info/double_variable_info.h"

enum StatusCode DoubleVariableInfo_init(struct DoubleVariableInfo* info) {
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_DOUBLE;
  return STATUS_OK;
}
