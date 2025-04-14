#include "class_file/attribute/attributes/signature_attribute.h"
#include "util/file_util.h"

enum StatusCode
SignatureAttribute_parse(struct SignatureAttribute* attribute, FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->signature_index)) !=
      STATUS_OK)
    return status;

  return status;
}
