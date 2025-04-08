#ifndef STACK_MAP_FRAME_H
#define STACK_MAP_FRAME_H

#include "class_file/attribute/attributes/stack_map_frame/frame_type/append_frame.h"
#include "class_file/attribute/attributes/stack_map_frame/frame_type/chop_frame.h"
#include "class_file/attribute/attributes/stack_map_frame/frame_type/full_frame.h"
#include "class_file/attribute/attributes/stack_map_frame/frame_type/same_frame.h"
#include "class_file/attribute/attributes/stack_map_frame/frame_type/same_frame_extended.h"
#include "class_file/attribute/attributes/stack_map_frame/frame_type/same_locals_1_stack_item_frame.h"
#include "class_file/attribute/attributes/stack_map_frame/frame_type/same_locals_1_stack_item_frame_extended.h"

struct StackMapFrame
{
  uint8_t frame_type;
  union type
  {
    struct SameFrameType same_frame;
    struct SameLocals1StackItemFrameType same_locals_1_stack_item_frame;
    struct SameLocals1StackItemFrameExtendedType
      same_locals_1_stack_item_frame_extended;
    struct ChopFrameType chop_frame;
    struct SameFrameExtendedType same_frame_extended;
    struct AppendFrameType append_frame;
    struct FullFrameType full_frame;
  } type;
};

void
stack_map_frame_free(struct StackMapFrame* frame);

#endif
