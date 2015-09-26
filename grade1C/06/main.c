#include <stdio.h>
#include "func.h"

char *ask_where_to_save()
{
	char *ret[STRING_SIZE];
	printf("\nEnter where to save database.\n>");
	__fpurge(stdin);
	scanf("%s", ret);
	__fpurge(stdin);
	return ret;
}

char *ask_what_to_load()
{
	char *ret[STRING_SIZE];
	printf("\nEnter file name to load.\n>");
	__fpurge(stdin);
	scanf("%s", ret);
	__fpurge(stdin);
	return ret;
}

void print_menu()
{
	printf("Those actions available:\n");
	printf("\t'a' for add new entry;\n");
	printf("\t'd' for delete entry;\n");
	printf("\t'v' for print all entries;\n");
	printf("\t'f' for find all flights to destination;\n");
	printf("\t's' for write to disk;\n");
	printf("\t'q' for exit.\n");
}

Aeroflot ask_one()
{
	int buf;
	Aeroflot ret;
	do {
		printf("Введите название пункта назначения: ");
		buf = scanf("%s", ret.destination);
		__fpurge(stdin);
	} while (buf != 1);
	do {
		get_long("Введите номер рейса: ", &ret.flight_number);
	} while (ret.flight_number < 0);
	do {
		printf("Введите тип самолёта: ");
		buf = scanf("%s", ret.aircraft_type);
		__fpurge(stdin);
	} while (buf != 1);
	do {
		get_long("Введите количество занятых мест: ", &ret.employed_seats);
	} while (ret.employed_seats < 0);
	do {
		get_long("Введите общее количество мест: ", &ret.seats);
	} while (ret.seats < ret.employed_seats);
	return ret;
}


unsigned long ask_delete_entry(const unsigned long size)
{
	system("clear");
	char str[STRING_LENGHT];
	long long e = 0;
	int ch;
	do {
		printf("\nIn database %lu entries...\n\tWhich one you want to delete?\n\t>", size);
		scanf("%255[^\n]", &str);
		__fpurge(stdin);
		ch = sscanf(str, "%lld %c", &e, NULL);
	} while (ch != 1 || e < 1 || e > size);
	return e - 1;
}

int main(void)
{
	Aeroflot* base = NULL;
	size_t s = 0;
	FILE *f = NULL;
	f = fopen(ask_what_to_load(), "rb");
	if (f == NULL)
		return -1;

	fseek(f , 0 , SEEK_END);
	size_t basefile_size = ftell(f);
	printf("\nSIZE %lu\n", basefile_size);
	rewind(f);

	base = (Aeroflot*)malloc(sizeof(char*)*basefile_size);
	if (base == NULL) {
		fputs("Memory error", stderr);
		if(f)
			fclose(f);
		return 1;
	}

	size_t result = fread(base, 1, basefile_size, f);
	if (result != basefile_size) {
		fputs ("Reading error", stderr);
		if(f)
			fclose(f);
		if(base)
			free(base);
		return 1;
	}

	fclose (f);
	s = basefile_size/sizeof(Aeroflot);
	printf("\n*** Data file read succes ***\n\t%lu entry readed.\n", s);

	char ch = ' ';
	size_t st, fbase_size;
	Aeroflot *fbase = NULL;
	do {
		printf("ds");
		__fpurge(stdin);
		system("clear");
		print_menu();
		switch (ch) {
		case 'a':
		case 'A':
			system("clear");
			add_entry(base, &s, ask_one());
			break;
		case 'd':
		case 'D':
			system("clear");
			st = ask_delete_entry(s);
			printf("\nd x");
			delete_entry(base, &s, st);
			break;
		case 'v':
		case 'V':
			sort_base(base, s);
			system("clear");
			print_base(base, s);
			break;
		case 'f':
		case 'F':
			sort_base(base, s);
			fbase = find_flights_by_destination(base,s,"rrr",&fbase_size);
			print_base(fbase, fbase_size);
			//free(fbase);
			break;
		case 's':
		case 'S':
			system("clear");
			sort_base(base, s);
			write_base(base, s, ask_where_to_save());
			break;
		case 'q':
		case 'Q':
			system("clear");
			printf("\nExiting...\n");
			fflush(stdout);
			free(base);
			return 0;
			break;
		default:
		break;
		}
	}
	while (scanf("%c", &ch));
	return 0;
}
