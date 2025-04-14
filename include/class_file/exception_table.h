#ifndef EXCEPTION_TABLE_H
#define EXCEPTION_TABLE_H

#include <stdint.h>
#include <stdio.h>

#include "status/status_code.h"

struct ExceptionTable
{
  uint16_t start_pc;
  uint16_t end_pc;
  uint16_t handler_pc;
  uint16_t catch_type;
};

enum StatusCode
ExceptionTable_parse(struct ExceptionTable* exception_table, FILE* file);

#endif
