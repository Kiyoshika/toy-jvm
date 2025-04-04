#include <stdbool.h>

#include "memory/heap.h"
#include "status/status_code.h"
#include "memory/pointer.h"

static bool __check_pointer_collision(
  const struct Heap* heap,
  size_t alloc_size_bytes,
  struct Pointer* furthest_pointer) {

  size_t alloc_lower_bound = heap->heap_start_search_idx;
  size_t alloc_upper_bound = heap->heap_start_search_idx + alloc_size_bytes - 1;

  bool pointer_collision = false;

  for (size_t ptr_i = 0; ptr_i < heap->pointers_capacity; ++ptr_i) {
    struct Pointer* heap_pointer = &heap->pointers[ptr_i];

    // skip "NULL" pointers
    if (heap_pointer->size_bytes == 0)
      continue;

    if (heap_pointer->heap_start_idx >= alloc_lower_bound &&
        heap_pointer->heap_start_idx <= alloc_upper_bound) {

      pointer_collision = true;

      if (furthest_pointer->size_bytes == 0)
        memcpy(furthest_pointer, heap_pointer, sizeof(struct Pointer));
      else if (heap_pointer->heap_start_idx > furthest_pointer->heap_start_idx)
        memcpy(furthest_pointer, heap_pointer, sizeof(struct Pointer));
    }
  }

  return pointer_collision;
}

static bool __allocate_pointer(
  struct Heap* heap,
  size_t alloc_size_bytes,
  struct Pointer* new_pointer) {
  new_pointer->heap_start_idx = heap->heap_start_search_idx;
  new_pointer->size_bytes = alloc_size_bytes;
  heap->heap_start_search_idx = heap->heap_start_search_idx + alloc_size_bytes;

  // copy new pointer into heap's internal pointer array
  struct Pointer* pointer_dest = &heap->pointers[heap->write_pointer_idx];
  memcpy(pointer_dest, new_pointer, sizeof(struct Pointer));
  heap->pointers_active++;
  if ((double)heap->pointers_active / (double)heap->pointers_capacity > heap->pointer_max_capacity_ratio) {
    size_t new_capacity = heap->pointers_capacity * 2u;
    void* realloc_pointers_array = realloc(heap->pointers, new_capacity);
    if (!realloc_pointers_array)
      return false;
    heap->pointers_capacity = new_capacity;
    heap->pointers = realloc_pointers_array;
  }

  // after allocating pointer, find the next "open slot" in our pointer
  // array to store a new pointer if allocated
  for (size_t i = 0; i < heap->pointers_capacity; ++i) {
    struct Pointer* pointer = &heap->pointers[i];
    if (pointer->size_bytes == 0) {
      heap->write_pointer_idx = i;
      break;
    }
  }
  return true;
}

static bool __resize_heap(
  struct Heap* heap,
  size_t alloc_size_bytes) {

  // if we get a pointer larger than the doubling rule, need to continue
  // growing to accommodate that size
  size_t new_capacity = heap->heap_capacity * 2u;
  while (new_capacity - heap->heap_start_search_idx < alloc_size_bytes)
    new_capacity *= 2u;

  void* realloc_heap = realloc(heap->byte_pool, new_capacity);

  if (!realloc_heap)
    return false;

  heap->heap_capacity = new_capacity;
  heap->byte_pool = realloc_heap;
  return true;
}

enum StatusCode heap_init(struct Heap *heap, size_t size_bytes) {
  if (!heap || size_bytes == 0)
    return STATUS_BAD_ARG;

  heap->byte_pool = calloc(size_bytes, 1u);
  if (!heap->byte_pool)
    return STATUS_NO_MEM;

  heap->heap_capacity = size_bytes;
  heap->heap_start_search_idx = 0u;

  size_t pointers_capacity = 8u;
  heap->pointers = calloc(pointers_capacity, sizeof(struct Pointer));
  if (!heap->pointers) {
    free(heap->byte_pool);
    heap->byte_pool = NULL;

    return STATUS_NO_MEM;
  }

  heap->pointers_capacity = pointers_capacity;
  heap->write_pointer_idx = 0u;
  heap->pointer_max_capacity_ratio = 0.75;
  heap->pointers_active = 0u;

  return STATUS_OK;
}

void heap_free(struct Heap *heap) {
  if (!heap)
    return;

  free(heap->pointers);
  heap->byte_pool = NULL;

  free(heap->pointers);
  heap->pointers = NULL;
}

enum StatusCode heap_allocate(
  struct Heap* heap,
  size_t size_bytes,
  struct Pointer* new_pointer) {

  if (!heap || size_bytes == 0 || !new_pointer)
    return STATUS_BAD_ARG;

  enum StatusCode init_pointer_status = pointer_init(new_pointer);
  if (init_pointer_status != STATUS_OK)
    return init_pointer_status;

  while (heap->heap_start_search_idx < heap->heap_capacity) {
    size_t remaining_heap_capacity = heap->heap_capacity - heap->heap_start_search_idx;
    if (remaining_heap_capacity < size_bytes)
      if (!__resize_heap(heap, size_bytes))
        return STATUS_NO_MEM;

    // check for pointer collisions
    struct Pointer furthest_pointer;
    pointer_init(&furthest_pointer);
    bool pointer_collision = __check_pointer_collision(heap, size_bytes, &furthest_pointer);

    if (!pointer_collision) {
      __allocate_pointer(heap, size_bytes, new_pointer);

      // if newly allocated pointer happens to use all remaining right-hand
      // heap memory, expand
      if (heap->heap_start_search_idx >= heap->heap_capacity)
        __resize_heap(heap, size_bytes);

      return STATUS_OK;
    }

    heap->heap_start_search_idx = furthest_pointer.heap_start_idx + furthest_pointer.size_bytes;
  }

  return STATUS_OK;
}

void heap_deallocate(struct Heap *heap, const struct Pointer *pointer) {
  if (!heap || !pointer)
    return;

  for (size_t ptr_i = 0; ptr_i < heap->pointers_capacity; ptr_i++) {
    // skip "NULL" pointers
    if (heap->pointers[ptr_i].size_bytes == 0)
      continue;

    struct Pointer* find_pointer = &heap->pointers[ptr_i];
    if (find_pointer->heap_start_idx == pointer->heap_start_idx) {
      heap->heap_start_search_idx = find_pointer->heap_start_idx;
      memset(find_pointer, 0, sizeof(struct Pointer));
      heap->write_pointer_idx = ptr_i;
      if (heap->pointers_active > 0u)
        heap->pointers_active--;
    }
  }
}