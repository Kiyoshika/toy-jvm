#include "class_file/attribute/attributes/code_attribute.h"
#include "class_file/attribute/attribute_header.h"
#include "class_file/attribute/attribute_info.h"
#include "class_file/exception_table.h"
#include "util/file_util.h"

enum StatusCode
CodeAttribute_parse(struct CodeAttribute* attribute,
                    FILE* file,
                    const struct ConstantPool* constant_pool)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->max_stack)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->max_locals)) != STATUS_OK)
    return status;

  if ((status = _read_u32_from_file(file, &attribute->code_length)) !=
      STATUS_OK)
    return status;

  if (attribute->code_length > 0) {
    attribute->code = calloc(attribute->code_length + 1, sizeof(uint8_t));
    if (!attribute->code)
      return STATUS_NO_MEM;

    if ((status = _read_nbytes_from_file(
           file, attribute->code, attribute->code_length)) != STATUS_OK)
      return status;
  } else
    attribute->code = NULL;

  if ((status = _read_u16_from_file(
         file, &attribute->exception_table_length)) != STATUS_OK)
    return status;

  if (attribute->exception_table_length > 0) {
    attribute->exceptions =
      calloc(attribute->exception_table_length, sizeof(struct ExceptionTable));
    if (!attribute->exceptions)
      return STATUS_NO_MEM;

    for (uint16_t i = 0; i < attribute->exception_table_length; ++i)
      if ((status = ExceptionTable_parse(&attribute->exceptions[i], file)) !=
          STATUS_OK)
        return status;
  } else
    attribute->exceptions = NULL;

  if ((status = _read_u16_from_file(file, &attribute->attributes_count)) !=
      STATUS_OK)
    return status;

  if (attribute->attributes_count > 0) {
    attribute->attributes =
      calloc(attribute->attributes_count, sizeof(struct AttributeInfo));
    if (!attribute->attributes)
      return STATUS_NO_MEM;

    for (uint16_t i = 0; i < attribute->attributes_count; ++i)
      if ((status = AttributeInfo_parse(
             attribute->attributes, file, constant_pool)) != STATUS_OK)
        return status;
  } else
    attribute->attributes = NULL;

  return status;
}

void
CodeAttribute_free(struct CodeAttribute* attribute)
{
  if (!attribute)
    return;

  free(attribute->code);
  attribute->code = NULL;
}
