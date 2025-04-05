#ifndef UTF8_INFO_H
#define UTF8_INFO_H

#include <stdint.h>

#include "constant_pool/constant_pool_tag.h"

struct Utf8Info {
  enum ConstantPoolTag tag;
  uint16_t length;
  char* bytes;
};

#endif //UTF8_INFO_H
