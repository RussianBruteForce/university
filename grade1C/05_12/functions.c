#include "functions.h"

int read_file(char *filename, char **db, size_t *words_count)
{
	FILE *f = NULL;
	if ((f = fopen(filename,"r")) == NULL){
		free(filename);
		return -1;
	} else {
		int ch = fgetc(f);
		for (int i = 0; i < MAX_WORDS; i++) {
			if(ch == EOF || ch == '.') {
				free(filename);
				fclose(f);
				return 0;
			}
			if (ch != ' ') {
				++*words_count;
				db[i][0] = ch;
				for (int j = 1; j < MAX_WORD_LENGHT; j++) {
					ch = fgetc(f);
					if (ch != ' ' && ch != '.')
						db[i][j] = ch;
					else
						break;
				}
			} else
				i--;
			ch = fgetc(f);
		}
	}
	free(filename);
	fclose(f);
	return -2;
}

char *ask_user_filename()
{
	char *f_name = (char *)malloc(sizeof(char)*(STRING_LENGHT + 1));
	printf("\nВведите имя файла со строкой: ");
	fflush(stdout);
	while (scanf("%s", f_name) != 1) {
		printf("\nВведите имя файла со строкой: ");
		fflush(stdout);
		__fpurge(stdin);
	}
	return f_name;
}

void print_full_db(char **db, const size_t size)
{
	printf("%u\n", (int)size);
	for (size_t i = 0; i < size; i++) {
		if (db[i][0] != '\0') {
			for (int j = 0; j < MAX_WORD_LENGHT; j++)
				printf("%c", db[i][j]);
			printf("\n");
		} else
			break;
	}
}

void free_double_array(char **db, const size_t size)
{
	for (size_t i = 0; i < size; i++)
		free(db[i]);
	free(db);
}

int is_last_word(char *w, char **db, const size_t size)
{
	for (int i = 0; i < MAX_WORD_LENGHT; i++) {
		if (w[i] != db[size-1][i])
			return 0;
	}
	return 1;
}

int is_symmetric(char *w)
{
	int symbols_count = count_symbols(w);
	for (int i = 0; i < symbols_count/2; i++)
		if (w[i] != w[symbols_count-1-i])
			return 0;
	return 1;
}

int count_symbols(char *w)
{
	int ret = 0;
	while(1)
		if (w[ret++] == '\0')
			return ret-1;
}

void print_db(char **db, const size_t size)
{
	for (int i = 0; i < MAX_WORDS; i++) {
		if (!is_last_word(db[i],db,size)
		    &&
		    is_symmetric(db[i])) {
			if (db[i][0] != '\0') {
				for (int j = 0; j < MAX_WORD_LENGHT; j++)
					printf("%c", db[i][j]);
				printf("\n");
			} else
				break;
		}
	}
}
