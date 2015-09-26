#include "in.h"

void get_int(char *text, int *i)
{
	char str[STRING_LENGHT];
	int ch;
	do {
		printf("%s", text);
		scanf("%31[^\n]", &str);
		__fpurge(stdin);
		ch = sscanf(str, "%i %c", i);
	} while (ch != 1);
}

void get_long(char *text, long long *i)
{
	char str[STRING_LENGHT];
	int ch = 0;
	do {
		printf("%s", text);
		scanf("%31[^\n]", &str);
		__fpurge(stdin);
		ch = sscanf(str, "%lld %c", i);
	} while (ch != 1);
}

void get_size(char *text, size_t *i)
{
	char str[STRING_LENGHT];
	int ch;
	do {
		printf("%s", text);
		scanf("%31[^\n]", &str);
		__fpurge(stdin);
		ch = sscanf(str, "%lld %c", i);
	} while (ch != 1);
}

void get_double(char *text, double *i)
{
	char str[STRING_LENGHT];
	int ch;
	do {
		printf("%s", text);
		scanf("%31[^\n]", &str);
		__fpurge(stdin);
		ch = sscanf(str, "%lf %c", i);
	} while (ch != 1);
}
