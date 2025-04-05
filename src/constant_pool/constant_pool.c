#include "constant_pool/constant_pool.h"
#include "constant_pool/constant_pool_item.h"
#include "constant_pool/info_structs/class_info.h"
#include "util/file_util.h"

static enum StatusCode _parse_class_info(FILE* file, struct ConstantPool* constant_pool) {
  struct ClassInfo class_info;
  class_info.tag = CONSTANT_POOL_CLASS;
  if (!_read_u16_from_file(file, &class_info.name_index))
    return STATUS_IO_FAILED;

  struct ConstantPoolItem new_item = {
    .tag = class_info.tag,
    .item = class_info
  };

  return constant_pool_add_item(constant_pool, &new_item);
}

enum StatusCode constant_pool_init(struct ConstantPool* constant_pool, size_t constant_pool_item_count) {
  if (!constant_pool || constant_pool_item_count == 0u)
    return STATUS_BAD_ARG;

  constant_pool->items = calloc(constant_pool_item_count, sizeof(struct ConstantPoolItem));
  if (!constant_pool->items)
    return STATUS_NO_MEM;

  constant_pool->capacity = constant_pool_item_count;

  return STATUS_OK;
}

enum StatusCode constant_pool_parse(FILE* file, struct ConstantPool* constant_pool) {
  if (!file || !constant_pool)
    return STATUS_BAD_ARG;

  uint8_t constant_pool_tag = 0u;
  for (size_t i = 0; i < constant_pool->capacity; i++) {
    _read_u8_from_file(file, &constant_pool_tag);
    enum ConstantPoolTag tag = constant_pool_tag;
    switch (tag) {
      case CONSTANT_POOL_CLASS:
        if (!_parse_class_info(file, constant_pool))
          return STATUS_IO_FAILED;
        break;
      // TODO: other cases
      default:
        return STATUS_BAD_CLASS_FORMAT;
    }
  }
  return STATUS_OK;
}

void constant_pool_free(struct ConstantPool* constant_pool) {
  if (!constant_pool)
    return;
  free(constant_pool->items);
  constant_pool->items = NULL;
}

enum StatusCode constant_pool_add_item(struct ConstantPool* constant_pool, const struct ConstantPoolItem* item) {
  if (!constant_pool || !item)
    return STATUS_BAD_ARG;

  memcpy(constant_pool->items, item, sizeof(struct ConstantPoolItem));
  return STATUS_OK;
}