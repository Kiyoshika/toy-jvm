#include "class_file/attribute/stack_map_frame/variable_info/uninitialized_this_variable_info.h"

enum StatusCode UninitializedThisVariableInfo_init(struct UninitializedThisVariableInfo* info) {
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_UNINITIALIZED_THIS;
  return STATUS_OK;
}
