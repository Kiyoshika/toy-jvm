#ifndef CONSTANT_POOL_ITEM_H
#define CONSTANT_POOL_ITEM_H

#include "constant_pool/constant_pool_tag.h"
#include "constant_pool/info_structs/class_info.h"
#include "constant_pool/info_structs/double_info.h"
#include "constant_pool/info_structs/field_ref_info.h"
#include "constant_pool/info_structs/float_info.h"
#include "constant_pool/info_structs/integer_info.h"
#include "constant_pool/info_structs/interface_method_ref_info.h"
#include "constant_pool/info_structs/invoke_dynamic_info.h"
#include "constant_pool/info_structs/long_info.h"
#include "constant_pool/info_structs/method_handle_info.h"
#include "constant_pool/info_structs/method_ref_info.h"
#include "constant_pool/info_structs/method_type_info.h"
#include "constant_pool/info_structs/name_and_type_info.h"
#include "constant_pool/info_structs/string_info.h"
#include "constant_pool/info_structs/utf8_info.h"

struct ConstantPoolItem {
  enum ConstantPoolTag tag;
  union item {
    struct ClassInfo class_info;
    struct DoubleInfo double_info;
    struct FieldRefInfo field_ref_info;
    struct FloatInfo float_info;
    struct IntegerInfo integer_info;
    struct InterfaceMethodRefInfo interface_method_ref_info;
    struct InvokeDynamicInfo invoke_dynamic_info;
    struct LongInfo long_info;
    struct MethodHandleInfo method_handle_info;
    struct MethodRefInfo method_ref_info;
    struct MethodTypeInfo method_type_info;
    struct NameAndTypeInfo name_and_type_info;
    struct StringInfo string_info;
    struct Utf8Info utf8_info;
  } item;
};

#endif //CONSTANT_POOL_ITEM_H
