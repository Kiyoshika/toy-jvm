#ifndef FLOAT_VARIABLE_INFO_H
#define FLOAT_VARIABLE_INFO_H

#include "class_file/attribute/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct FloatVariableInfo
{
  enum VariableInfoItemType tag;
};

enum StatusCode
FloatVariableInfo_init(struct FloatVariableInfo* info);

#endif
