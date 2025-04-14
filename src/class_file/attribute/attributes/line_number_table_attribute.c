#include "class_file/attribute/attributes/line_number_table_attribute.h"
#include "class_file/attribute/attributes/line_number_table_attribute_info.h"
#include "util/file_util.h"

enum StatusCode
LineNumberTableAttribute_parse(struct LineNumberTableAttribute* attribute,
                               FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(
         file, &attribute->line_number_table_length)) != STATUS_OK)
    return status;

  if (attribute->line_number_table_length > 0) {
    attribute->line_number_table =
      calloc(attribute->line_number_table_length,
             sizeof(struct LineNumberTableAttributeInfo));
    if (!attribute->line_number_table)
      return STATUS_NO_MEM;

    for (uint16_t i = 0; i < attribute->line_number_table_length; ++i)
      if ((status = LineNumberTableAttributeInfo_parse(
             &attribute->line_number_table[i], file)) != STATUS_OK)
        return status;
  } else
    attribute->line_number_table = NULL;

  return status;
}

void
LineNumberTableAttribute_free(struct LineNumberTableAttribute* attribute)
{
  if (!attribute)
    return;

  free(attribute->line_number_table);
  attribute->line_number_table = NULL;
}
