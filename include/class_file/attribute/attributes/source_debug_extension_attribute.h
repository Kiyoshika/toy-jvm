#ifndef SOURCE_DEBUG_EXTENSION_H
#define SOURCE_DEBUG_EXTENSION_H

#include <stdint.h>
#include <stdlib.h>

struct SourceDebugExtensionAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint8_t* debug_extension;
};

void
SourceDebugExtensionAttribute_free(
  struct SourceDebugExtensionAttribute* attribute);

#endif
