#ifndef TAYLOR_SERIES_H
#define TAYLOR_SERIES_H

#include <ostream>
#include <cmath>
#include <iomanip>

class taylor_series
{
    // перегрузка оператора
    friend std::ostream &operator<< (std::ostream &out, const taylor_series &c);
public:
    // запред пустого конструктора
    taylor_series() = delete;
    // конструктор
    taylor_series(double var, size_t lenght) : x(var), n(lenght) {}

private:
    // вычисление i-того элемента ряда
    double function(ulong i) const; // функция не может менять объект
    // переменная
    double x;
    // кол-во вычисляемых элементов ряда
    size_t n;
    // формат вывода (кол-во символов на значение)
    const uint o_width = 10;
};
#endif // TAYLOR_SERIES_H
