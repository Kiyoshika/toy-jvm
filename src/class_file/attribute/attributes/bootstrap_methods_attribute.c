#include "class_file/attribute/attributes/bootstrap_methods_attribute.h"
#include "util/file_util.h"

enum StatusCode
BootstrapMethodsAttribute_parse(struct BootstrapMethodsAttribute* attribute,
                                FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->num_bootstrap_methods)) !=
      STATUS_OK)
    return status;

  if (attribute->num_bootstrap_methods > 0) {
    attribute->bootstrap_methods =
      calloc(attribute->num_bootstrap_methods,
             sizeof(struct BootstrapMethodsAttributeInfo));

    if (!attribute->num_bootstrap_methods)
      return STATUS_NO_MEM;

    if ((status = BootstrapMethodsAttributeInfo_parse(
           attribute->bootstrap_methods, file)) != STATUS_OK)
      return status;
  } else
    attribute->bootstrap_methods = NULL;

  return STATUS_OK;
}

void
BootstrapMethodsAttribute_free(struct BootstrapMethodsAttribute* attribute)
{
  if (!attribute)
    return;

  if (attribute->bootstrap_methods) {
    for (size_t i = 0; i < attribute->num_bootstrap_methods; ++i)
      BootstrapMethodsAttributeInfo_free(&attribute->bootstrap_methods[i]);

    free(attribute->bootstrap_methods);
    attribute->bootstrap_methods = NULL;
  }
}
