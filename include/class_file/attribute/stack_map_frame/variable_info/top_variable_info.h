#ifndef TOP_VARIABLE_INFO_H
#define TOP_VARIABLE_INFO_H

#include "class_file/attribute/stack_map_frame/variable_info/variable_info_item_type.h"
#include "status/status_code.h"

struct TopVariableInfo
{
  enum VariableInfoItemType tag;
};

enum StatusCode
TopVariableInfo_init(struct TopVariableInfo* info);

#endif
