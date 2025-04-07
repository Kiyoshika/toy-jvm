#include "class_file/attribute/stack_map_frame/variable_info/long_variable_info.h"

enum StatusCode LongVariableInfo_init(struct LongVariableInfo* info) {
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_LONG;
  return STATUS_OK;
}
