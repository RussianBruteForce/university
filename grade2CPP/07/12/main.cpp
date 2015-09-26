#include <iostream>
#include <fstream>
#include "doublylinkedlist.h"

using namespace std;

std::string read_file(std::string filename)
{
    std::ifstream file(filename,std::ios::in);
    if (!file) {
        std::cerr << "Can't open file " << filename << '!' << std::endl;
        exit(0);
    }
    std::cout << "Читаем файл…";

    std::string ret;
    while(!file.eof()) { // до конца файла
        std::string buf;
        file >> buf; // чиатем до разделительного символа (пробел, табуляция, перевод строки)

        if (!ret.empty())
            ret.append(" " + buf); // добавляем к нашей строке предварительно вставив пробел
        else
            ret.append(buf); // первое слово вставляем без предшествующего пробела
    }

    file.close();
    std::cout << "\tГотово!" << std::endl;
    return ret;
}

void string_to_list(DoublyLinkedList<char> &list, std::string &string)
{
    for (auto &ch : string)
        list.addToEnd(ch);
}

int main()
{
    DoublyLinkedList<char> arr; //  создаем список
    auto str = read_file("w"); //   чиатем файл

    cout << "Из файла считана строка:\n\t>" << str << endl;
    string_to_list(arr, str); //    пихаем строку в список
    cout << "Засунули строку в список, в списке теперь:" << endl;
    arr.print();

    cout << "Обрабатываем строку..." << endl;
    arr.handle_char_array(); //     обрабатываем
    arr.print(); //                 выводим результат


    cout << "Копируем объект класса..." << endl;
    auto y = arr;
    y.print();
    cout << "Еще раз)))" << endl;
    auto x = y;
    x.print(); //                   проверка конструктора копирования

    return 0;
}

