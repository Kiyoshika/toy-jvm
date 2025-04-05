#ifndef CLASS_FILE_H
#define CLASS_FILE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "status/status_code.h"
#include "constant_pool/constant_pool.h"

struct ClassFile {
  uint32_t magic_number;
  uint16_t minor_version;
  uint16_t major_version;
  uint16_t constant_pool_count;
  struct ConstantPool constant_pool;
};

enum StatusCode class_file_read(const char* path, struct ClassFile* class_file);

#endif //CLASS_FILE_H
