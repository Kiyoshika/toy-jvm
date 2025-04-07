#include "class_file/class_file.h"
#include "class_file/class_access_flags.h"
#include <assert.h>

static const char* empty_main_class_path = "test/resources/compiled_class_files/EmptyMain.class";

int main() {
  struct ClassFile class_file;
  assert(class_file_read(empty_main_class_path, &class_file) == STATUS_OK);

  assert(class_file.magic_number == 0xCAFEBABE);

  // Java8 is 52.0
  assert(class_file.minor_version == 0u);
  assert(class_file.major_version == 52u);

  assert(class_file.constant_pool_count == 15u);
  assert(class_file.constant_pool.length == 14u);

  // validate constant pool

  // Entry 1: Method Ref (index 1)
  struct ConstantPoolItem* item = &class_file.constant_pool.items[0];
  assert(item->tag == CONSTANT_POOL_METHOD_REF);
  assert(item->item.method_ref_info.class_index == 3u);
  assert(item->item.method_ref_info.name_and_type_index == 12u);

  // Entry 2: Class (index 2)
  item = &class_file.constant_pool.items[1];
  assert(item->tag == CONSTANT_POOL_CLASS);
  assert(item->item.class_info.name_index == 13u);

  // Entry 3: Class (index 3)
  item = &class_file.constant_pool.items[2];
  assert(item->tag == CONSTANT_POOL_CLASS);
  assert(item->item.class_info.name_index == 14u);

  // Entry 4: Utf8 <init> (index 4)
  item = &class_file.constant_pool.items[3];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "<init>") == 0);
  assert(item->item.utf8_info.length == 6u);

  // Entry 5: Utf8 ()V (index 5)
  item = &class_file.constant_pool.items[4];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "()V") == 0);
  assert(item->item.utf8_info.length == 3u);

  // Entry 6: Utf8 Code (index 6)
  item = &class_file.constant_pool.items[5];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "Code") == 0);
  assert(item->item.utf8_info.length == 4u);

  // Entry 7: Utf8 LineNumberTable (index 7)
  item = &class_file.constant_pool.items[6];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "LineNumberTable") == 0);
  assert(item->item.utf8_info.length == 15u);

  // Entry 8: Utf8 main (index 8)
  item = &class_file.constant_pool.items[7];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "main") == 0);
  assert(item->item.utf8_info.length == 4u);

  // Entry 9: Utf8 ([Ljava/lang/String;)V (index 9)
  item = &class_file.constant_pool.items[8];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "([Ljava/lang/String;)V") == 0);
  assert(item->item.utf8_info.length == 22u);

  // Entry 10: Utf8 SourceFile (index 10)
  item = &class_file.constant_pool.items[9];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "SourceFile") == 0);
  assert(item->item.utf8_info.length == 10u);

  // Entry 11: Utf8 EmptyMain.java (index 11)
  item = &class_file.constant_pool.items[10];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "EmptyMain.java") == 0);
  assert(item->item.utf8_info.length == 14u);

  // Entry 12: NameAndType <init>:()V (index 12)
  item = &class_file.constant_pool.items[11];
  assert(item->tag == CONSTANT_POOL_NAME_AND_TYPE);
  assert(item->item.name_and_type_info.name_index == 4u);
  assert(item->item.name_and_type_info.descriptor_index == 5u);

  // Entry 13: Utf8 EmptyMain (index 13)
  item = &class_file.constant_pool.items[12];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "EmptyMain") == 0);
  assert(item->item.utf8_info.length == 9u);

  // Entry 14: Utf8 java/lang/Object (index 14)
  item = &class_file.constant_pool.items[13];
  assert(item->tag == CONSTANT_POOL_UTF8);
  assert(strcmp(item->item.utf8_info.bytes, "java/lang/Object") == 0);
  assert(item->item.utf8_info.length == 16u);

  // this is a public class
  assert((class_file.access_flags & CLASS_ACC_PUBLIC) > 0);
  // not an enum
  assert((class_file.access_flags & CLASS_ACC_ENUM) == 0);

  assert(class_file.this_class == 2u); // points to "EmptyMain" class info index
  assert(class_file.super_class == 3u); // points to "Object" class info index

  // no interfaces
  assert(class_file.interfaces_count == 0u);

  // no fields
  assert(class_file.fields_count == 0u);

  class_file_free(&class_file);
  return 0;
}
