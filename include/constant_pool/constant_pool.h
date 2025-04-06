#ifndef CONSTANT_POOL_H
#define CONSTANT_POOL_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "status/status_code.h"
#include "constant_pool/constant_pool_item.h"

struct ConstantPool {
  struct ConstantPoolItem* items;
  size_t capacity;
  size_t length;
};

enum StatusCode constant_pool_init(struct ConstantPool* constant_pool, size_t constant_pool_item_count);
enum StatusCode constant_pool_parse(FILE* file, struct ConstantPool* constant_pool);
void constant_pool_free(struct ConstantPool* constant_pool);
enum StatusCode constant_pool_add_item(struct ConstantPool* constant_pool, const struct ConstantPoolItem* item);

#endif //CONSTANT_POOL_H
