#ifndef ATTRIBUTE_INFO_H
#define ATTRIBUTE_INFO_H

#include <stdint.h>

#include "class_file/attribute/attribute_type.h"
#include "class_file/attribute/attributes/code_attribute.h"
#include "class_file/attribute/attributes/constant_value_attribute.h"
#include "class_file/attribute/attributes/exceptions_attribute.h"
#include "class_file/attribute/attributes/stack_map_table_attribute.h"

struct AttributeInfo
{
  enum AttributeType type;
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  // TODO: add remaining attribute structs defined in:
  // https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.7
  union attribute
  {
    struct ConstantValueAttribute constant_value;
    struct CodeAttribute code;
    struct ExceptionsAttribute exceptions;
    struct StackMapTableAttribute stack_map_table;
  } attribute;
};

void
attribute_info_free(struct AttributeInfo* attribute_info);

#endif // ATTRIBUTE_INFO_H
