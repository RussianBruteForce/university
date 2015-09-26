#include "functions.h"

int EnterI(void)
{
	char *input_1 = new char[1024];
	char *input_2 = new char[1024];
	int a;
	int error = 0;
	do
	{
		if (error == 1)
		{
			printf("Ошибка ввода. Повторите ввод: ");
		}
		scanf("%s", input_1);
		sscanf(input_1, "%i", &a);
		sprintf(input_2, "%i", a);
		if (strcmp(input_1, input_2) != 0)
		{
			error = 1;
		}
		else
		{
			error = 0;
		}
	} while (error == 1);
	delete[]input_1;
	delete[] input_2;
	return a;
}

float EnterF(void)
{
	char *input_1 = new char[1024];
	char *input_2 = new char[1024];
	float a;
	int error = 0;
	do
	{
		if (error == 1)
		{
			printf("Ошибка ввода. Повторите ввод: ");
		}
		scanf("%s", input_1);
		sscanf(input_1, "%g", &a);
		sprintf(input_2, "%g", a);
		if (strcmp(input_1, input_2) != 0)
		{
			error = 1;
		}
		else
		{
			error = 0;
		}
	} while (error == 1);
	delete[]input_1;
	delete[] input_2;
	return a;
}