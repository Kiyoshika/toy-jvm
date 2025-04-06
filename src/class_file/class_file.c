#include "class/class_file.h"
#include "constant_pool/constant_pool.h"
#include "util/file_util.h"

enum StatusCode class_file_read(const char* path, struct ClassFile* class_file) {
  if (!class_file)
    return STATUS_BAD_ARG;

  FILE* file = fopen(path, "r");
  if (!file)
    return STATUS_IO_FAILED;

  rewind(file);

  // start parsing class file according to https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.4

  uint16_t u16_value = 0u;
  uint32_t u32_value = 0u;

  if (!_read_u32_from_file(file, &u32_value))
    goto error;
  class_file->magic_number = u32_value;

  if (!_read_u16_from_file(file, &u16_value))
    goto error;
  class_file->minor_version = u16_value;

  if (!_read_u16_from_file(file, &u16_value))
    goto error;
  class_file->major_version = u16_value;

  if (!_read_u16_from_file(file, &u16_value))
    goto error;
  class_file->constant_pool_count = u16_value;

  // initialize the constant pool and pass the current active
  // file pointer to start parsing
  enum StatusCode status = constant_pool_init(&class_file->constant_pool, class_file->constant_pool_count);
  if (status != STATUS_OK)
    return status;

  status = constant_pool_parse(file, &class_file->constant_pool);
  if (status != STATUS_OK)
    return status;


  fclose(file);
  return STATUS_OK;

  error:
  fclose(file);
  return STATUS_IO_FAILED;
}

void class_file_free(struct ClassFile* class_file) {
  if (!class_file)
    return;

  constant_pool_free(&class_file->constant_pool);
}