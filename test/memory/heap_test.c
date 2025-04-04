#include <assert.h>
#include <stdint.h>

#include "memory/heap.h"

void initHeap() {
  struct Heap heap;
  assert(heap_init(&heap, 16u) == STATUS_OK);

  assert(heap.byte_pool != NULL);
  assert(heap.heap_capacity == 16u);
  assert(heap.heap_start_search_idx == 0u);
  assert(heap.pointers != NULL);
  assert(heap.pointers_capacity == 8u);
  assert(heap.write_pointer_idx == 0u);
}

void allocPointersNoHeapResize() {
  struct Heap heap;
  heap_init(&heap, 16u);

  struct Pointer p1;
  assert(heap_allocate(&heap, 4u, &p1) == STATUS_OK);
  assert(heap.write_pointer_idx == 1u);

  struct Pointer p2;
  assert(heap_allocate(&heap, 6u, &p2) == STATUS_OK);
  assert(heap.write_pointer_idx == 2u);

  assert(p1.heap_start_idx == 0u);
  assert(p1.size_bytes == 4u);
  assert(p1.heap_start_idx == heap.pointers[0].heap_start_idx);
  assert(p1.size_bytes == heap.pointers[0].size_bytes);

  assert(p2.heap_start_idx == 4u);
  assert(p2.size_bytes == 6u);
  assert(p2.heap_start_idx == heap.pointers[1].heap_start_idx);
  assert(p2.size_bytes == heap.pointers[1].size_bytes);
}

// allocate multiple pointers on the heap such that the sum of their sizes
// equal the heap capacity
void allocMultiplePointersCausingHeapResize_ExactSize() {
  struct Heap heap;
  heap_init(&heap, 4u);

  struct Pointer p1;
  heap_allocate(&heap, 2u, &p1);

  struct Pointer p2;
  heap_allocate(&heap, 2u, &p2);

  // heap capacity should have doubled
  assert(heap.heap_capacity == 8u);
}

// allocate multiple pointers such that the sum of their sizes
// exceeds the heap capacity
void allocMultiplePointersCausingHeapResize_SumIsLarger() {
  struct Heap heap;
  heap_init(&heap, 4u);

  struct Pointer p1;
  heap_allocate(&heap, 1u, &p1);

  struct Pointer p2;
  heap_allocate(&heap, 6u, &p2);

  // heap capacity should double
  assert(heap.heap_capacity == 8u);
}

void allocMultiplePointersCausingHeapResize_RequestedSizeLargerThanDoublingRule() {
  struct Heap heap;
  heap_init(&heap, 4u);

  struct Pointer p1;
  heap_allocate(&heap, 1u, &p1);

  struct Pointer p2;
  heap_allocate(&heap, 30u, &p2);

  // heap capacity should double
  assert(heap.heap_capacity == 32u);
}

void allocOneLargePointerTooBigForHeapCausingResize() {
  struct Heap heap;
  heap_init(&heap, 4u);

  struct Pointer p1;
  heap_allocate(&heap, 10u, &p1);

  assert(heap.heap_capacity == 16u);
}

void deallocPointers() {
  struct Heap heap;
  heap_init(&heap, 4u);

  struct Pointer p1;
  heap_allocate(&heap, 1u, &p1);

  struct Pointer p2;
  heap_allocate(&heap, 1u, &p2);

  assert(heap.pointers_active == 2u);

  heap_deallocate(&heap, &p1);
  assert(heap.pointers_active == 1u);

  heap_deallocate(&heap, &p2);
  assert(heap.pointers_active == 0u);
}

// create two pointers and deallocate the first one.
// then create a pointer too large to fit in first spot that it needs
// to shift past the second pointer
void deallocTocreateFragmentedHeap() {
  struct Heap heap;

  heap_init(&heap, 16u);

  struct Pointer p1;
  heap_allocate(&heap, 2u, &p1);

  struct Pointer p2;
  heap_allocate(&heap, 3u, &p2);

  heap_deallocate(&heap, &p1);

  struct Pointer p3;
  heap_allocate(&heap, 4u, &p3);

  // since a pointer of size 4 doesn't fit in the empty two byte space,
  // it gets moved to the end of the second pointer
  assert(p3.heap_start_idx == 5u);
}

void readAndWriteTwoIntegers() {
  struct Heap heap;
  heap_init(&heap, 16u);

  struct Pointer p1;
  heap_allocate(&heap, sizeof(uint16_t), &p1);
  uint16_t p1_value = 42u;
  heap_write_pointer_content(&heap, &p1, &p1_value);
  p1_value = 0u;
  heap_get_pointer_content(&heap, &p1, &p1_value);
  assert(p1_value == 42u);

  struct Pointer p2;
  heap_allocate(&heap, sizeof(int64_t), &p2);
  int64_t p2_value = -310LL;
  heap_write_pointer_content(&heap, &p2, &p2_value);
  p2_value = 0LL;
  heap_get_pointer_content(&heap, &p2, &p2_value);
  assert(p2_value == -310LL);
}

int main() {
  initHeap();
  allocPointersNoHeapResize();
  allocMultiplePointersCausingHeapResize_ExactSize();
  allocMultiplePointersCausingHeapResize_SumIsLarger();
  allocMultiplePointersCausingHeapResize_RequestedSizeLargerThanDoublingRule();
  allocOneLargePointerTooBigForHeapCausingResize();
  deallocPointers();
  deallocTocreateFragmentedHeap();
  readAndWriteTwoIntegers();
  return 0;
}