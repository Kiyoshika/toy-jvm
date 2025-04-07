#ifndef SAME_LOCALS_1_STACK_ITEM_FRAME_H
#define SAME_LOCALS_1_STACK_ITEM_FRAME_H

#include <stdint.h>

#include "class_file/attribute/stack_map_frame/verification_type_info.h"

struct SameLocals1StackItemFrameType {
  uint8_t frame_type;
  union VerificationTypeInfo stack[1];
};

#endif
