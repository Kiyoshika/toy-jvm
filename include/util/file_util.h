#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Read at most 4 bytes from a file at a time and store it into a uint64_t.
 *
 * @param buffer A uint8_t[] buffer (max of 4 bytes)
 * @param read_bytes Number of bytes to take from the buffer and store into the
 * value
 * @return The value after combining the buffer into one uint64_t
 */
uint64_t _read_bytes_from_file(uint8_t* buffer, size_t read_bytes);
bool _read_u32_from_file(FILE* file, uint32_t* value);
bool _read_u16_from_file(FILE* file, uint16_t* value);
bool _read_u8_from_file(FILE* file, uint8_t* value);

#endif //FILE_UTIL_H
