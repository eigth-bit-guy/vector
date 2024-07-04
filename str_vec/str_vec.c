#include <stdio.h>
#include <stdlib.h>
#include "str_vec.h"

void vector_init(str_vec *v)
{
  v->capacity = INIT_CAPACITY;
  v->total = 0;
  v->strings = malloc(sizeof(void*) * v->capacity);
}

int vector_total(str_vec *v)
{
  return v->total;
}

static void vector_resize(str_vec *v, int capacity)
{
  void **strings = realloc(v->strings, sizeof(void*) * capacity);
  if(strings){
	v->strings = strings;
	v->capacity = capacity;
  }
}

void vector_add(str_vec *v, void *string)
{
  if(v->capacity == v->total)
	vector_resize(v, v->capacity * 2);
  v->strings[v->total++] = string;
}

void vector_set(str_vec *v, int index, void *string)
{
  if(index >= 0 && index < v->total)
	v->strings[index] = string;
}

void *vector_get(str_vec *v, int index)
{
  if(index >= 0 && index < v->total)
	return v->strings[index];
  return NULL;
}

void vector_delete(str_vec *v, int index)
{
  if(index < 0 || index > v->total)
	return;

  v->strings[index] = NULL;

  for(int i = index; i < v->total; i++){
	v->strings[i] = v->strings[i + 1];
	v->strings[i + 1] = NULL;
  }

  v->total--;

  if(v->total > 0 && v->total == v->capacity / 4)
	vector_resize(v, v->capacity * 2);
  
}

void vector_free(str_vec *v)
{
  free(v->strings);
}
