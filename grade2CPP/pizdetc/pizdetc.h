#ifndef PIZDETC_H
#define PIZDETC_H

#include <string> // строки
#include <vector> // вектор
#include <iostream> // вывод/ввод

struct dick{
    std::string name; // хуевое имя
    double size; // длина хуя
};

class pizdetc
{
public:
    pizdetc(); // конструктор класса
    // добавляет новый хуй
    void add(dick x);
    // добавляет новый хуй, но принимает параметры хуя, а не сам хуй
    void add(std::string name, double size);
    // возвращает хуй, который стоит на позиции position
    dick get(size_t position);
    // будет возвращать количество хуев в классе, можно и без неё
    size_t size();
    // рисует табличку с хуями
    void show();

private:
    std::vector<dick> data; // наш список хуев
};

#endif // PIZDETC_H
