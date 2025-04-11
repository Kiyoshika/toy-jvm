#include "class_file/attribute/attributes/constant_value_attribute.h"

enum StatusCode
ConstantValueAttribute_parse(struct ConstantValueAttribute* attribute,
                             FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  // TODO: implement this
}
