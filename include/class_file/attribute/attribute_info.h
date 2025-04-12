#ifndef ATTRIBUTE_INFO_H
#define ATTRIBUTE_INFO_H

#include <stdint.h>

#include "class_file/attribute/attribute_type.h"
#include "class_file/attribute/attributes/annotation_default_attribute.h"
#include "class_file/attribute/attributes/bootstrap_methods_attribute.h"
#include "class_file/attribute/attributes/code_attribute.h"
#include "class_file/attribute/attributes/constant_value_attribute.h"
#include "class_file/attribute/attributes/deprecated_attribute.h"
#include "class_file/attribute/attributes/enclosing_method_attribute.h"
#include "class_file/attribute/attributes/exceptions_attribute.h"
#include "class_file/attribute/attributes/inner_classes_attribute.h"
#include "class_file/attribute/attributes/line_number_table_attribute.h"
#include "class_file/attribute/attributes/local_variable_table_attribute.h"
#include "class_file/attribute/attributes/local_variable_type_table_attribute.h"
#include "class_file/attribute/attributes/method_parameters_attribute.h"
#include "class_file/attribute/attributes/runtime_invisible_annotations_attribute.h"
#include "class_file/attribute/attributes/runtime_invisible_parameter_annotations_attribute.h"
#include "class_file/attribute/attributes/runtime_visible_annotations_attribute.h"
#include "class_file/attribute/attributes/runtime_visible_parameter_annotations_attribute.h"
#include "class_file/attribute/attributes/signature_attribute.h"
#include "class_file/attribute/attributes/source_debug_extension_attribute.h"
#include "class_file/attribute/attributes/source_file_attribute.h"
#include "class_file/attribute/attributes/stack_map_table_attribute.h"
#include "class_file/attribute/attributes/synthetic_attribute.h"
#include "class_file/constant_pool/constant_pool.h"
#include "status/status_code.h"

struct AttributeInfo
{
  enum AttributeType type;
  struct AttributeHeader header;
  union attribute
  {
    struct AnnotationDefaultAttribute annotation_default;
    struct BootstrapMethodsAttribute bootstrap_methods;
    struct CodeAttribute code;
    struct ConstantValueAttribute constant_value;
    struct DeprecatedAttribute deprecated;
    struct EnclosingMethodAttribute enclosing_method;
    struct ExceptionsAttribute exceptions;
    struct InnerClassesAttribute inner_classes;
    struct LineNumberTableAttribute line_number_table;
    struct MethodParametersAttribute method_parameters;
    struct SignatureAttribute signature_attribute;
    struct StackMapTableAttribute stack_map_table;
    struct SyntheticAttribute synthetic;
    struct SourceFileAttribute source_file;
    struct SourceDebugExtensionAttribute source_debug_extension;
    struct LocalVariableTableAttribute local_variable_table;
    struct LocalVariableTypeTableAttribute local_variable_type_table;
    struct RuntimeVisibleAnnotationsAttribute runtime_visible_annotations;
    struct RuntimeInvisibleAnnotationsAttribute runtime_invisible_annotations;
    struct RuntimeVisibleParameterAnnotationsAttribute
      runtime_visible_parameter_annotations;
    struct RuntimeInvisibleParameterAnnotationsAttribute
      runtime_invisible_parameter_annotations;
  } attribute;
};

enum StatusCode
AttributeInfo_parse(struct AttributeInfo* attribute_info,
                    FILE* file,
                    const struct ConstantPool* constant_pool);
void
AttributeInfo_free(struct AttributeInfo* attribute_info);

#endif // ATTRIBUTE_INFO_H
