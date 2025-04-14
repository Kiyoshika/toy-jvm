#include "class_file/attribute/attributes/inner_classes_attribute_info.h"
#include "util/file_util.h"

enum StatusCode
InnerClassesAttributeInfo_parse(struct InnerClassesAttributeInfo* attribute,
                                FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(
         file, &attribute->inner_class_info_index)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(
         file, &attribute->outer_class_info_index)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->inner_name_index)) !=
      STATUS_OK)
    return status;

  uint16_t access_flags = 0u;
  if ((status = _read_u16_from_file(file, &access_flags)) != STATUS_OK)
    return status;

  attribute->inner_class_access_flags = access_flags;

  return status;
}
