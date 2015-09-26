#include "functions.h"

int write_base(Note *base, size_t size, const char *name)
{
	printf("Writing database to disk...\t");
	fflush(stdout);
	FILE *f = NULL;
	f = fopen(name, "wb");
	if (f == NULL)
		return -1;
	fwrite(base, sizeof(Note), size, f);
	fflush(f);
	fclose(f);
	printf("OK\n");
	return 0;
}

void print_one(const Note n)
{
	printf("\n\t*** OBJ ***\n");
	printf("Surname:\t%s\n", n.surname);
	printf("Name:\t%s\n", n.name);
	printf("Phone number:\t%u\n", n.phone_number);
	printf("Birthday:\t");
	print_date(n.birthday);
	printf("\n\n");
}


Note *delete_entry(Note *base, size_t *size, const size_t pos)
{
	for(size_t i = pos; i < (*size-1); i++)
		base[i] = base[i+1];
	Note* base_buf = (Note*)realloc(base, sizeof(Note)*(--*size));
	if (base_buf != NULL)
		return base_buf;
	else {
		free(base);
		fprintf(stderr, "Ошибка перевыделения памяти!\n");
		exit(1);
	}
}


Note *add_entry(Note *base, size_t *size, Note e)
{
	Note* base_buf = NULL;

	size_t n_size_b = sizeof(Note)*(++*size);
	base_buf = (Note*)realloc(base, n_size_b);
	if (base_buf != NULL) {
		//base = base_buf;
		base_buf[*size-1] = e;
		return base_buf;
	} else {
		free(base);
		fprintf(stderr, "Ошибка перевыделения памяти!\n");
		exit(2);
	}
}


void sort_base(Note *base, const size_t size)
{
	printf("\nPlease wait...");
	fflush(stdout);
	qsort(base, size, sizeof(Note), compare_names);
	printf("\tOK\n");
}


int compare_names(const void *a, const void *b)
{
	return compare_strings(
				((Note*)a)->name,
				((Note*)b)->name
				);
}


void print_base(const Note *base, const size_t size)
{
	for(size_t i = 0; i < size; i++) {
		system("clear");
		print_one(base[i]);
		char buf = ' ';
		printf("Press \"Enter\" for next or \'q\' for quit...");
		fflush(stdout);
		while (scanf("%c", &buf) != 1 && (
					buf != '\n'
					||
					buf != 'q'))
			__fpurge(stdin);
		if (buf == 'q')
			break;
	}
	printf("\n");
}

Note *find_notes_by_birthday(Note *base, const size_t size, date_t birthday, size_t *count)
{
	*count = 0;
	Note *ret = malloc(sizeof(Note));
	for(size_t i = 0; i < size; i++) {
		if (compare_dates(base[i].birthday, birthday) == 1) {
			*count = *count +1;
			Note *ret_buf = (Note*)realloc(ret, sizeof(Note)*(*count));
			if (ret_buf != NULL) {
				ret = ret_buf;
				ret[*count - 1] = base[i];
			} else {
				free(ret);
				fprintf(stderr, "Ошибка перевыделения памяти!\n");
				exit(3);
			}
		}
	}
	return ret;
}

int compare_strings(char *str1, char *str2)
{
	printf("\n%s : %s\n",str1,str2);
	for (unsigned short i = 0; i < STRING_SIZE; i++) {
		if (str1[i] == '\0' || str2[i] == '\0') {
			break;
			printf("\nEND STR\n");
		}
		if (!compare_symbols(str1[i],str2[i])) {
			continue;
			printf("\nCOMPARED\n");
		} else {
			return 0;
			printf("\nPHYS END STR\n");
		}
	}
	printf("\n WUT?");
	return 1;
}


int compare_dates(const date_t date1, const date_t date2)
{
	//printf("%hu", date1[0]);
	//printf(" = ");
	//printf("%hu", date2[0]);
	//printf("\n");
	if (date1[0] == date2[0]
	    &&
	    date1[1] == date2[1]
	    &&
	    date1[2] == date2[2])
		return 1;
	else
		return 0;
}


void print_date(const date_t date)
{
	printf("%hu-%hu-%hu", date[0], date[1], date[2]);
}

int compare_symbols(char a, char b)
{
	if (a < 97)
		a += 32;
	if (b < 97)
		b += 32;
	//printf("\n%c %i : %c %i\n",a,(int)a,b,(int)b);
	if (a <= b)
		return 1;
	else
		return 0;
}
