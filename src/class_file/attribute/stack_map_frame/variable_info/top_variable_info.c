#include "class_file/attribute/attributes/stack_map_frame/variable_info/top_variable_info.h"

enum StatusCode
TopVariableInfo_init(struct TopVariableInfo* info)
{
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_TOP;
  return STATUS_OK;
}
