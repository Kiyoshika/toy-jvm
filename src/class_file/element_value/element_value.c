#include "class_file/element_value/element_value.h"
#include "class_file/annotation/annotation.h"
#include "util/file_util.h"

enum StatusCode
ElementValue_parse(struct ElementValue* element_value, FILE* file)
{
  if (!element_value || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = _read_u8_from_file(file, (uint8_t*)&element_value->tag)) !=
      STATUS_OK)
    return status;

  switch (element_value->tag) {
    case ELEMENT_VALUE_BYTE:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_CHAR:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_DOUBLE:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_FLOAT:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_INT:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_LONG:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_SHORT:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_BOOLEAN:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_STRING:
      if ((status = _read_u16_from_file(
             file, &element_value->value.const_value_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_ENUM:
      if ((status = ElementValueEnum_parse(
             &element_value->value.enum_const_value, file)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_CLASS:
      if ((status = _read_u16_from_file(
             file, &element_value->value.class_info_index)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_ANNOTATION:
      if ((status = Annotation_parse(&element_value->value.annotation_value,
                                     file)) != STATUS_OK)
        return status;
      break;
    case ELEMENT_VALUE_ARRAY:
      if ((status = ElementValueArray_parse(&element_value->value.array_value,
                                            file)) != STATUS_OK)
        return status;
      break;
  }

  return status;
}
