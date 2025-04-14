#include "class_file/attribute/attributes/stack_map_frame/frame_type/frame_type.h"
#include "util/file_util.h"

enum FrameType
FrameType_get(uint8_t value)
{
  if (value >= 0 && value <= 63)
    return FRAME_TYPE_SAME;

  if (value >= 64 && value <= 127)
    return FRAME_TYPE_SAME_LOCALS_1_STACK_ITEM;

  if (value == 247)
    return FRAME_TYPE_SAME_LOCALS_1_STACK_ITEM_EXTENDED;

  if (value >= 248 && value <= 250)
    return FRAME_TYPE_CHOP;

  if (value == 251)
    return FRAME_TYPE_SAME_EXTENDED;

  if (value >= 252 && value <= 254)
    return FRAME_TYPE_APPEND;

  if (value == 255)
    return FRAME_TYPE_FULL;
}
