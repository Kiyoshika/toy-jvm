#ifndef NULL_VARIABLE_INFO_H
#define NULL_VARIABLE_INFO_H

#include "class_file/attribute/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct NullVariableInfo
{
  enum VariableInfoItemType tag;
};

enum StatusCode
NullVariableInfo_init(struct NullVariableInfo* info);

#endif
