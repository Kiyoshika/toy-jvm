#include "class/class_file.h"
#include <assert.h>

static const char* empty_main_class_path = "../../resources/compiled_class_files/EmptyMain.class";

int main() {
  struct ClassFile class_file;
  assert(class_file_read(empty_main_class_path, &class_file) == STATUS_OK);

  assert(class_file.magic_number == 0xCAFEBABE);

  // Java8 is 52.0
  assert(class_file.minor_version == 0u);
  assert(class_file.major_version == 52u);

  assert(class_file.constant_pool_count == 15u);
	return 0;
}