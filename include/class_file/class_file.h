#ifndef CLASS_FILE_H
#define CLASS_FILE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "class_file/constant_pool/constant_pool.h"
#include "status/status_code.h"

// forward declaration
struct Field;

struct ClassFile
{
  uint32_t magic_number;
  uint16_t minor_version;
  uint16_t major_version;
  uint16_t constant_pool_count;
  struct ConstantPool constant_pool;
  uint16_t access_flags;
  uint16_t this_class;
  uint16_t super_class;
  uint16_t interfaces_count;
  uint16_t* interfaces; // points to ClassInfo indexes in the constant pool
  uint16_t fields_count;
  struct Field* fields;
};

enum StatusCode
class_file_read(const char* path, struct ClassFile* class_file);

enum StatusCode
class_file_append_field(struct ClassFile* class_file, const struct Field*);

void
class_file_free(struct ClassFile* class_file);

#endif // CLASS_FILE_H
