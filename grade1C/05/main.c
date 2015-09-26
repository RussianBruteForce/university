#include <stdio_ext.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define MAX_FILE_NAME_LENGHT 255

int main(void)
{
	char *f_name = (char *)malloc(MAX_FILE_NAME_LENGHT + 1);
	FILE *f = NULL;
	do {
		printf("\nВведите имя файла со строкой: ");
		while (scanf("%s", f_name) != 1) {
			printf("\nВведите имя файла со строкой: ");
			__fpurge(stdin);
		}
	} while ((f = fopen(f_name,"r")) == NULL);

	char *str = NULL;
	char *str_buf;
	size_t size = 0;//, zero_counter = 0;
	bool add_zero = false;
	while (true) {
		char ch_buf = getc(f);
		if (ch_buf == '\n' || ch_buf == EOF)
			break;
		if (ch_buf == 'w' && !add_zero) {
			add_zero = true;
			continue;
		}
		str_buf = (char*)realloc(str, sizeof(char)*size++);
		if (str_buf != NULL) {
			str = str_buf;
			str[size - 1] = ch_buf;
		} else {
			free(str);
			fprintf(stderr, "Ошибка перевыделения памяти!\n%s",
			        strerror(ENOMEM));
			return 1;
		}
	}
	fclose(f);

	if (add_zero) {
		str_buf = (char*)realloc(str, sizeof(char)* size++);
		if (str_buf != NULL) {
			str = str_buf;
			str[size - 1] = ' ';
		} else {
			free(str);
			fprintf(stderr, "Ошибка перевыделения памяти!\n%s",
			        strerror(ENOMEM));
			return 1;
		}
	}

	printf("\nВведите имя файла для вывода: ");
	do {
		while (scanf("%s", f_name) != 1) {
			printf("\nВведите имя файла для вывода: ");
			__fpurge(stdin);
		}
	} while ((f = fopen(f_name,"w")) == NULL);
	free(f_name);
	printf("\nПосле обработки строка получилась такой:\n>");
	for (size_t i = 0; i < size; i++){
		putchar(str[i]);
		fputc(str[i], f);
	}
	fputc('\n', f);
	printf("<\n");
	fflush(f);
	fclose(f);
	return 0;
}
