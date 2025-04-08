#include "class_file/attribute/attribute_info.h"

void
attribute_info_free(struct AttributeInfo* attribute_info)
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
      MethodParametersAttributes_free(
        &attribute_info->attribute.method_parameters);
      break;
    // any other attribute types that don't dynamically allocate, it's a no-op
    default:
      break;
  }
}
