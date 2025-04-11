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

  if ((status = field_parse_attributes(field, file, class_file)) != STATUS_OK)
    return status;

  return status;
}

enum StatusCode
field_parse_attributes(struct Field* field,
                       FILE* file,
                       struct ClassFile* class_file)
{
  uint16_t attribute_name_index = 0u;
  uint32_t attribute_length = 0u;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &attribute_name_index)) != STATUS_OK)
    return status;

  if ((status = _read_u32_from_file(file, &attribute_length)) != STATUS_OK)
    return status;

  const struct ConstantPoolItem* attribute =
    constant_pool_get_item(&class_file->constant_pool, attribute_name_index);

  if (!attribute || attribute->tag != CONSTANT_POOL_UTF8)
    return STATUS_BAD_CLASS_FORMAT;

  const struct Utf8Info* utf8_info = &attribute->item.utf8_info;

  const char* attribute_name = utf8_info->bytes;

  struct AttributeInfo attribute_info;
  AttributeInfo_parse(&attribute_info, file, attribute_name);

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
