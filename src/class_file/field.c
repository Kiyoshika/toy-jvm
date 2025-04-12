#include "class_file/field/field.h"
#include "class_file/attribute/attribute_info.h"
#include "class_file/constant_pool/constant_pool_item.h"
#include "class_file/constant_pool/constant_pool_tag.h"
#include "util/file_util.h"

enum StatusCode
field_init(struct Field* field)
{
  if (!field)
    return STATUS_BAD_ARG;

  field->access_flags = 0u;
  field->name_index = 0u;
  field->descriptor_index = 0u;
  field->attributes_count = 0u;
  field->attributes = NULL; // will be set during parsing

  return STATUS_OK;
}

enum StatusCode
field_parse(struct Field* field, FILE* file, struct ClassFile* class_file)
{
  if (!file || !class_file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &field->access_flags)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &field->name_index)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &field->descriptor_index)) !=
      STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &field->attributes_count)) !=
      STATUS_OK)
    return status;

  // TODO: use AttributeInfo_parse() to parse field attributes

  return status;
}

void
field_free(struct Field* field)
{
  if (!field)
    return;
  free(field->attributes);
  field->attributes = NULL;
}
