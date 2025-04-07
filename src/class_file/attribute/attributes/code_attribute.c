#include "class_file/attribute/attributes/code_attribute.h"

void
CodeAttribute_free(struct CodeAttribute* attribute)
{
  if (!attribute)
    return;

  free(attribute->code);
  attribute->code = NULL;
}
