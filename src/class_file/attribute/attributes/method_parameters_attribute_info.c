#include "class_file/attribute/attributes/method_parameters_attribute_info.h"
#include "util/file_util.h"

enum StatusCode
MethodParametersAttributeInfo_parse(
  struct MethodParametersAttributeInfo* attribute,
  FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &attribute->name_index)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->access_flags)) !=
      STATUS_OK)
    return status;

  return status;
}
