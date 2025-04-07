#include "class_file/attribute/stack_map_frame/variable_info/integer_variable_info.h"

enum StatusCode
IntegerVariableInfo_init(struct IntegerVariableInfo* info)
{
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_INTEGER;
  return STATUS_OK;
}
