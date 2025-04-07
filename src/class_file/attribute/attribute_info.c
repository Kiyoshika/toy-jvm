#include "class_file/attribute/attribute_info.h"

void
attribute_info_free(struct AttributeInfo* attribute_info)
{
  if (!attribute_info)
    return;

  // for any attribute types with dynamic memory, free them up
  switch (attribute_info->type) {
    case ATTRIBUTE_TYPE_CODE:
      CodeAttribute_free(&attribute_info->attribute.code);
      break;
    case ATTRIBUTE_TYPE_EXCEPTIONS:
      ExceptionsAttribute_free(&attribute_info->attribute.exceptions);
      break;
    case ATTRIBUTE_TYPE_STACK_MAP_TABLE:
      StackMapTableAttribute_free(&attribute_info->attribute.stack_map_table);
      break;
    // any other attribute types that don't dynamically allocate, it's a no-op
    default:
      break;
  }
}
