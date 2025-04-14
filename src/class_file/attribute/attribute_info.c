#include "class_file/attribute/attribute_info.h"
#include "class_file/attribute/attributes/annotation_default_attribute.h"
#include <string.h>

static enum StatusCode
_parse_attribute_type(struct AttributeInfo* attribute_info,
                      const struct Utf8Info* utf8_info,
                      const struct ConstantPool* constant_pool,
                      FILE* file)
{
  enum StatusCode status = STATUS_OK;

  const char* attribute_name = utf8_info->bytes;

  // TODO: worth it to use bsearch? We don't have many items... would need perf
  // testing

  if (strncmp(attribute_name, "AnnotationDefault", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_ANNOTATION_DEFAULT;
    return AnnotationDefaultAttribute_parse(
      &attribute_info->attribute.annotation_default, file);
  }

  if (strncmp(attribute_name, "BootstrapMethods", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_BOOTSTRAP_METHODS;
    return BootstrapMethodsAttribute_parse(
      &attribute_info->attribute.bootstrap_methods, file);
  }

  if (strncmp(attribute_name, "Code", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_CODE;
    return CodeAttribute_parse(
      &attribute_info->attribute.code, file, constant_pool);
  }

  if (strncmp(attribute_name, "ConstantVaue", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_CONSTANT_VALUE;
    return ConstantValueAttribute_parse(
      &attribute_info->attribute.constant_value, file);
  }

  if (strncmp(attribute_name, "Deprecated", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_DEPRECATED;
    return DeprecatedAttribute_parse(&attribute_info->attribute.deprecated,
                                     file);
  }

  if (strncmp(attribute_name, "EnclosingMethod", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_ENCLOSING_METHOD;
    return EnclosingMethodAttribute_parse(
      &attribute_info->attribute.enclosing_method, file);
  }

  if (strncmp(attribute_name, "Exceptions", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_EXCEPTIONS;
    return ExceptionsAttribute_parse(&attribute_info->attribute.exceptions,
                                     file);
  }

  if (strncmp(attribute_name, "InnerClasses", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_INNER_CLASSES;
    return InnerClassesAttribute_parse(&attribute_info->attribute.inner_classes,
                                       file);
  }

  if (strncmp(attribute_name, "LineNumberTable", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_LINE_NUMBER_TABLE;
    return LineNumberTableAttribute_parse(
      &attribute_info->attribute.line_number_table, file);
  }

  if (strncmp(attribute_name, "MethodParameters", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_METHOD_PARAMETERS;
    return MethodParametersAttribute_parse(
      &attribute_info->attribute.method_parameters, file);
  }

  if (strncmp(attribute_name, "Signature", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_SIGNATURE;
    return SignatureAttribute_parse(&attribute_info->attribute.signature, file);
  }

  if (strncmp(attribute_name, "StackMapTable", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_STACK_MAP_TABLE;
    return StackMapTableAttribute_parse(
      &attribute_info->attribute.stack_map_table, file);
  }

  if (strncmp(attribute_name, "Synthetic", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_SYNTHETIC;
    return SyntheticAttribute_parse(&attribute_info->attribute.synthetic, file);
  }

  if (strncmp(attribute_name, "SourceFile", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_SOURCE_FILE;
    return SourceFileAttribute_parse(&attribute_info->attribute.source_file,
                                     file);
  }

  if (strncmp(attribute_name, "SourceDebugExtension", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_SOURCE_DEBUG_EXTENSION;
    return SourceDebugExtensionAttribute_parse(
      &attribute_info->attribute.source_debug_extension, file);
  }

  if (strncmp(attribute_name, "LocalVariableTable", utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_LOCAL_VARIABLE_TABLE;
    return LocalVariableTableAttribute_parse(
      &attribute_info->attribute.local_variable_table, file);
  }

  if (strncmp(attribute_name, "LocalVariableTypeTable", utf8_info->length) ==
      0) {
    attribute_info->type = ATTRIBUTE_TYPE_LOCAL_VARIABLE_TYPE_TABLE;
    return LocalVariableTypeTableAttribute_parse(
      &attribute_info->attribute.local_variable_type_table, file);
  }

  if (strncmp(attribute_name, "RuntimeVisibleAnnotations", utf8_info->length) ==
      0) {
    attribute_info->type = ATTRIBUTE_TYPE_RUNTIME_VISIBLE_ANNOTATIONS;
    return RuntimeVisibleAnnotationsAttribute_parse(
      &attribute_info->attribute.runtime_visible_annotations, file);
  }

  if (strncmp(attribute_name,
              "RuntimeInvisibleAnnotations",
              utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_RUNTIME_INVISIBLE_ANNOTATIONS;
    return RuntimeInvisibleAnnotationsAttribute_parse(
      &attribute_info->attribute.runtime_invisible_annotations, file);
  }

  if (strncmp(attribute_name,
              "RuntimeVisibleParameterAnnotations",
              utf8_info->length) == 0) {
    attribute_info->type = ATTRIBUTE_TYPE_RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS;
    return RuntimeVisibleParameterAnnotationsAttribute_parse(
      &attribute_info->attribute.runtime_visible_parameter_annotations, file);
  }

  if (strncmp(attribute_name,
              "RuntimeInvisibleParameterAnnotations",
              utf8_info->length) == 0) {
    attribute_info->type =
      ATTRIBUTE_TYPE_RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS;
    return RuntimeInvisibleParameterAnnotationsAttribute_parse(
      &attribute_info->attribute.runtime_invisible_parameter_annotations, file);
  }
  // else if ...
  // else (ATTRIBUTE_TYPE_UNKNOWN)

  // TODO: finish this for all remaining attributes.
  // For unknown attributes, we can use the attribute length
  // and skip the text. This is where custom attributes from different
  // compilers can be handled, but this JVM will just ignore them.
  // Maybe log an info message or something

  return status;
}

enum StatusCode
AttributeInfo_parse(struct AttributeInfo* attribute_info,
                    FILE* file,
                    const struct ConstantPool* constant_pool)
{
  if (!attribute_info || !file)
    return STATUS_BAD_ARG;

  enum StatusCode status = STATUS_OK;

  if ((status = AttributeHeader_parse(&attribute_info->header, file)) !=
      STATUS_OK)
    return status;

  const struct ConstantPoolItem* item = constant_pool_get_item(
    constant_pool, attribute_info->header.attribute_name_index);
  if (!item)
    return STATUS_BAD_CLASS_FORMAT;

  // attribute name index must point to a UTF8 info within the constant pool
  const struct Utf8Info* utf8_info = &item->item.utf8_info;
  if (!utf8_info)
    return STATUS_BAD_CLASS_FORMAT;

  if ((status = _parse_attribute_type(
         attribute_info, utf8_info, constant_pool, file)) != STATUS_OK)
    return status;

  return status;
}

void
AttributeInfo_free(struct AttributeInfo* attribute_info)
{
  if (!attribute_info)
    return;

  // for any attribute types with dynamic memory, free them up
  switch (attribute_info->type) {
    case ATTRIBUTE_TYPE_CODE:
      CodeAttribute_free(&attribute_info->attribute.code);
      break;
    case ATTRIBUTE_TYPE_EXCEPTIONS:
      ExceptionsAttribute_free(&attribute_info->attribute.exceptions);
      break;
    case ATTRIBUTE_TYPE_STACK_MAP_TABLE:
      StackMapTableAttribute_free(&attribute_info->attribute.stack_map_table);
      break;
    case ATTRIBUTE_TYPE_INNER_CLASSES:
      InnerClassesAttribute_free(&attribute_info->attribute.inner_classes);
      break;
    case ATTRIBUTE_TYPE_SOURCE_DEBUG_EXTENSION:
      SourceDebugExtensionAttribute_free(
        &attribute_info->attribute.source_debug_extension);
      break;
    case ATTRIBUTE_TYPE_LINE_NUMBER_TABLE:
      LineNumberTableAttribute_free(
        &attribute_info->attribute.line_number_table);
      break;
    case ATTRIBUTE_TYPE_LOCAL_VARIABLE_TABLE:
      LocalVariableTableAttribute_free(
        &attribute_info->attribute.local_variable_table);
      break;
    case ATTRIBUTE_TYPE_LOCAL_VARIABLE_TYPE_TABLE:
      LocalVariableTypeTableAttribute_free(
        &attribute_info->attribute.local_variable_type_table);
      break;
    case ATTRIBUTE_TYPE_RUNTIME_VISIBLE_ANNOTATIONS:
      RuntimeVisibleAnnotationsAttribute_free(
        &attribute_info->attribute.runtime_visible_annotations);
      break;
    case ATTRIBUTE_TYPE_RUNTIME_INVISIBLE_ANNOTATIONS:
      RuntimeInvisibleAnnotationsAttribute_free(
        &attribute_info->attribute.runtime_invisible_annotations);
      break;
    case ATTRIBUTE_TYPE_RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS:
      RuntimeVisibleParameterAnnotationsAttribute_free(
        &attribute_info->attribute.runtime_visible_parameter_annotations);
      break;
    case ATTRIBUTE_TYPE_RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS:
      RuntimeInvisibleParameterAnnotationsAttribute_free(
        &attribute_info->attribute.runtime_invisible_parameter_annotations);
      break;
    case ATTRIBUTE_TYPE_ANNOTATION_DEFAULT:
      AnnotationDefaultAttribute_free(
        &attribute_info->attribute.annotation_default);
      break;
    case ATTRIBUTE_TYPE_BOOTSTRAP_METHODS:
      BootstrapMethodsAttribute_free(
        &attribute_info->attribute.bootstrap_methods);
      break;
    case ATTRIBUTE_TYPE_METHOD_PARAMETERS:
      MethodParametersAttribute_free(
        &attribute_info->attribute.method_parameters);
      break;
    // any other attribute types that don't dynamically allocate, it's a no-op
    default:
      break;
  }
}
