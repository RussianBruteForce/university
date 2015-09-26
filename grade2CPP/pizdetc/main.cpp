#include <iostream>
#include "pizdetc.h"

using namespace std;

int main()
{
    pizdetc p; // создаем объект нашего класса
    p.add({"Витя", 3.4}); // вариант добавления

    // еще вариант
    dick trusha = {"Антон", 9000};
    p.add(trusha);

    // и еще
    dick art;
    art.name = "Артур";
    art.size = 14.5;
    p.add(art);

    std::string name_kostya = {"Костя"};
    double size_kostya = 0.0007;

    p.add(name_kostya, size_kostya); // и еще, тут вызовется void add(std::string name, double size);

    name_kostya = {"Костя2"};
    p.add({name_kostya, size_kostya}); // а тут void add(dick x);

    p.show();

    return 0;
}

