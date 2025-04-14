#include "class_file/attribute/attributes/stack_map_frame/stack_map_frame.h"
#include "util/file_util.h"

enum StatusCode
StackMapFrame_parse(struct StackMapFrame* frame, FILE* file)
{
  if (!frame || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  uint8_t frame_type_value = 0u;
  if ((status = _read_u8_from_file(file, &frame_type_value)) != STATUS_OK)
    return status;

  frame->frame_type = FrameType_get(frame_type_value);

  switch (frame->frame_type) {
    case FRAME_TYPE_SAME:
      if ((status = SameFrameType_parse(&frame->type.same_frame, file)) !=
          STATUS_OK)
        return status;
      break;
    case FRAME_TYPE_SAME_LOCALS_1_STACK_ITEM:
      if ((status = SameLocals1StackItemFrameType_parse(
             &frame->type.same_locals_1_stack_item_frame, file)) != STATUS_OK)
        return status;
      break;
    case FRAME_TYPE_SAME_LOCALS_1_STACK_ITEM_EXTENDED:
      if ((status = SameLocals1StackItemFrameExtendedType_parse(
             &frame->type.same_locals_1_stack_item_frame_extended, file)) !=
          STATUS_OK)
        return status;
      break;
    case FRAME_TYPE_CHOP:
      if ((status = ChopFrameType_parse(&frame->type.chop_frame, file)) !=
          STATUS_OK)
        return status;
      break;
    case FRAME_TYPE_SAME_EXTENDED:
      if ((status = SameFrameExtendedType_parse(
             &frame->type.same_frame_extended, file)) != STATUS_OK)
        return status;
      break;
    case FRAME_TYPE_APPEND:
      if ((status = AppendFrameType_parse(&frame->type.append_frame, file)) !=
          STATUS_OK)
        return status;
      break;
    case FRAME_TYPE_FULL:
      if ((status = FullFrameType_parse(&frame->type.full_frame, file)) !=
          STATUS_OK)
        return status;
      break;
  }

  return status;
}

void
StackMapFrame_free(struct StackMapFrame* frame)
{
  // TODO:
}
