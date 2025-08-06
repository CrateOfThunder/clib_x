/* ---------------------------------------------------------------- */
/* C Vector                                                         */
/*          cvector.h -- generic c++ vector implementation          */
/* Ver. 1.00                  09AUG2024              CrateOfThunder */
/* ---------------------------------------------------------------- */
#ifndef _CVECTOR_H
#define _CVECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the dynamic array structure */
typedef struct {
  void *d;   /* data */
  size_t s;  /* size */
  size_t c;  /* capacity */
  size_t es; /* elem_size */
} Vec;

/* Initialize vector */
void v_init(Vec *v, size_t es);

/* Free vector memory */
void v_free(Vec *v);

/* Resize vector */
static void v_resize(Vec *v, size_t nc);

/* Append element */
void v_push(Vec *v, const void *val);

/* Get element */
void *v_get(Vec *v, size_t i);

/* Set element */
void v_set(Vec *v, size_t i, const void *val);

/* Insert element */
void v_ins(Vec *v, size_t i, const void *val);

/* Erase element */
void v_erase(Vec *v, size_t i);

/* Get vector size */
size_t v_size(Vec *v);

/* Get vector capacity */
size_t v_cap(Vec *v);

/* Check if vector is empty */
int v_empty(Vec *v);

/* Clear vector */
void v_clear(Vec *v);

#endif
