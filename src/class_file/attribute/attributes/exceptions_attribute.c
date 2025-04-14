#include "class_file/attribute/attributes/exceptions_attribute.h"
#include "util/file_util.h"

enum StatusCode
ExceptionsAttribute_parse(struct ExceptionsAttribute* attribute, FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->number_of_exceptions)) !=
      STATUS_OK)
    return status;

  if (attribute->number_of_exceptions > 0) {
    attribute->exception_index_table =
      calloc(attribute->number_of_exceptions, sizeof(uint16_t));
    if (!attribute->exception_index_table)
      return STATUS_NO_MEM;

    for (uint16_t i = 0; i < attribute->number_of_exceptions; ++i)
      if ((status = _read_u16_from_file(
             file, &attribute->exception_index_table[i])) != STATUS_OK)
        return status;
  } else
    attribute->exception_index_table = NULL;
  return status;
}

void
ExceptionsAttribute_free(struct ExceptionsAttribute* attribute)
{
  if (!attribute)
    return;

  free(attribute->exception_index_table);
  attribute->exception_index_table = NULL;
}
