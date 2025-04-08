#ifndef SOURCE_FILE_ATTRIBUTE_H
#define SOURCE_FILE_ATTRIBUTE_H

#include <stdint.h>

struct SourceFileAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t sourcefile_index;
};

#endif
