#ifndef SOURCE_DEBUG_EXTENSION_H
#define SOURCE_DEBUG_EXTENSION_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct SourceDebugExtensionAttribute
{
  struct AttributeHeader header;
  uint8_t* debug_extension;
};

enum StatusCode
SourceDebugExtensionAttribute_parse(
  struct SourceDebugExtensionAttribute* attribute,
  FILE* file);

void
SourceDebugExtensionAttribute_free(
  struct SourceDebugExtensionAttribute* attribute);

#endif
