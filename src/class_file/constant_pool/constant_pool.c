#include "class_file/constant_pool/constant_pool.h"
#include "class_file/constant_pool/constant_pool_item.h"
#include "class_file/constant_pool/info_structs/class_info.h"
#include "class_file/constant_pool/info_structs/double_info.h"
#include "class_file/constant_pool/info_structs/field_ref_info.h"
#include "class_file/constant_pool/info_structs/float_info.h"
#include "class_file/constant_pool/info_structs/integer_info.h"
#include "class_file/constant_pool/info_structs/interface_method_ref_info.h"
#include "class_file/constant_pool/info_structs/invoke_dynamic_info.h"
#include "class_file/constant_pool/info_structs/long_info.h"
#include "class_file/constant_pool/info_structs/method_handle_info.h"
#include "class_file/constant_pool/info_structs/method_ref_info.h"
#include "class_file/constant_pool/info_structs/method_type_info.h"
#include "class_file/constant_pool/info_structs/name_and_type_info.h"
#include "class_file/constant_pool/info_structs/string_info.h"
#include "class_file/constant_pool/info_structs/utf8_info.h"
#include "util/file_util.h"

static enum StatusCode
_parse_class_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct ClassInfo class_info;
  class_info.tag = CONSTANT_POOL_CLASS;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &class_info.name_index)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = class_info.tag,
                                       .item = class_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_double_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct DoubleInfo _double_info;
  _double_info.tag = CONSTANT_POOL_DOUBLE;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u32_from_file(file, &_double_info.high_bytes)) !=
      STATUS_OK)
    return status;

  if ((status = _read_u32_from_file(file, &_double_info.low_bytes)) !=
      STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _double_info.tag,
                                       .item.double_info = _double_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_field_ref_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct FieldRefInfo _field_ref_info;
  _field_ref_info.tag = CONSTANT_POOL_FIELD_REF;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &_field_ref_info.class_index)) !=
      STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(
         file, &_field_ref_info.name_and_type_index)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _field_ref_info.tag,
                                       .item.field_ref_info = _field_ref_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_float_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct FloatInfo _float_info;
  _float_info.tag = CONSTANT_POOL_FLOAT;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u32_from_file(file, &_float_info.bytes)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _float_info.tag,
                                       .item.float_info = _float_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_integer_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct IntegerInfo _integer_info;
  _integer_info.tag = CONSTANT_POOL_INTEGER;

  enum StatusCode status = STATUS_OK;
  if ((status = _read_u32_from_file(file, &_integer_info.bytes)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _integer_info.tag,
                                       .item.integer_info = _integer_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_interface_method_ref_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct InterfaceMethodRefInfo _interface_method_ref_info;
  _interface_method_ref_info.tag = CONSTANT_POOL_INTERFACE_METHOD_REF;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(
         file, &_interface_method_ref_info.class_index)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(
         file, &_interface_method_ref_info.name_and_type_index)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _interface_method_ref_info.tag,
                                       .item.interface_method_ref_info =
                                         _interface_method_ref_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_invoke_dynamic_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct InvokeDynamicInfo _invoke_dynamic_info;
  _invoke_dynamic_info.tag = CONSTANT_POOL_INVOKE_DYNAMIC;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(
         file, &_invoke_dynamic_info.bootstrap_method_attr_index)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(
         file, &_invoke_dynamic_info.name_and_type_index)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _invoke_dynamic_info.tag,
                                       .item.invoke_dynamic_info =
                                         _invoke_dynamic_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_long_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct LongInfo _long_info;
  _long_info.tag = CONSTANT_POOL_LONG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u32_from_file(file, &_long_info.high_bytes)) != STATUS_OK)
    return status;

  if ((status = _read_u32_from_file(file, &_long_info.low_bytes)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = {
    .tag = _long_info.tag,
    .item.long_info = _long_info,
  };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_method_handle_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct MethodHandleInfo _method_handle_info;
  _method_handle_info.tag = CONSTANT_POOL_METHOD_HANDLE;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u8_from_file(
         file, &_method_handle_info.reference_kind)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(
         file, &_method_handle_info.reference_index)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _method_handle_info.tag,
                                       .item.method_handle_info =
                                         _method_handle_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_method_ref_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct MethodRefInfo _method_ref_info;
  _method_ref_info.tag = CONSTANT_POOL_METHOD_REF;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &_method_ref_info.class_index)) !=
      STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(
         file, &_method_ref_info.name_and_type_index)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _method_ref_info.tag,
                                       .item.method_ref_info =
                                         _method_ref_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_method_type_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct MethodTypeInfo _method_type_info;
  _method_type_info.tag = CONSTANT_POOL_METHOD_TYPE;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(
         file, &_method_type_info.descriptor_index)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _method_type_info.tag,
                                       .item.method_type_info =
                                         _method_type_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_name_and_type_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct NameAndTypeInfo _name_and_type_info;
  _name_and_type_info.tag = CONSTANT_POOL_NAME_AND_TYPE;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &_name_and_type_info.name_index)) !=
      STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(
         file, &_name_and_type_info.descriptor_index)) != STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _name_and_type_info.tag,
                                       .item.name_and_type_info =
                                         _name_and_type_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_string_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct StringInfo _string_info;
  _string_info.tag = CONSTANT_POOL_STRING;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &_string_info.class_index)) !=
      STATUS_OK)
    return status;

  struct ConstantPoolItem new_item = { .tag = _string_info.tag,
                                       .item.string_info = _string_info };

  return constant_pool_add_item(constant_pool, &new_item);
}

static enum StatusCode
_parse_utf8_info(FILE* file, struct ConstantPool* constant_pool)
{
  struct Utf8Info _utf8_info;
  _utf8_info.tag = CONSTANT_POOL_UTF8;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &_utf8_info.length)) != STATUS_OK)
    return status;

  char* content = calloc(_utf8_info.length + 1, sizeof(char));
  if (!content)
    return STATUS_NO_MEM;

  fgets(content, _utf8_info.length + 1, file);
  _utf8_info.bytes = content;

  // need to memcpy this so we don't lose the heap-allocated content pointer
  struct ConstantPoolItem new_item;
  new_item.tag = _utf8_info.tag;
  memcpy(&new_item.item.utf8_info, &_utf8_info, sizeof(struct Utf8Info));

  return constant_pool_add_item(constant_pool, &new_item);
}

enum StatusCode
constant_pool_init(struct ConstantPool* constant_pool,
                   size_t constant_pool_item_count)
{
  if (!constant_pool || constant_pool_item_count == 0u)
    return STATUS_BAD_ARG;

  constant_pool->items =
    calloc(constant_pool_item_count, sizeof(struct ConstantPoolItem));
  if (!constant_pool->items)
    return STATUS_NO_MEM;

  constant_pool->capacity = constant_pool_item_count;
  constant_pool->length = 0u;

  return STATUS_OK;
}

enum StatusCode
constant_pool_parse(FILE* file, struct ConstantPool* constant_pool)
{
  if (!file || !constant_pool)
    return STATUS_BAD_ARG;

  uint8_t constant_pool_tag = 0u;
  enum StatusCode status = STATUS_OK;
  // according to the spec, the array size is constant pool count - 1, so we
  // iterate index [0, count - 1) (e.g., if the count = 15, the size is 14, so
  // we iterate 0-13) it's a little confusing... but it is what it is.
  for (size_t i = 0; i < constant_pool->capacity - 1u; i++) {

    if ((status = _read_u8_from_file(file, &constant_pool_tag)) != STATUS_OK)
      return status;

    enum ConstantPoolTag tag = constant_pool_tag;
    switch (tag) {
      case CONSTANT_POOL_CLASS:
        if ((status = _parse_class_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_DOUBLE:
        if ((status = _parse_double_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_FIELD_REF:
        if ((status = _parse_field_ref_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_FLOAT:
        if ((status = _parse_float_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_INTEGER:
        if ((status = _parse_integer_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_INTERFACE_METHOD_REF:
        if ((status = _parse_interface_method_ref_info(file, constant_pool)) !=
            STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_INVOKE_DYNAMIC:
        if ((status = _parse_invoke_dynamic_info(file, constant_pool)) !=
            STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_LONG:
        if ((status = _parse_long_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_METHOD_HANDLE:
        if ((status = _parse_method_handle_info(file, constant_pool)) !=
            STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_METHOD_REF:
        if ((status = _parse_method_ref_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_METHOD_TYPE:
        if ((status = _parse_method_type_info(file, constant_pool)) !=
            STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_NAME_AND_TYPE:
        if ((status = _parse_name_and_type_info(file, constant_pool)) !=
            STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_STRING:
        if ((status = _parse_string_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      case CONSTANT_POOL_UTF8:
        if ((status = _parse_utf8_info(file, constant_pool)) != STATUS_OK)
          return status;
        break;
      default:
        return STATUS_BAD_CLASS_FORMAT;
    }
  }
  return STATUS_OK;
}

void
constant_pool_free(struct ConstantPool* constant_pool)
{
  if (!constant_pool)
    return;

  // check for any UTF8 info structs which dynamically allocate string data
  for (size_t i = 0; i < constant_pool->capacity; i++) {
    struct ConstantPoolItem* item = &constant_pool->items[i];
    if (item->tag == CONSTANT_POOL_UTF8) {
      free(item->item.utf8_info.bytes);
      item->item.utf8_info.bytes = NULL;
    }
  }

  free(constant_pool->items);
  constant_pool->items = NULL;
}

enum StatusCode
constant_pool_add_item(struct ConstantPool* constant_pool,
                       const struct ConstantPoolItem* item)
{
  if (!constant_pool || !item)
    return STATUS_BAD_ARG;

  memcpy(&constant_pool->items[constant_pool->length++],
         item,
         sizeof(struct ConstantPoolItem));
  return STATUS_OK;
}

const struct ConstantPoolItem*
constant_pool_get_item(const struct ConstantPool* constant_pool, size_t idx)
{
  if (!constant_pool)
    return NULL;

  if (idx >= constant_pool->length)
    return NULL;

  return &constant_pool->items[idx];
}
