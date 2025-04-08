#ifndef APPEND_FRAME_H
#define APPEND_FRAME_H

#include <stdint.h>

#include "class_file/attribute/attributes/stack_map_frame/verification_type_info.h"

struct AppendFrameType
{
  uint8_t frame_type;
  uint16_t offset_delta;
  // will be size frame_type - 251, with a maximum size of 3
  uint8_t n_locals;
  union VerificationTypeInfo locals[3];
};

#endif
