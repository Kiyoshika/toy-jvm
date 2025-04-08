#ifndef SIGNATURE_ATTRIBUTE_H
#define SIGNATURE_ATTRIBUTE_H

#include <stdint.h>

struct SignatureAttribute
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t signature_index;
};

#endif
