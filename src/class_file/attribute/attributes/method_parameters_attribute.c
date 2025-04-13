#include "class_file/attribute/attributes/method_parameters_attribute.h"
#include "class_file/attribute/attributes/method_parameters_attribute_info.h"
#include "util/file_util.h"

enum StatusCode
MethodParametersAttribute_parse(struct MethodParametersAttribute* attribute,
                                FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u8_from_file(file, &attribute->parameters_count)) !=
      STATUS_OK)
    return status;

  if (attribute->parameters_count > 0) {
    attribute->parameters =
      calloc(attribute->parameters_count,
             sizeof(struct MethodParametersAttributeInfo));
    if (!attribute->parameters)
      return STATUS_NO_MEM;

    for (uint8_t i = 0; i < attribute->parameters_count; ++i)
      if ((status = MethodParametersAttributeInfo_parse(
             &attribute->parameters[i], file)) != STATUS_OK)
        return status;
  } else
    attribute->parameters = NULL;

  return status;
}

void
MethodParametersAttribute_free(struct MethodParametersAttribute* attribute)
{
  if (!attribute)
    return;

  free(attribute->parameters);
  attribute->parameters = NULL;
}
