#include "class_file/attribute/stack_map_frame/variable_info/float_variable_info.h"

enum StatusCode FloatVariableInfo_init(struct FloatVariableInfo* info) {
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_FLOAT;
  return STATUS_OK;
}
