#ifndef CHOP_FRAME_H
#define CHOP_FRAME_H

#include <stdint.h>

struct ChopFrameType {
  uint8_t frame_type;
  uint16_t offset_delta;
};

#endif
