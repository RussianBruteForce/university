#include "Classes.h"
#include "functions.h"
#include <iostream>
#include <string>

/*
 * �� ��� ��������� �������� ����, �������� ��� ���� ���� �� "�������, ����� �����������"
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
		printf("������ ����� �������� �� 1)Int, 2)Float ��� 3)String? : ");
		whoit = EnterI();
		if ((whoit < 1) || (whoit > 3))
		{
			printf("������ �����. ��������� ����\n");
		}
		else
		{
			break;
		}
	} while (true);
	do
	{
		printf("��� �� ������ �������?\n1) �������� ������� � ������ ������\n2) �������� ������� � ����� ������\n3) ������ ������� �� ������ ������\n4) ������ ������� �� ����� ������\n5) ����� �� ���������\n���� �������: ");
		menu = EnterI();
        try {
		if ((menu <= 0) || (menu >= 6))
		{
			printf("\n������ �����. ��������� ����\n");
		}
		else if (menu == 1)
		{
			printf("������� �������: ");
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
				// ������ ������ :3
			}
			printf("������� �������\n\n");
		}
		else if (menu == 2)
		{
			printf("������� �������: ");
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
				// ������ ������ :3
			}
			printf("������� �������\n\n");
		}
		else if (menu == 3)
		{
			if (whoit == 1)
			{
				A1 << b;
				printf("�������� ����� %i\n\n", b);
			}
			else if (whoit == 2)
			{
				A2 << c;
				cout << "�������� ����� " << c << endl << endl;
			}
			else
			{
				A3 << d;
				cout << "�������� ������ " << d << endl << endl;
			}
		}
		else if (menu == 4)
		{
			if (whoit == 1)
			{
				A1 >> b;
				printf("�������� ����� %i\n\n", b);
			}
			else if (whoit == 2)
			{
				A2 >> c;
				cout << "�������� ����� " << c << endl << endl;
			}
			else
			{
				A3 >> d;
				cout << "�������� ������ " << d << endl << endl;
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
