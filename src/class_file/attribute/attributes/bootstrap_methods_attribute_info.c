#include "class_file/attribute/attributes/bootstrap_methods_attribute_info.h"
#include "util/file_util.h"

enum StatusCode
BootstrapMethodsAttributeInfo_parse(struct BootstrapMethodsAttributeInfo* info,
                                    FILE* file)
{
  if (!info || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &info->bootstrap_method_ref)) !=
      STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &info->num_bootstrap_arguments)) !=
      STATUS_OK)
    return status;

  if (info->num_bootstrap_arguments > 0) {
    info->bootstrap_arguments =
      calloc(info->num_bootstrap_arguments, sizeof(uint16_t));
    if (!info->bootstrap_arguments)
      return STATUS_NO_MEM;

    for (uint16_t i = 0; i < info->num_bootstrap_arguments; ++i)
      if ((status = _read_u16_from_file(file, &info->bootstrap_arguments[i])) !=
          STATUS_OK)
        return status;
  }

  return STATUS_OK;
}

void
BootstrapMethodsAttributeInfo_free(struct BootstrapMethodsAttributeInfo* info)
{
  if (!info)
    return;

  if (info->bootstrap_arguments) {
    free(info->bootstrap_arguments);
    info->bootstrap_arguments = NULL;
  }
}
