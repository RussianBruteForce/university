#ifndef FUNC_H
#define FUNC_H

#include <stdio_ext.h>
#include <stdlib.h>
#include <malloc.h>
#include "aeroflot.h"
#include "../in.h"

void print_one(Aeroflot o);
void print_base(Aeroflot *base, const size_t size);
int write_base(Aeroflot *base, size_t size, const char *name);
int compare_names(const void * a, const void * b);
int compare_strings(const char *str1, const char *str2);
void sort_base(Aeroflot *base, const size_t size);
Aeroflot* find_flights_by_destination(Aeroflot *base, const size_t size, const char *str, size_t *count);
Aeroflot* delete_entry(Aeroflot *base, size_t *size, const size_t pos);
Aeroflot* add_entry(Aeroflot *base, size_t *size, Aeroflot e);

#endif // FUNC_H
