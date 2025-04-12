#include "class_file/exception_table.h"
#include "util/file_util.h"

enum StatusCode
ExceptionTable_parse(struct ExceptionTable* exception_table, FILE* file)
{
  if (!exception_table || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u16_from_file(file, &exception_table->start_pc)) !=
      STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &exception_table->end_pc)) !=
      STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &exception_table->handler_pc)) !=
      STATUS_OK)
    return status;

  if ((status - _read_u16_from_file(file, &exception_table->catch_type)) !=
      STATUS_OK)
    return status;

  return status;
}
