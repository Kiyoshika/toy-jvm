#include "class_file/attribute/attributes/inner_classes_attribute.h"
#include "util/file_util.h"

enum StatusCode
InnerClassesAttribute_parse(struct InnerClassesAttribute* attribute, FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->number_of_classes)) !=
      STATUS_OK)
    return status;

  if (attribute->number_of_classes > 0) {
    attribute->classes = calloc(attribute->number_of_classes,
                                sizeof(struct InnerClassesAttributeInfo));
    if (!attribute->classes)
      return STATUS_NO_MEM;

    for (uint16_t i = 0; i < attribute->number_of_classes; ++i)
      if ((status = InnerClassesAttributeInfo_parse(&attribute->classes[i],
                                                    file)) != STATUS_OK)
        return status;
  } else
    attribute->classes = NULL;

  return status;
}

void
InnerClassesAttribute_free(struct InnerClassesAttribute* attribute)
{
  if (!attribute)
    return;

  free(attribute->classes);
  attribute->classes = NULL;
}
