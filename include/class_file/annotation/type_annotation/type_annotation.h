#ifndef TYPE_ANNOTATION_H
#define TYPE_ANNOTATION_H

#include "class_file/annotation/type_annotation/target_info/catch_target.h"
#include "class_file/annotation/type_annotation/target_info/empty_target.h"
#include "class_file/annotation/type_annotation/target_info/formal_parameter_target.h"
#include "class_file/annotation/type_annotation/target_info/localvar_target.h"
#include "class_file/annotation/type_annotation/target_info/offset_target.h"
#include "class_file/annotation/type_annotation/target_info/supertype_target.h"
#include "class_file/annotation/type_annotation/target_info/throws_target.h"
#include "class_file/annotation/type_annotation/target_info/type_argument_target.h"
#include "class_file/annotation/type_annotation/target_info/type_parameter_target.h"
#include "class_file/annotation/type_annotation/type_annotation_target_type.h"
#include "class_file/annotation/type_annotation/type_annotation_target_type_location.h"
#include "class_file/element_value_pair.h"
#include "class_file/type_annotation_target_type.h"

struct TypeAnnotation
{
  uint8_t target_type_value;
  enum TypeAnnotationTargetType target_type;
  enum TypeAnnotationTargetTypeLocation target_type_location;
  union target_info
  {
    struct TypeParameterBoundTarget type_parameter_bound_target;
    struct TypeParameterTarget type_parameter_target;
    struct SupertypeTarget supertype_target;
    struct EmptyTarget empty_target;
    struct FormalParameterTarget formal_parameter_target;
    struct ThrowsTarget throws_target;
    struct LocalvarTarget localvar_target;
    struct CatchTarget catch_target;
    struct OffsetTarget offset_target;
    struct TypeArgumentTarget type_argument_target;
  } target_info;
  struct TypePath target_path;
  uint16_t type_index;
  uint16_t num_element_value_pairs;
  struct ElementValuePair* element_value_pairs;
};

void
TypeAnnotation_free(struct TypeAnnotation* annotation);

#endif
