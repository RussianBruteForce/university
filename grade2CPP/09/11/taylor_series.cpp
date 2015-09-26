#include "taylor_series.h"

std::ostream &operator<< (std::ostream &out, const taylor_series &c)
{
    out << "Ваш ряд: ";
    for (size_t i = 0; i < c.n; i++)
        out << std::setw(c.o_width) << c.function(i) << ' ';
    out << std::endl;
    return out;
}

double taylor_series::function(ulong i) const
{
    // 1-ый элемент ряда всегда 1
    if (!i)
        return 1;

    // функция вычисления значения
    auto f = [i](double x)->double { return pow(x, i+1) / i+1; };

    // чередование знака и вычисление значения
    if (i%2)
        return f(x)*(-1);
    else
        return f(x);
}
