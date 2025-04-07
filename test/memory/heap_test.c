#include <assert.h>
#include <stdint.h>

#include "memory/heap.h"

void initHeap() {
  char* x = malloc(100);
  struct Heap heap;
  assert(Heap_init(&heap, 16u) == STATUS_OK);

  assert(heap.byte_pool != NULL);
  assert(heap.heap_capacity == 16u);
  assert(heap.heap_start_search_idx == 0u);
  assert(heap.pointers != NULL);
  assert(heap.pointers_capacity == 8u);
  assert(heap.write_pointer_idx == 0u);

  Heap_free(&heap);
}

void allocPointersNoHeapResize() {
  struct Heap heap;
  Heap_init(&heap, 16u);

  struct Pointer p1;
  assert(Heap_allocate(&heap, 4u, &p1) == STATUS_OK);
  assert(heap.write_pointer_idx == 1u);

  struct Pointer p2;
  assert(Heap_allocate(&heap, 6u, &p2) == STATUS_OK);
  assert(heap.write_pointer_idx == 2u);

  assert(p1.heap_start_idx == 0u);
  assert(p1.size_bytes == 4u);
  assert(p1.heap_start_idx == heap.pointers[0].heap_start_idx);
  assert(p1.size_bytes == heap.pointers[0].size_bytes);

  assert(p2.heap_start_idx == 4u);
  assert(p2.size_bytes == 6u);
  assert(p2.heap_start_idx == heap.pointers[1].heap_start_idx);
  assert(p2.size_bytes == heap.pointers[1].size_bytes);

  Heap_free(&heap);
}

// allocate multiple pointers on the heap such that the sum of their sizes
// equal the heap capacity
void allocMultiplePointersCausingHeapResize_ExactSize() {
  struct Heap heap;
  Heap_init(&heap, 4u);

  struct Pointer p1;
  Heap_allocate(&heap, 2u, &p1);

  struct Pointer p2;
  Heap_allocate(&heap, 2u, &p2);

  // heap capacity should have doubled
  assert(heap.heap_capacity == 8u);

  Heap_free(&heap);
}

// allocate multiple pointers such that the sum of their sizes
// exceeds the heap capacity
void allocMultiplePointersCausingHeapResize_SumIsLarger() {
  struct Heap heap;
  Heap_init(&heap, 4u);

  struct Pointer p1;
  Heap_allocate(&heap, 1u, &p1);

  struct Pointer p2;
  Heap_allocate(&heap, 6u, &p2);

  // heap capacity should double
  assert(heap.heap_capacity == 8u);

  Heap_free(&heap);
}

void allocMultiplePointersCausingHeapResize_RequestedSizeLargerThanDoublingRule() {
  struct Heap heap;
  Heap_init(&heap, 4u);

  struct Pointer p1;
  Heap_allocate(&heap, 1u, &p1);

  struct Pointer p2;
  Heap_allocate(&heap, 30u, &p2);

  // heap capacity should double
  assert(heap.heap_capacity == 32u);

  Heap_free(&heap);
}

void allocOneLargePointerTooBigForHeapCausingResize() {
  struct Heap heap;
  Heap_init(&heap, 4u);

  struct Pointer p1;
  Heap_allocate(&heap, 10u, &p1);

  assert(heap.heap_capacity == 16u);

  Heap_free(&heap);
}

void deallocPointers() {
  struct Heap heap;
  Heap_init(&heap, 4u);

  struct Pointer p1;
  Heap_allocate(&heap, 1u, &p1);

  struct Pointer p2;
  Heap_allocate(&heap, 1u, &p2);

  assert(heap.pointers_active == 2u);

  Heap_deallocate(&heap, &p1);
  assert(heap.pointers_active == 1u);

  Heap_deallocate(&heap, &p2);
  assert(heap.pointers_active == 0u);

  Heap_free(&heap);
}

// create two pointers and deallocate the first one.
// then create a pointer too large to fit in first spot that it needs
// to shift past the second pointer
void deallocTocreateFragmentedHeap() {
  struct Heap heap;

  Heap_init(&heap, 16u);

  struct Pointer p1;
  Heap_allocate(&heap, 2u, &p1);

  struct Pointer p2;
  Heap_allocate(&heap, 3u, &p2);

  Heap_deallocate(&heap, &p1);

  struct Pointer p3;
  Heap_allocate(&heap, 4u, &p3);

  // since a pointer of size 4 doesn't fit in the empty two byte space,
  // it gets moved to the end of the second pointer
  assert(p3.heap_start_idx == 5u);

  Heap_free(&heap);
}

void readAndWriteTwoIntegers() {
  struct Heap heap;
  Heap_init(&heap, 16u);

  struct Pointer p1;
  Heap_allocate(&heap, sizeof(uint16_t), &p1);
  uint16_t p1_value = 42u;
  Heap_write_pointer_content(&heap, &p1, &p1_value);
  p1_value = 0u;
  Heap_get_pointer_content(&heap, &p1, &p1_value);
  assert(p1_value == 42u);

  struct Pointer p2;
  Heap_allocate(&heap, sizeof(int64_t), &p2);
  int64_t p2_value = -310LL;
  Heap_write_pointer_content(&heap, &p2, &p2_value);
  p2_value = 0LL;
  Heap_get_pointer_content(&heap, &p2, &p2_value);
  assert(p2_value == -310LL);

  Heap_free(&heap);
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
