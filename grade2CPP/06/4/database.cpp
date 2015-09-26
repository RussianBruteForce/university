#include "database.h"

bool DataBase::take(List::node *t)
{
    if (!t)
        return false;
    else {
        t->next = head;
        head = t;
        return true;
//        auto d = t->data;
//        delete t;
//        add(d);
        return true;
    }
}

List<Bus>::node *DataBase::getByID(size_t ID)
{
    node *tmp = head,
         *before = nullptr;

    // на случай отсутствия элементов
    if (!head)
        return nullptr;

    // На случай одного элемента в базе
    if (!head->next){
        head = nullptr;
        return tmp;
    }

    while (tmp) {
        if (tmp->data.id == ID) {
            before->next = tmp->next;
            return tmp;
        }
        before = tmp;
        tmp = tmp->next;
    }
    return nullptr;
}

void DataBase::deleteByID(size_t ID)
{
    delete getByID(ID);
}

bool DataBase::print()
{
    std::cout << "*****" << std::endl;
    if (!head)
        return false;
    auto tmp = head;
    while (tmp) {
        std::cout << "ID: " << tmp->data.id << "\t"
                  << "Имя: " << tmp->data.driver << "\t"
                  << "Маршрут: " << tmp->data.route << std::endl;
        tmp = tmp->next;
    }
    std::cout << std::endl;
    return true;
}

