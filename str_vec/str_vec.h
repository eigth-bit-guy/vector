#ifndef STR_VEC
#define STR_VEC

#define INIT_CAPACITY 8

#define VECTOR_INIT(vec) vector vec; vector_init(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (void *) item)
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (void *) item)
#define VECTOR_GET(vec, type, id) (type) vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct {
  void **strings;
  int capacity;
  int total;
}str_vec;

void vector_init(str_vec *);
int vector_total(str_vec *);
static void vector_resize(str_vec *, int);
void vector_add(str_vec *, void *);
void vector_set(str_vec *, int, void *);
void *vector_get(str_vec *, int);
void vector_delete(str_vec *, int);
void vector_free(str_vec *);

#endif
