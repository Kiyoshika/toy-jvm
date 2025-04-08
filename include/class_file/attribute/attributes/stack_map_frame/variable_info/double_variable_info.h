#ifndef DOUBLE_VARIABLE_INFO_H
#define DOUBLE_VARIABLE_INFO_H

#include "class_file/attribute/attributes/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct DoubleVariableInfo
{
  enum VariableInfoItemType tag;
};

enum StatusCode
DoubleVariableInfo_init(struct DoubleVariableInfo* info);

#endif
