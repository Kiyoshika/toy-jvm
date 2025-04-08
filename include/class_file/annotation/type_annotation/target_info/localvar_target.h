#ifndef LOCALVAR_TARGET_H
#define LOCALVAR_TARGET_H

#include <stdint.h>

#include "class_file/annotation/type_annotation/target_info/localvar_target_info.h"

struct LocalvarTarget
{
  uint16_t table_length;
  struct LocalvarTargetInfo* table;
};

void
LocalvarTarget_free(struct LocalvarTarget* target);

#endif
