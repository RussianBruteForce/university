#ifndef LISTEXCP_H
#define LISTEXCP_H

#include "iostream"
#include <exception>

using namespace std;

class empty_list_deleting : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Удаление из пустого списка!\n";
    }
};
class empty_list_copying : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Копирование пустого списка!\n";
    }
};
class empty_list_printing : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Вывод пустого списка!\n";
    }
};
class already_at_end : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Уже в конце!\n";
    }
};
class already_at_start : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Уже в начале!\n";
    }
};
class moving_in_empty_list : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Перемещение по пустому списку!!\n";
    }
};
#endif // LISTEXCP_H
