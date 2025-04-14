#ifndef SOURCE_FILE_ATTRIBUTE_H
#define SOURCE_FILE_ATTRIBUTE_H

#include <stdint.h>
#include <stdio.h>

#include "class_file/attribute/attribute_header.h"
#include "status/status_code.h"

struct SourceFileAttribute
{
  struct AttributeHeader header;
  uint16_t sourcefile_index;
};

enum StatusCode
SourceFileAttribute_parse(struct SourceFileAttribute* attribute, FILE* file);

#endif
