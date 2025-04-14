#include "class_file/attribute/attributes/deprecated_attribute.h"

enum StatusCode
DeprecatedAttribute_parse(struct DeprecatedAttribute* attribute, FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  return status;
}
