#ifndef POINTER_H
#define POINTER_H

#include <stddef.h>

#include "status/status_code.h"

struct Pointer
{
  size_t heap_start_idx;
  size_t size_bytes;
};

enum StatusCode
pointer_init(struct Pointer* pointer);

#endif // POINTER_H
