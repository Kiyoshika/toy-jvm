#include "class_file/attribute/attributes/inner_classes_attribute.h"

void
InnerClassesAttribute_free(struct InnerClassesAttribute* attribute)
{
  if (!attribute)
    return;

  free(attribute->classes);
  attribute->classes = NULL;
}
