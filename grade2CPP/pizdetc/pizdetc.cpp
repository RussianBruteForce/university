#include "pizdetc.h"

pizdetc::pizdetc()
{
}

void pizdetc::add(dick x)
{
    // суем хуй в вектор
    data.push_back(x);
}

void pizdetc::add(std::string name, double size)
{
    // просто буфер хуя, память освободится после выхода из функции
    dick buf {name, size};
    // суем хуй в вектор
    data.push_back(buf);
}

dick pizdetc::get(size_t position)
{
    if (position > data.size())// если position больше чем размер вектора с хуями
        return data.at(data.size() - 1); // то мы возвращаем последний хуй
    else
        return data.at(position); // иначе тот хуй, который просят
}

size_t pizdetc::size()
{
    // возвращаем размер вектора в котрый напиханы хуи
    return data.size();
}

void pizdetc::show()
{
    // заголовок таблицы хуев
    std::cout << "Имя" << '\t' << "Длина" << std::endl;
    for (auto x: data) // бежим по вектору хуев, for будет пихать хуи от начала до конца по очереди в x
        std::cout << x.name << '\t' << x.size << std::endl;
}
