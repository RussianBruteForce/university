#include <stdio_ext.h>
#include <stdlib.h>
#include <math.h>

//функция вывода результата функции
// Первые 3 аргумента -- коэфициэнты функции
// четвертый X -- это аргумент функции которую реальизует эта функция
void f_print(const double a, const double b, const double c, const double x)
{
	//printf("\ndf %f\n",x);
	double res = 0;
	if (a < 0 && c != 0)
		printf("\t%13.11f", res = (a*pow(x,2) + b*x + c));
	else if (a > 0 && c == 0) {
		if (fabs(x) > 10e-7)
			printf("\t%13.11f", res = ((double)(-1) * a)/(x - c));
		else
			printf("\terror         ");
	} else
		printf("\t%13.11f", res = a * (x + c));
	if (res >= 0)
		printf(" ");
}

int main(void)
{
	double a, b, c, x1, x2;
	a = b = c = x1 = x2 = 0;
	double dx = 1;
	printf("Введите последовательно a, b, c, x1, x2, dx: ");// просим ввести коэфициэнты
	// интервал на котором вызывается функция и шаг
	int d = scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &x1, &x2, &dx);// считываем результаты с клавиатуры
	__fpurge(stdin); // очищаем поток ввода

	//проверяем всё на валидность, если не правильно -- включается цикл и будет повторяться пока пользователь не введет верные данные
	while ( (d != 6) ||
	        x2 < x1  ||
	        dx >= abs(x2-x1) ||
	        dx <= 0) {
		printf("\nПроверьте ввод!\nВведите последовательно a, b, c, x1, x2, dx: ");
		d = scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &x1, &x2, &dx);
		__fpurge(stdin); // очистка потока ввода
	};

	// Цикл от нижней границы интервала до верхней включительно с шагом dx
	printf("\n|-----------------------------------------------|");
	int line_counter = 1;
	for (double i = x1; i <= x2; i += dx) {
		printf("\n| f(%13.11f)\t=", i);// вывод переноса строки, затем значение Х
		f_print(a,b,c,i);// вызываем функцию которая посчитает и выведет значение функции для Х
		printf("\t|");
		if (line_counter++%20 == 0) {
			printf("\nНажмите Enter для продолжения...\n");
			char ch;
			__fpurge(stdin);
			while (scanf("%c", &ch) != 1 ||
			       ch != '\n') ;
		}
	}
	printf("\n|-----------------------------------------------|\n");

	return 0;
}
