#ifndef VERIFICATION_TYPE_INFO_H
#define VERIFICATION_TYPE_INFO_H

#include "class_file/attribute/stack_map_frame/variable_info/double_variable_info.h"
#include "class_file/attribute/stack_map_frame/variable_info/float_variable_info.h"
#include "class_file/attribute/stack_map_frame/variable_info/integer_variable_info.h"
#include "class_file/attribute/stack_map_frame/variable_info/long_variable_info.h"
#include "class_file/attribute/stack_map_frame/variable_info/null_variable_info.h"
#include "class_file/attribute/stack_map_frame/variable_info/object_variable_info.h"
#include "class_file/attribute/stack_map_frame/variable_info/top_variable_info.h"
#include "class_file/attribute/stack_map_frame/variable_info/uninitialized_this_variable_info.h"
#include "class_file/attribute/stack_map_frame/variable_info/uninitialized_variable_info.h"

union VerificationTypeInfo
{
  struct TopVariableInfo top_variable;
  struct IntegerVariableInfo integer_variable;
  struct FloatVariableInfo float_variable;
  struct LongVariableInfo long_variable;
  struct DoubleVariableInfo double_variable;
  struct NullVariableInfo null_variable;
  struct UninitializedThisVariableInfo uninitialized_this_variable;
  struct ObjectVariableInfo object_variable;
  struct UninitializedVariableInfo uninitialized_variable;
} VerificationTypeInfo;

#endif
