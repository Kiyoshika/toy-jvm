#ifndef TYPE_PATH_H
#define TYPE_PATH_H

#include "class_file/annotation/type_annotation/type_path_info.h"

struct TypePath
{
  uint8_t path_length;
  struct TypePathInfo* path;
};

#endif
