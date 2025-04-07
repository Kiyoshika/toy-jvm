#ifndef FULL_FRAME_H
#define FULL_FRAME_H

#include <stdlib.h>
#include <stdint.h>

#include "class_file/attribute/stack_map_frame/verification_type_info.h"

struct FullFrameType {
  uint8_t frame_type;
  uint16_t offset_delta;
  
  uint16_t number_of_locals;
  union VerificationTypeInfo* locals;

  uint16_t number_of_stack_items;
  union VerificationTypeInfo* stack;
};

void full_frame_init(struct FullFrameType* frame);
void full_frame_free(struct FullFrameType* frame);

#endif
