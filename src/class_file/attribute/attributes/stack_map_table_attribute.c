#include "class_file/attribute/attributes/stack_map_table_attribute.h"
#include "class_file/attribute/attributes/stack_map_frame/frame_type/frame_type.h"
#include "util/file_util.h"

enum StatusCode
StackMapTableAttribute_parse(struct StackMapTableAttribute* attribute,
                             FILE* file)
{
  if (!attribute || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute->header, file)) != STATUS_OK)
    return status;

  if ((status = _read_u16_from_file(file, &attribute->number_of_entries)) !=
      STATUS_OK)
    return status;

  if (attribute->number_of_entries > 0) {
    attribute->entries =
      calloc(attribute->number_of_entries, sizeof(struct StackMapFrame));
    if (!attribute->entries)
      return STATUS_NO_MEM;

    for (uint16_t i = 0; i < attribute->number_of_entries; ++i)
      if ((status = StackMapFrame_parse(&attribute->entries[i], file)) !=
          STATUS_OK)
        return status;
  } else
    attribute->entries = NULL;

  return status;
}

void
StackMapTableAttribute_free(struct StackMapTableAttribute* attribute)
{
  if (!attribute)
    return;

  for (size_t i = 0; i < attribute->number_of_entries; ++i) {
    struct StackMapFrame* entry = &attribute->entries[i];
    enum FrameType frame_type = frame_type_get(entry->frame_type);
    // only the frame types that dynamically allocate need to be explicitly
    // free'd
    switch (frame_type) {
      case FRAME_TYPE_FULL:
        full_frame_free(&entry->type.full_frame);
        break;
      default:
        break;
    }
  }
}
