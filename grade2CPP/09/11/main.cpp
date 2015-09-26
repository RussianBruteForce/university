#include <iostream>
#include "taylor_series.h"
#include "antifool.h"

using namespace std;

void print_menu()
{
    cout << "Лаб 9, вариант 11\n"
         << "\tx - для установки значения функции\n"
         << "\tn - для установки кол-ва выводимых первых элементов\n"
         << "\tp - для вывода ряда\n"
         << "\tq - для выхода\n\t>";
    cout.flush();
}

int main()
{
    size_t *n = nullptr;
    double *x = nullptr;
    while(true) {
        char ch = '\0';
        print_menu();
        AntiFool::read(ch);
        switch (ch) {
        case 'x':
            if (!x)
                x = new double;
            AntiFool::read(*x,"Введите x");
            break;
        case 'n':
            if (!n)
                n = new size_t;
            AntiFool::read(*n,"Введите n");
            break;
        case 'p':
            if (!x) {
                cout << "Задайте x!" << endl;
                break;
            }
            if (!n) {
                cout << "Задайте n!" << endl;
                break;
            }
            cout << taylor_series(*x,*n);
            break;
        case 'q':
            if (x)
                delete x;
            if (n)
                delete n;
            cout << "пока!" << endl;
            return 0;
        default:
            cout << "Выбирай то, что дают!" << endl;
            break;
        }
    }
    if (x)
        delete x;
    if (n)
        delete n;
    return 0;
}
