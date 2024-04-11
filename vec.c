#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

//create vec
vec_t *new_vec()
{
  return (vec_t*)malloc(sizeof(vec_t));
}

//build vec
void vec_cst(vec_t *vec)
{
  vec->items = calloc(DEF_CAPACITY, sizeof(size_t));
  vec->capacity = DEF_CAPACITY;
  vec->size = 0;
}

//free vec
void vec_free(vec_t *vec)
{
  free(vec->items);
  free(vec);
}

//get capacity
void vec_capacity(vec_t *vec)
{
  printf("Vec capacity: %d\n",vec->capacity);
}

//get size
void vec_size(vec_t *vec)
{
  printf("Vec size: %d\n" ,vec->size);
}

void vec_push(struct vec_t *vec, const int item)
{
  //Verify size 
  if(vec->size > 0 && vec->size % vec->capacity == 0){
	vec->capacity = (vec->size / DEF_CAPACITY + 1) * DEF_CAPACITY;
	vec->items = realloc(vec->items, vec->capacity * sizeof(int));
	printf("Realloc size %d\n", vec->capacity);
  }
  //Add items
  vec->items[vec->size++] = item;
}

void vec_item(vec_t *vec, int index)
{
  printf("Value on index: %d, value: %d\n" ,index, vec->items[index]);
}

int vec_begin(vec_t *vec)
{
  return vec->items[0];
}

int vec_end(vec_t *vec)
{
  return vec->size;
}



