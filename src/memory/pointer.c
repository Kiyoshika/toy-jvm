#include "memory/pointer.h"

enum StatusCode pointer_init(struct Pointer* pointer) {
  if (!pointer)
    return STATUS_BAD_ARG;

  pointer->heap_start_idx = 0u;
  pointer->size_bytes = 0u;
  return STATUS_OK;
}