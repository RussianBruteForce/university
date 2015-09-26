#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio_ext.h>
#include <malloc.h>

#define STRING_LENGHT 255

#define MAX_WORDS 30
#define MAX_WORD_LENGHT 5

int read_file(char *filename, char **db, size_t *words_count);
char *ask_user_filename();
int is_last_word(char *w, char **db, const size_t size);
int is_symmetric(char *w);
int count_symbols(char *w);
void print_full_db(char **db, const size_t size);
void print_db(char **db, const size_t size);
void free_double_array(char **db, const size_t size);



#endif //FUNCTIONS_H
