#ifndef TYPE_ANNOTATION_TARGET_TYPE_H
#define TYPE_ANNOTATION_TARGET_TYPE_H

enum TypeAnnotationTargetType
{
  // type_parameter_target
  TARGET_TYPE_PARAMETER,
  // supertype_target
  TARGET_TYPE_SUPERTYPE,
  // type_parameter_bound_target
  TARGET_TYPE_TYPE_PARAMETER_BOUND,
  // empty_target
  TARGET_TYPE_EMPTY,
  // formal_parameter_target
  TARGET_TYPE_FORMAL_PARAMETER,
  // throws_target
  TARGET_TYPE_THROWS,
  // localvar_target
  TARGET_TYPE_LOCALVAR,
  // catch_target
  TARGET_TYPE_CATCH,
  // offset_target
  TARGET_TYPE_OFFSET,
  // type_argument_target
  TARGET_TYPE_TYPE_ARGUMENT
};

#endif
