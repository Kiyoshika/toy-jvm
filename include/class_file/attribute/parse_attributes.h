#ifndef PARSE_ATTRIBUTES_H
#define PARSE_ATTRIBUTES_H

#include <stdio.h>

#include "class_file/class_file.h"
#include "status/status_code.h"

enum StatusCode
parse_attributes(FILE* file, struct ClassFile* class_file);

#endif
