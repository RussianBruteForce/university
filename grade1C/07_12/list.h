#ifndef LIST
#define LIST

#include <stddef.h>

typedef struct _Node {
    void *data;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct {
    size_t size;
    Node *head;
    Node *tail;
} List;

#endif //LIST
