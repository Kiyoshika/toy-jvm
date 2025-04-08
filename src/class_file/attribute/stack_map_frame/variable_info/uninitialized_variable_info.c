#include "class_file/attribute/attributes/stack_map_frame/variable_info/uninitialized_variable_info.h"

enum StatusCode
UninitializedVariableInfo_init(struct UninitializedVariableInfo* info,
                               uint16_t offset)
{
  if (!info)
    return STATUS_BAD_ARG;

  info->tag = VAR_INFO_ITEM_UNINITIALIZED;
  info->offset = offset;
  return STATUS_OK;
}
