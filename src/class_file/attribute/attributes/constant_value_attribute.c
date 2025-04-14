#include "class_file/attribute/attributes/constant_value_attribute.h"
#include "class_file/attribute/attribute_header.h"
#include "util/file_util.h"

enum StatusCode
ConstantValueAttribute_parse(struct ConstantValueAttribute* attribute,
                             FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->constantvalue_index)) !=
      STATUS_OK)
    return status;

  return status;
}
