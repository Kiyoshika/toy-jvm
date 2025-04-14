#ifndef ANNOTATION_H
#define ANNOTATION_H

#include <stdint.h>
#include <stdio.h>

struct Annotation
{
  uint16_t type_index;
  uint16_t num_element_value_pairs;
  struct ElementValuePair* element_value_pairs;
};

enum StatusCode
Annotation_parse(struct Annotation* annotation, FILE* file);

void
Annotation_free(struct Annotation* annotation);

#endif
