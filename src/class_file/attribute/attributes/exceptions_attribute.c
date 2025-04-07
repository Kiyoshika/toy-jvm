#include "class_file/attribute/attributes/exceptions_attribute.h"

void
ExceptionsAttribute_free(struct ExceptionsAttribute* attribute)
{
  if (!attribute)
    return;

  free(attribute->exception_index_table);
  attribute->exception_index_table = NULL;
}
