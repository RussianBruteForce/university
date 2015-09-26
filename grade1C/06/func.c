#include "func.h"

int write_base(Aeroflot *base, size_t size, const char *name)
{
	printf("Writing database to disk...\t");
	fflush(stdout);
	FILE *f = NULL;
	f = fopen(name, "wb");
	if (f == NULL)
		return -1;
	fwrite(base, sizeof(Aeroflot), size, f);
	fflush(f);
	fclose(f);
	printf("OK\n");
	return 0;
}

void print_one(Aeroflot o)
{
	printf("\n\t*** OBJ ***\n");
	printf("Destination:\t%s\n", o.destination);
	printf("Flight number:\t%u\n", o.flight_number);
	printf("Aircraft type:\t%s\n", o.aircraft_type);
	printf("Employed seats:\t%u\n", o.employed_seats);
	printf("Seats:\t\t%u\n\n", o.seats);
}


Aeroflot *delete_entry(Aeroflot *base, size_t *size, const size_t pos)
{
	for(size_t i = pos; i < (*size-1); i++)
		base[i] = base[i+1];
	Aeroflot* base_buf = (Aeroflot*)realloc(base, sizeof(Aeroflot)*(--*size));
	if (base_buf != NULL) {
		//base = base_buf;
		return base_buf;
	} else {
		free(base);
		fprintf(stderr, "Ошибка перевыделения памяти!\n");
		exit(1);
	}
}


Aeroflot *add_entry(Aeroflot *base, size_t *size, Aeroflot e)
{
	Aeroflot* base_buf = NULL;

	size_t n_size_b = sizeof(Aeroflot)*(++*size);
	base_buf = (Aeroflot*)realloc(base, n_size_b);
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


void sort_base(Aeroflot *base, const size_t size)
{
	printf("\nPlease wait...");
	fflush(stdout);
	qsort(base, size, sizeof(Aeroflot), compare_names);
	printf("\tOK\n");
}


int compare_names(const void *a, const void *b)
{
	return ( ((Aeroflot*)a)->flight_number > ((Aeroflot*)b)->flight_number );
}


void print_base(Aeroflot *base, const size_t size)
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

Aeroflot *find_flights_by_destination(Aeroflot *base, const size_t size, const char *str, size_t *count)
{
	*count = 0;
	Aeroflot *ret = malloc(sizeof(Aeroflot));
	for(size_t i = 0; i < size; i++) {
		if (compare_strings(base[i].destination, str) == 1) {
			*count = *count +1;
			Aeroflot *ret_buf = (Aeroflot*)realloc(ret, sizeof(Aeroflot)*(*count));
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

int compare_strings(const char *str1, const char *str2)
{
	for (unsigned short i = 0; i < STRING_SIZE; i++) {
		if (str1[i] != str2[i])
			return 0;
		else if (str1[i] == '\0')
			return 1;
	}
	printf("\nEmpty string?\n%s\n%s\n", str1, str2);
	return -1;
}
