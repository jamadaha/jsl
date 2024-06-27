#include <memory.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct jsl_vec {
    size_t size;
    size_t capacity;
    size_t element_size;
    char  *buffer;
};

#define vec_ptr(v) ((struct jsl_vec *)((char *)(v) - offsetof(struct jsl_vec, buffer)))
#define vec_size(v) (vec_ptr(v)->size)
#define vec_capacity(v) (vec_ptr(v)->capacity)
#define vec_front(v) (v[0])
#define vec_back(v) (v[vec_size(v) - 1])
#define vec_push(v, e) (jsl_vec_may_grow(v), (v)[vec_ptr(v)->size++] = e)
#define vec_pop(v) (vec_ptr(v)->size--, v[vec_ptr(v)->size])
#define vec_clear(v) (vec_ptr(v)->size = 0)
#define vec_shrink(v) ((v) = vec_realloc(v, vec_size(v)))

#define jsl_vec_may_grow(v)                                                                        \
    (vec_size(v) >= vec_capacity(v) ? (v) = vec_realloc(v, vec_capacity(v) * vec_capacity(v)) : 0)

static inline void *vec_alloc(size_t capacity, size_t element_size) {
    struct jsl_vec *p = (struct jsl_vec *)malloc(sizeof(struct jsl_vec) + capacity * element_size);
    if (!p) abort();
    p->size         = 0;
    p->capacity     = capacity;
    p->element_size = element_size;
    p->buffer       = NULL;
    return &p->buffer;
}

static inline void *vec_realloc(void *ptr, size_t capacity) {
    struct jsl_vec *p_old = vec_ptr(ptr);
    struct jsl_vec *p     = realloc(p_old, sizeof(struct jsl_vec) + capacity * p_old->element_size);
    if (!p) {
        free(p_old);
        abort();
    }
    p->capacity = capacity;
    return &p->buffer;
}

static inline void vec_reverse(void *ptr) {
    struct jsl_vec *p   = vec_ptr(ptr);
    void           *tmp = malloc(p->element_size);
    if (!tmp) abort();
    for (size_t i = 0; i < p->size / 2; i++) {
        void *a = ptr + i * p->element_size;
        void *b = ptr + (p->size - i - 1) * p->element_size;
        memcpy(tmp, a, p->element_size);
        memcpy(a, b, p->element_size);
        memcpy(b, tmp, p->element_size);
    }
    free(tmp);
}

static inline void vec_free(void *ptr) {
    struct jsl_vec *p = vec_ptr(ptr);
    free(p);
}
