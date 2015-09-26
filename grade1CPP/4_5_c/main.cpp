#include <iostream>
#include <vector>
#include "aeroflot.h"
using namespace std;

int main()
{
    vector<AEROFLOT> massiv;
    massiv.resize(10);
    for (int i = 0; i < 10;i++) {\
        cout << "имя ";
        cin >>massiv[i].name;
        cout << "\nрейс ";
        cin >>massiv[i].flight;
        cout << "\nтип ";
        cin >>massiv[i].type;
        cout << "\nзанято мест ";
        cin >>massiv[i].engaged;
        cout << "\nвсего мест ";
        cin >>massiv[i].seat;
        cout << endl;
        //massiv[i] = {"Addffd",423,"34",43,34};
    }
    //massiv[5] = {"Bewrte",423,"34",43,34};
    //massiv[2] = {"t",423,"34",43,34};

    //сортировка прямым выбором по 1-м буквам слов
    for(int i = 0    ; i < 10; i++)
    for(int j = i + 1; j < 10; j++)
    {
        if((massiv[j]).name[0] < (massiv[i]).name[0])
        {
            //Меняем элементы посредством буфера
            string sBuffer      = massiv[j].name;
            massiv[j].name = massiv[i].name;
            massiv[i].name = sBuffer;
        }
    }
    string buf;
    bool vyvodili = false;
    int ch;

    while(true) {
        cout << "\t**menu**"
             << "0 для выхода\n"
             << "1 дял вывода списка всех рейсов\n"
             << "2 для поиска рейсов по пункту назначения"
             << endl;
        cin >> ch;
        switch (ch) {
        case '0':
            return 0;
            break;
        case 1:
            for (int i = 0; i < 10;i++) {
                cout << "***\n";
                cout << "имя ";
                cout << massiv[i].name;
                cout << "\nрейс ";
                cout << massiv[i].flight;
                cout << "\nтип ";
                cout <<massiv[i].type;
                cout << "\nзанято мест ";
                cout << massiv[i].engaged;
                cout << "\nвсего мест ";
                cout << massiv[i].seat;
                cout << endl;
            }
            break;
        case 2:
            cout << "введите место назначения ";
            cin >> buf;
            for (int i = 0; i < 10;i++) {
                if (buf == massiv[i].name) {
                cout << "***\n";
                cout << "\nрейс ";
                cout << massiv[i].flight;
                cout << "\nтип ";
                cout <<massiv[i].type;
                cout << endl;
                vyvodili = true;
                }
            }
            if (!vyvodili)
                cout << "Не найдено рейсов!" << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}

