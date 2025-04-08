#include "class_file/attribute/attributes/stack_map_frame/frame_type/full_frame.h"

void
full_frame_free(struct FullFrameType* frame)
{
  if (!frame)
    return;

  free(frame->locals);
  frame->locals = NULL;

  free(frame->stack);
  frame->stack = NULL;
}
