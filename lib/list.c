#include "list.h"

#include <string.h>

list list_empty() {
    size_t *head = malloc(sizeof(size_t) * 3);
    head[0] = 0;
    head[1] = 0;
    return (head + 2);
}

size_t list_len(list l) {
    return ((size_t*)l)[-2];
}

size_t list_alloc(list l) {
    return ((size_t*)l)[-1];
}

static size_t *l_len(list l) {
    return ((size_t*)l) - 2;
}

static size_t *l_alloc(list l) {
    return ((size_t*)l) - 1;
}

static void l_realloc(list l, size_t size, size_t datasize) {
    size_t *head = l_len(l);
    size_t *tmp = realloc(head, sizeof(size_t) * 2 + (size * datasize));
    if(tmp) {
        l = (tmp + 2);
        ((size_t*)tmp)[1] = size;
    }
}

list list_bytes(size_t size, size_t datasize) {
    list *l = list_empty();
    l_realloc(l, size, datasize);
    *l_len(l) = size;
    return l;
}

void* list_fit(list l, size_t datasize) {
    if(list_len(l) == list_alloc(l)) {
        l_realloc(l, list_alloc(l) * 2 + 1, datasize);
    }
    return (l + (++*l_len(l) - 1) * datasize);
}

void* list_fit_insert(list l, size_t index, size_t datasize) {
    if(list_len(l) == list_alloc(l)) {
        l_realloc(l, list_alloc(l) * 2 + 1, datasize);
    }
    memmove(l + (index + 1) * datasize, l + index * datasize, (list_len(l) - index) * datasize);
    ++*l_len(l);
    return l + index * datasize;
}

void list_backtrack(char *l, size_t index, size_t datasize) {
    memmove(l + index * datasize, l + (index + 1) * datasize, (list_len(l) - index) * datasize);
    --*l_len(l);
}

void list_free(list l) {
    free(l_len(l));
}
