#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
class List {
public:
    List() {head = nullptr;}
    ~List();
    void add(T data);
    virtual bool print() = 0;

protected:
    struct node {
        T data;
        node *next;
    };
    node *head;
};

template <class T>
List<T>::~List()
{
    while (head)
    {
        auto tmp = head->next;
        delete head;
        head = tmp;
    }
}

template <class T>
void List<T>::add(T data)
{
    auto tmp = new node;
    tmp->data = data;
    tmp->next = nullptr;
    if (head)
        tmp->next = head;
    head = tmp;
}

#endif // LIST_H
