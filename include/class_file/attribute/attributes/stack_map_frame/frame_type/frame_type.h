#ifndef FRAME_TYPE_H
#define FRAME_TYPE_H

#include <stdint.h>

enum FrameType
{
  FRAME_TYPE_SAME,                              /* 0-63 */
  FRAME_TYPE_SAME_LOCALS_1_STACK_ITEM,          /* 64-127 */
  FRAME_TYPE_SAME_LOCALS_1_STACK_ITEM_EXTENDED, /* 247 */
  FRAME_TYPE_CHOP,                              /* 248-250 */
  FRAME_TYPE_SAME_EXTENDED,                     /* 251 */
  FRAME_TYPE_APPEND,                            /* 252-254 */
  FRAME_TYPE_FULL                               /* 255 */
};

enum FrameType
frame_type_get(uint8_t value);

#endif
