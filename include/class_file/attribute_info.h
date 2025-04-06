#ifndef ATTRIBUTE_INFO_H
#define ATTRIBUTE_INFO_H

#include <stdint.h>

struct AttributeInfo {
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  // TODO: union of attribute structs defined in section 4.7: https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.7
};

#endif //ATTRIBUTE_INFO_H
