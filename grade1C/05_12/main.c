#include "functions.h"

int main(void)
{
	char **db  = malloc(sizeof(char*)*MAX_WORDS);
	for (int i = 0; i < MAX_WORDS; i++) {
		db[i] = malloc(sizeof(char)*(MAX_WORD_LENGHT+1));
		db[i][0] = '\0';
	}
	size_t words_count = 0;
	switch (read_file(ask_user_filename(), db, &words_count)) {
	case 0:
		print_db(db, words_count);
		break;
	case -1:
		printf("\nError opening file!\n");
		fflush(stdout);
		break;
	case -2:
		print_full_db(db, words_count);
		printf("\nSomething wrong with file!\n");
		fflush(stdout);
		break;
	default:
		printf("\nWUT?\n");
		fflush(stdout);
		break;
	}

	free_double_array(db, MAX_WORDS);
	return 0;
}
