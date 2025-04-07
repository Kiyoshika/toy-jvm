#ifndef LONG_VARIABLE_INFO_H
#define LONG_VARIABLE_INFO_H

#include "class_file/attribute/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct LongVariableInfo
{
  enum VariableInfoItemType tag;
};

enum StatusCode
LongVariableInfo_init(struct LongVariableInfo* info);

#endif
