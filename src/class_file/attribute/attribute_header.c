#include "class_file/attribute/attribute_header.h"
#include "util/file_util.h"

enum StatusCode
AttributeHeader_parse(struct AttributeHeader* attribute_header, FILE* file)
{
  if (!attribute_header || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(
         file, &attribute_header->attribute_name_index)) != STATUS_OK)
    return status;

  if ((status = _read_u32_from_file(
         file, &attribute_header->attribute_length)) != STATUS_OK)
    return status;

  return status;
}
