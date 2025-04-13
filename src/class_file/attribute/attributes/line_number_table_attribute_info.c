#include "class_file/attribute/attributes/line_number_table_attribute_info.h"
#include "util/file_util.h"

enum StatusCode
LineNumberTableAttributeInfo_parse(
  struct LineNumberTableAttributeInfo* attribute,
  FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &attribute->start_pc)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->line_number)) !=
      STATUS_OK)
    return status;

  return status;
}
