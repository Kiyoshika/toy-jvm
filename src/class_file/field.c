#include "class_file/field/field.h"

void
field_free(struct Field* field)
{
  if (!field)
    return;
  free(field->attributes);
  field->attributes = NULL;
}
