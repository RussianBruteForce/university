#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "list.h"
#include <malloc.h>
#include <stdlib.h>

typedef enum {
	NoErrors,
	OutOfRange,
	BadMemory,
	NoHead,
	NoTail
} ErrorCode;

void *error_handler(void *error);

List* createL();
void deleteL(List **l);
ErrorCode push_front(List *l, void *data);
ErrorCode push_back(List *l, void *data);
void *pop_front(List *l);
void *pop_back(List *l);
Node *get_at(List *l, size_t at);
ErrorCode insert_at(List *l, size_t at, void *data);
void *delete_at(List *l, size_t at);

void print_list(List *l, void (*print_function)(void*));
void print_int(void *data);
void print_unsigned(void *data);
void print_char(void *data);
void print_string(void *data);

int summ_elements_from(List *l, size_t pos);

#endif //FUNCTIONS_H
