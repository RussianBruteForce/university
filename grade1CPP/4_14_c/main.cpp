#include <iostream>
#include "note.h"
#include "array"

using namespace std;

int main()
{
    array<NOTE, 1> data;
    for (auto &x: data)
        x = NOTE::readNote();

    while (true) {
        char ch = '\0';
        bool any = false;
        string name;
        cout << "\tменю\n"
             << "p -- вывод списка\n"
             << "s -- поиск по имени\n"
             << "q -- выход\n\t>";
        cin >> ch;
        switch (ch) {
        case 'p':
            for (auto &x: data)
                x.print();
            break;
        case 's':
            cout << "Введите имя:\n\t>";
            cin >> name;
            cout << endl;
            for (auto &x: data) {
                if (x.checkName(name)) {
                    any = true;
                    x.print();
                }
            }
            if (!any)
                cout << "не найдено!\n";
            break;
        case 'q':
            cout << "пока!" << endl;
            return 0;
            break;
        default:
            cout << "Неверный выбор!";
            break;
        }
    }
    return 0;
}

