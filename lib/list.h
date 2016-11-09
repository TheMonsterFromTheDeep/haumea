#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef void *list;

list list_empty(void);
size_t list_len(list);
size_t list_alloc(list);

list list_bytes(size_t,size_t);
void *list_fit(list,size_t);
void *list_fit_insert(list,size_t,size_t);

void list_free(list);

#define list_of(type,size) list_bytes(size, sizeof(type));

#define list_set(type,list,index,value) ((type*)list)[index] = value
#define list_get(type,list,index) (((type*)list)[index])

#define list_add(type,list,value) *((type*)list_fit(list,sizeof(type))) = value
#define list_insert(type,list,index,value) *((type*)list_fit_insert(list,index,sizeof(type))) = value
#define list_remove(type,list,index) list_backtrack(list,index,sizeof(type))

/*#define LIST(type) list_ ## type
#define L(type) list_ ## type *
#define FUNC(type,name) list_ ## type ## _ ## name

#define INIT(name,type,nsize) \
    L(type) name = malloc(sizeof(LIST(type))); \
    name->data = (nsize == 0) ? NULL : malloc(sizeof(type) * nsize); \
    name->size = nsize; \
    name->alloc = nsize;

#define MAKE_LIST_STRUCT(type) \
    typedef struct LIST(type) { \
        type *data; \
        size_t size; \
        size_t alloc; \
    } LIST(type);

#define MAKE_LIST_EMPTY(type) \
    L(type) FUNC(type,empty)(void) { \
        INIT(list,type,0) \
        return list; \
    }

#define MAKE_LIST_SIZE(type) \
    L(type) FUNC(type,fromsize)(size_t size) { \
        INIT(list,type,size) \
        return list; \
    }

#define MAKE_LIST_ALLOC(type) \
    int FUNC(type,alloc)(L(type) list, size_t size) { \
        if(list == NULL) { return; } \
        type *tmp = realloc(list->data, sizeof(type) * (list->alloc + size)); \
        if(tmp == NULL) { return 0; } \
        list->data = tmp; \
        list->alloc += size; \
        return 1; \
    }

#define TRY_EXPAND(type,list) if(!FUNC(type,alloc)(list, list->alloc * 2 + 1))

#define MAKE_LIST_ADD(type) \
    int FUNC(type,add)(L(type) list, type item) { \
        if(list->size == list->alloc) { \
            TRY_EXPAND(type,list) { return 0; } \
        } \
        list->data[list->size++] = item; \
        return 1; \
    }

#define MAKE_LIST_INSERT(type) \
    int FUNC(type,insert)(L(type) list, size_t index, type item) { \
        if(index > list->size) { return 0; } \
        if(list->size == list->alloc) { \
            TRY_EXPAND(type,list) { return 0; } \
        } \
        size_t i; \
        for(i = list->size; i > index; --i) { \
            list->data[i] = list->data[i - 1]; \
        } \
        list->data[index] = item; \
        ++list->size; \
        return 1; \
    }

#define MAKE_LIST_REMOVE(type) \
    int FUNC(type,remove)(L(type) list, size_t index) { \
        if(index > list->size) { return 0; } \
        size_t i; \
        for(i = index; i < list->size; ++i) { \
            list->data[i] = list->data[i + 1]; \
        } \
        --list->size; \
        return 1; \
    }

#define MAKE_LIST_FREE(type) \
    void FUNC(type,free)(L(type) list) { \
        if(list == NULL) { return; } \
        free(list->data); \
        free(list); \
    }

#define MAKE_LIST(type) \
    MAKE_LIST_STRUCT(type); \
    MAKE_LIST_EMPTY(type); \
    MAKE_LIST_SIZE(type); \
    MAKE_LIST_ALLOC(type); \
    MAKE_LIST_ADD(type); \
    MAKE_LIST_INSERT(type); \
    MAKE_LIST_REMOVE(type); \
    MAKE_LIST_FREE(type);

#undef LIST
#undef L
#undef FUNC
#undef TRY_EXPAND*/

#endif
