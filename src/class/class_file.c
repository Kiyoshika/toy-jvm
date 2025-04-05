#include "class/class_file.h"

/**
 * Read at most 4 bytes from a file at a time and store it into a uint64_t.
 *
 * @param buffer A uint8_t[] buffer (max of 4 bytes)
 * @param read_bytes Number of bytes to take from the buffer and store into the
 * value
 * @return The value after combining the buffer into one uint64_t
 */
static uint64_t _read_bytes_from_file(uint8_t* buffer, size_t read_bytes) {
  uint64_t value = 0;

  size_t buffer_idx = 0;
  while (read_bytes --> 0)
    value |= (uint64_t)buffer[buffer_idx++] << 8*read_bytes;

  return value;
}

static bool _read_u32_from_file(FILE* file, uint32_t* value) {
  uint8_t buffer[4] = {0};
  if (!fread(buffer, 1u, 4u, file))
    return false;

  *value = _read_bytes_from_file(buffer, 4u);
  return true;
}

static bool _read_u16_from_file(FILE* file, uint16_t* value) {
  uint8_t buffer[2] = {0};
  if (!fread(buffer, 1u, 2u, file))
    return false;

  *value = _read_bytes_from_file(buffer, 2u);
  return true;
}

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


  fclose(file);
  return STATUS_OK;

  error:
  fclose(file);
  return STATUS_IO_FAILED;
}