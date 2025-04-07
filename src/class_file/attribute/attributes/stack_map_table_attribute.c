#include "class_file/attribute/attributes/stack_map_table_attribute.h"
#include "class_file/attribute/stack_map_frame/frame_type/frame_type.h"

void StackMapTableAttribute_free(struct StackMapTableAttribute* attribute) {
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
