#ifndef VEC_H
#define VEC_H
#include <stdlib.h>

#define DEF_CAPACITY 4

typedef struct vec_t{
  int *items;
  int capacity;
  int size;
}vec_t;

vec_t *new_vec();
void vec_cst(vec_t *vec);
void vec_size(vec_t *vec);
void vec_capacity(vec_t *vec);
void vec_free(vec_t *vec);
void vec_push(vec_t *vec, const int items);
void vec_item(vec_t *vec, int index);
int vec_begin(vec_t *vec);
int vec_end(vec_t *vec);

#endif
