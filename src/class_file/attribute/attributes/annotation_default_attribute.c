#include "class_file/attribute/attributes/annotation_default_attribute.h"
#include "class_file/element_value/element_value.h"

enum StatusCode
AnnotationDefaultAttribute_parse(struct AnnotationDefaultAttribute* attribute,
                                 FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = ElementValue_parse(&attribute->default_value, file)) !=
      STATUS_OK)
    return status;

  return status;
}
