#include "Classes.h"
#include "functions.h"
#include <iostream>
#include <string>

/*
 * Не все программы написаны мной, например эта была дана на "сдалать, чтобы запускалось"
 */
using namespace std;


int main()
{
	int b;
	float c;
	char *d = (char*)malloc(10000);
	int menu;
	int whoit;
	Spisok<int> A1;
	Spisok<float> A2;
	Spisok<char *> A3;
	setlocale(0, "");
	do
	{
		printf("Список будет состоять из 1)Int, 2)Float или 3)String? : ");
		whoit = EnterI();
		if ((whoit < 1) || (whoit > 3))
		{
			printf("Ошибка ввода. Повторите ввод\n");
		}
		else
		{
			break;
		}
	} while (true);
	do
	{
		printf("Что вы хотите сделать?\n1) Добавить элемент в начало списка\n2) Добавить элемент в конец списка\n3) Изъять элемент из начала списка\n4) Изъять элемент из конца списка\n5) Выйти из программы\nВаше решение: ");
		menu = EnterI();
        try {
		if ((menu <= 0) || (menu >= 6))
		{
			printf("\nОшибка ввода. Повторите ввод\n");
		}
		else if (menu == 1)
		{
			printf("Введите элемент: ");
			if (whoit == 1)
			{
				b = EnterI();
				A1 <= b;
			}
			else if (whoit == 2)
			{
				c = EnterF();
				A2 <= c;
			}
			else
			{
				cin >> d;
				char *temp = (char*)malloc(sizeof(char) * (strlen(d) + 1));
				strcpy(temp, d);
				A3 >= temp;
				// учетка памяти :3
			}
			printf("Элемент добвлен\n\n");
		}
		else if (menu == 2)
		{
			printf("Введите элемент: ");
			if (whoit == 1)
			{
				b = EnterI();
				A1 >= b;
			}
			else if (whoit == 2)
			{
				c = EnterF();
				A2 >= c;
			}
			else
			{
				cin >> d;
				char *temp = (char*)malloc(sizeof(char) * (strlen(d) + 1));
				strcpy(temp, d);
				A3 >= temp;
				// утечка памяти :3
			}
			printf("Элемент добвлен\n\n");
		}
		else if (menu == 3)
		{
			if (whoit == 1)
			{
				A1 << b;
				printf("Получено число %i\n\n", b);
			}
			else if (whoit == 2)
			{
				A2 << c;
				cout << "Получено число " << c << endl << endl;
			}
			else
			{
				A3 << d;
				cout << "Получена строка " << d << endl << endl;
			}
		}
		else if (menu == 4)
		{
			if (whoit == 1)
			{
				A1 >> b;
				printf("Получено число %i\n\n", b);
			}
			else if (whoit == 2)
			{
				A2 >> c;
				cout << "Получено число " << c << endl << endl;
			}
			else
			{
				A3 >> d;
				cout << "Получена строка " << d << endl << endl;
			}
		}
		if (whoit == 1)
		{
			A1.showAll();
		}
		else if (whoit == 2)
		{
			A2.showAll();
		}
		else
		{
			A3.showAll();
		}
        } catch (const char *str) {
            cout << str << endl;
        }
	} while (menu != 5);
	free(d);
	return 0;
}
