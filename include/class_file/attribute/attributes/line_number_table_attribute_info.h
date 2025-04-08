#ifndef LINE_NUMBER_TABLE_ATTRIBUTE_INFO_H
#define LINE_NUMBER_TABLE_ATTRIBUTE_INFO_H

#include <stdint.h>

struct LineNumberTableAttributeInfo
{
  uint16_t start_pc;
  uint16_t line_number;
};

#endif
