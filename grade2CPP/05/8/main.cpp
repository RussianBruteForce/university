#include <iostream>

#include "doublylinkedlist.h"

using namespace std;

int main()
{
    DoublyLinkedList<int> l;

    for (int i = 0 ; i < 10; i++) {
        l.add(666);
    }

    while(true) {
            int choice = -1;
            size_t p = l.position();
            cout << "\nМеню!" << endl;
            cout << "\t1 Вывод" << endl;
            cout << "\t2 Добавить элемент в текущую позицию (" << p << ")" << endl;
            cout << "\t3 Удалить элемент в текущей позиции (" << p << ")" << endl;
            cout << "\t4 В конец" << endl;
            cout << "\t5 В начало" << endl;
            cout << "\t6 Левее" << endl;
            cout << "\t7 Правее" << endl;
            cout << "\t0 или букву для выхода" << endl;
            cout << "\t>";
            cin >> choice;
            switch (choice) {
            case 1:
                    l.print();
                    break;
            case 2:
                    int buf;
                    cout << "Введите значение:\n\t>";
                    cin >> buf;
                    l << buf;
                    break;
            case 3:
		    l >> NULL;
                    break;
            case 4:
                    l--;
                break;
            case 5:
                    l++;
                break;
            case 6:
		    l <= NULL;
                break;
            case 7:
		    l >= NULL;
                break;
            case 0:
                    cout << "пока!" << endl;
                    return 0;
                    break;
            default:
		    cout << "выбирать надо из того,ч то дают! :P" << endl;
                    break;
            }
    }


    return 0;
}

