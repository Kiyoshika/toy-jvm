#include "util/file_util.h"

/**
 * Read at most 4 bytes from a file at a time and store it into a uint64_t.
 *
 * @param buffer A uint8_t[] buffer (max of 4 bytes)
 * @param read_bytes Number of bytes to take from the buffer and store into the
 * value
 * @return The value after combining the buffer into one uint64_t
 */
uint64_t
_read_bytes_from_file(uint8_t* buffer, size_t read_bytes)
{
  uint64_t value = 0;

  size_t buffer_idx = 0;
  while (read_bytes-- > 0)
    value |= (uint64_t)buffer[buffer_idx++] << 8 * read_bytes;

  return value;
}

bool
_read_u32_from_file(FILE* file, uint32_t* value)
{
  uint8_t buffer[4] = { 0 };
  if (!fread(buffer, 1u, 4u, file))
    return false;

  *value = _read_bytes_from_file(buffer, 4u);
  return true;
}

bool
_read_u16_from_file(FILE* file, uint16_t* value)
{
  uint8_t buffer[2] = { 0 };
  if (!fread(buffer, 1u, 2u, file))
    return false;

  *value = _read_bytes_from_file(buffer, 2u);
  return true;
}

bool
_read_u8_from_file(FILE* file, uint8_t* value)
{
  uint8_t buffer[1] = { 0 };
  if (!fread(buffer, 1u, 1u, file))
    return false;

  *value = _read_bytes_from_file(buffer, 1u);
  return true;
}