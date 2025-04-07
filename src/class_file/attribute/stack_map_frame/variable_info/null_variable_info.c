#include "class_file/attribute/stack_map_frame/variable_info/null_variable_info.h"

enum StatusCode
NullVariableInfo_init(struct NullVariableInfo* info)
{
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_NULL;
  return STATUS_OK;
}
