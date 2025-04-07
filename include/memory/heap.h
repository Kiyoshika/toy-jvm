#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "memory/pointer.h"
#include "status/status_code.h"

struct Heap
{
  void* byte_pool;
  size_t heap_capacity;
  size_t heap_start_search_idx;

  struct Pointer* pointers;
  size_t pointers_active; // how many "live" (non-NULL) pointers exist in heap
  size_t pointers_capacity;
  size_t write_pointer_idx;
  // when this ratio (0.0-1.0) is reached, increase pointer capacity
  double pointer_max_capacity_ratio;
};

/**
 * Initialize the heap with size_bytes in a continguous block of memory.
 *
 * @param heap A heap struct passed by address
 * @param size_bytes Number of bytes to initialize heap with
 * @return STATUS_OK on success, STATUS_NO_MEM if not enough memory could be
 * allocated or STATUS_BAD_ARG if an unexpected argument value was passed.
 */
enum StatusCode
Heap_init(struct Heap* heap, size_t size_bytes);

/**
 * Cleanup memory allocated by the heap.
 *
 * @param heap A heap struct passed by address
 */
void
Heap_free(struct Heap* heap);

/**
 * Allocate a block of memory in the heap and return a pointer to it.
 *
 * @param heap A heap struct passed by address
 * @param size_bytes The size of the block of memory to allocate for the pointer
 * @param new_pointer The pointer struct to write the allocated pointer into
 * @return STATUS_OK on success, STATUS_NO_MEM if not enough heap memory
 * available or STATUS_BAD_ARG if an unexpected argument value was passed
 */
enum StatusCode
Heap_allocate(struct Heap* heap,
              size_t size_bytes,
              struct Pointer* new_pointer);

/**
 * Deallocate memory held by a pointer.
 *
 * @param heap A heap struct passed by address
 * @param pointer The pointer to deallocate.
 */
void
Heap_deallocate(struct Heap* heap, const struct Pointer* pointer);

/**
 * Fetch the start address for a given pointer in the heap.
 *
 * @param heap A heap struct passed by address
 * @param pointer The pointer to fetch content for - must have
 * pointer->size_bytes > 0
 * @param content Pointer to write content into - needs to be at least
 * pointer->size_bytes long.
 * @return STATUS_BAD_ARG if heap/pointer is invalid, STATUS_OK otherwise.
 */
enum StatusCode
Heap_get_pointer_content(const struct Heap* heap,
                         const struct Pointer* pointer,
                         void* content);

/**
 * Writes content into the heap pointed to by a pointer.
 *
 * @param heap A heap struct passed by address
 * @param pointer The pointer to write into
 * @param content The content to write - assumed to be of length
 * pointer->size_bytes
 * @return STATUS_BAD_ARG if heap/pointer is invalid, STATUS_OK otherwise
 */
enum StatusCode
Heap_write_pointer_content(struct Heap* heap,
                           const struct Pointer* pointer,
                           const void* content);

#endif // HEAP_H
