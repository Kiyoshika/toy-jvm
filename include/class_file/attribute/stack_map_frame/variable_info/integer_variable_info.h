#ifndef INTEGER_VARIABLE_INFO_H
#define INTEGER_VARIABLE_INFO_H

#include "class_file/attribute/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct IntegerVariableInfo
{
  enum VariableInfoItemType tag;
};

enum StatusCode
IntegerVariableInfo_init(struct IntegerVariableInfo* info);

#endif
