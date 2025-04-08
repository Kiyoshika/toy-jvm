#ifndef INNER_CLASSES_ATTRIBUTE_INFO_H
#define INNER_CLASSES_ATTRIBUTE_INFO_H

#include <stdint.h>

#include "class_file/class_access_flags.h"

struct InnerClassesAttributeInfo
{
  uint16_t inner_class_info_index;
  uint16_t outer_class_info_index;
  uint16_t inner_name_index;
  // this is a uint16_t when parsing class file
  enum ClassAccessFlag inner_class_access_flags;
};

#endif
