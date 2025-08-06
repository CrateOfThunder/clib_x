/* ---------------------------------------------------------------- */
/* C Vector                                                         */
/*          cvector.c -- generic c++ vector implementation          */
/* Ver. 1.00                  09AUG2024              CrateOfThunder */
/* ---------------------------------------------------------------- */
#include "cvector.h"

/* Initialize vector */
void v_init(Vec *v, size_t es)
{
  v->s = 0;
  v->c = 4;
  v->es = es;
  v->d = malloc(es * v->c);

  if (v->d == NULL) {
    fprintf(stderr, "v_init: alloc error\n");
    exit(EXIT_FAILURE);
  }

  return;
}

/* Free vector memory */
void v_free(Vec *v)
{
  free(v->d);
  v->d = NULL;
  v->s = 0;
  v->c = 0;
  v->es = 0;
  return;
}

/* Resize vector */
static void v_resize(Vec *v, size_t nc)
{
  void *nd = realloc(v->d, v->es * nc);

  if (nd == NULL) {
    fprintf(stderr, "v_resize: alloc error\n");
    exit(EXIT_FAILURE);
  }

  v->d = nd;
  v->c = nc;
  return;
}

/* Append element */
void v_push(Vec *v, const void *val)
{
  if (v->s >= v->c) { v_resize(v, v->c * 2); }

  memcpy((char *)v->d + v->s * v->es, val, v->es);
  v->s++;
  return;
}

/* Get element */
void *v_get(Vec *v, size_t i)
{
  if (i >= v->s) {
    fprintf(stderr, "v_get: index error\n");
    exit(EXIT_FAILURE);
  }

  return (char *)v->d + i * v->es;
}

/* Set element */
void v_set(Vec *v, size_t i, const void *val)
{
  if (i >= v->s) {
    fprintf(stderr, "v_set: index error\n");
    exit(EXIT_FAILURE);
  }

  memcpy((char *)v->d + i * v->es, val, v->es);
  return;
}

/* Insert element */
void v_ins(Vec *v, size_t i, const void *val)
{
  if (i > v->s) {
    fprintf(stderr, "v_ins: index error\n");
    exit(EXIT_FAILURE);
  }

  if (v->s >= v->c) { v_resize(v, v->c * 2); }

  memmove((char *)v->d + (i + 1) * v->es, 
          (char *)v->d + i * v->es, 
          (v->s - i) * v->es);
  memcpy((char *)v->d + i * v->es, val, v->es);
  v->s++;
  return;
}

/* Erase element */
void v_erase(Vec *v, size_t i)
{
  if (i >= v->s) {
    fprintf(stderr, "v_erase: index error\n");
    exit(EXIT_FAILURE);
  }

  memmove((char *)v->d + i * v->es, 
          (char *)v->d + (i + 1) * v->es, 
          (v->s - i - 1) * v->es);
  v->s--;
  return;
}

/* Get vector size */
size_t v_size(Vec *v) { return v->s; }

/* Get vector capacity */
size_t v_cap(Vec *v) { return v->c; }

/* Check if vector is empty */
int v_empty(Vec *v) { return v->s == 0; }

/* Clear vector */
void v_clear(Vec *v) { v->s = 0;  return; }
