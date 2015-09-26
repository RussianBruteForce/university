#include <stdio.h>
#include "functions.h"
#include "../in.h"

size_t ask_at(){
	size_t ret;
	get_size("Позиция?\n\t>", &ret);
	printf("\n");
	fflush(stdout);
	return ret;
}

int* ask_what(){
	int *ret = (int*)malloc(sizeof(int));
	get_int("Ведите число:\n\t>", ret);
	printf("\n");
	return ret;
}

int main(void)
{
	List *l = createL();
	do{
		char *error = "";
		size_t pos;
		int *data;
		printf("\t>");
		char ch;
		scanf("%c",&ch);
		__fpurge(stdin);
		switch (ch) {
		case 'a':
			printf("Вставка элемента.\n");
			pos = ask_at();
			data = ask_what();
			error = error_handler((void*)insert_at(l,pos,data));
			break;
		case 'd':
			printf("Удаление элемента.\n");
			pos = ask_at();
			error = error_handler(delete_at(l,pos));
			break;
		case 'g':
			printf("Удаление элемента с начала.\n");
			error = error_handler(pop_front(l));
			break;
		case 'h':
			printf("Удаление элемента с конца.\n");
			error = error_handler(pop_back(l));
			break;
		case 't':
			printf("Вставка элемента в начало.\n");
			data = ask_what();
			error = error_handler((void*)push_front(l,data));
			break;
		case 'y':
			printf("Вставка элемента в конец.\n");
			data = ask_what();
			error = error_handler((void*)push_back(l,data));
			break;
		case 's':
			printf("Длина списка ");
			printf("%lu\n", l->size);
			break;
		case 'p':
			printf("Печать списка.\n");
			print_list(l,print_int);
			break;
		case 'e':
			printf("Печать элемента.\n");
			pos = ask_at();
			print_int(get_at(l,pos));
			printf("\n");
			break;
		case 'c':
			printf("Сумма значений n элементов, начиная с текущего (пользователь указывает номер элемента).\n");
			pos = ask_at();
			printf("%i\n", summ_elements_from(l,pos));
			break;
		case 'q':
			deleteL(&l);
			exit(0);
			break;
		default:
			break;
		}
		printf("%s\nData:%i\n",error,(int)*error);
		fflush(stdout);
	} while(1);
	deleteL(&l);
	return 0;
}

