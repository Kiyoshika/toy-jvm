#ifndef UNINITIALIZED_THIS_VARIABLE_INFO_H
#define UNINITIALIZED_THIS_VARIABLE_INFO_H

#include "class_file/attribute/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct UninitializedThisVariableInfo
{
  enum VariableInfoItemType tag;
};

enum StatusCode
UninitializedThisVariableInfo_init(struct UninitializedThisVariableInfo* info);

#endif
