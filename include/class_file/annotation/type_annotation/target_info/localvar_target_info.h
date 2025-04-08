#ifndef LOCALVAR_TARGET_INFO_H
#define LOCALVAR_TARGET_INFO_H

#include <stdint.h>

struct LocalvarTargetInfo
{
  uint16_t start_pc;
  uint16_t length;
  uint16_t index;
};

#endif
