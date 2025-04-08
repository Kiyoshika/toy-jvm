#ifndef ELEMENT_VALUE_PAIR_H
#define ELEMENT_VALUE_PAIR_H

#include <stdint.h>

struct ElementValuePair
{
  uint16_t element_name_index;
  struct ElementValue value;
};

#endif
