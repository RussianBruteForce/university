#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio_ext.h>
#include <stdlib.h>
#include <malloc.h>
#include "note.h"
#include "../in.h"

void print_one(const Note n);
void print_base(const Note *base, const size_t size);
void print_date(const date_t date);
int write_base(Note *base, size_t size, const char *name);
int compare_names(const void * a, const void * b);
int compare_strings(char *str1, char *str2);
int compare_symbols(char a, char b);
int compare_dates(const date_t date1, const date_t date2);
void sort_base(Note *base, const size_t size);
Note *find_notes_by_birthday(Note *base, const size_t size, date_t birthday, size_t *count);
Note *delete_entry(Note *base, size_t *size, const size_t pos);
Note *add_entry(Note *base, size_t *size, Note e);

#endif // FUNCTIONS_H
