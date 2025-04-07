#ifndef SAME_LOCALS_1_STACK_ITEM_FRAME_EXTENDED_H
#define SAME_LOCALS_1_STACK_ITEM_FRAME_EXTENDED_H

#include <stdint.h>

#include "class_file/attribute/stack_map_frame/verification_type_info.h"

struct SameLocals1StackItemFrameExtendedType {
  uint8_t frame_type;
  uint16_t offset_delta;
  union VerificationTypeInfo stack[1];
};

#endif
