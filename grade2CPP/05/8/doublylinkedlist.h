#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() :
	    firstNode{nullptr},
	    lastNode{nullptr},
	    current{nullptr},
	    pos{0}, count{0}
    {}
    ~DoublyLinkedList();

    void toStart();
    void toEnd();
    void goRight();
    void goLeft();
    void add(const T&  data);
    void deleteCurrent();

    void operator ++();
    void operator --();
    void operator ++(int);
    void operator --(int);
    void operator >=(const T&);
    void operator <=(const T&);
    void operator >>(const T&);
    void operator <<(const T&data);

    size_t position();
    size_t size();

    void print();
private:
    struct node{
        T data;
        node *next;
        node *prev;
    };
    node
        *firstNode,
        *lastNode,
        *current;
    size_t pos, count;
};

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    node *buf = firstNode;
    for (size_t i = 0; i < count; i++) {
        node *tmp = buf;
        buf = buf->next;
        delete tmp;
    }
}

template <class T>
void DoublyLinkedList<T>::toStart()
{
    current = firstNode;
    pos = 0;
}

template <class T>
void DoublyLinkedList<T>::toEnd()
{
    current = lastNode;
    pos = count -1;
}

template <class T>
void DoublyLinkedList<T>::goRight()
{
    if (current->next) {
        current = current->next;
        pos++;
    }
}

template <class T>
void DoublyLinkedList<T>::goLeft()
{
    if (current->prev) {
        current = current->prev;
        pos--;
    }
}

template <class T>
void DoublyLinkedList<T>::add(const T &data)
{
    node *buf = new node;
    buf->data = data;
    count++;

    if (!firstNode) {
        firstNode = buf;
        lastNode = buf;
        buf->next = NULL;
        buf->prev = NULL;
        pos = 0;
    } else {
        buf->prev = current->prev;
        buf->next = current;
        if (!current->prev)
            firstNode = buf;
        else
            current->prev->next = buf;
        current->prev = buf;
    }
    current = buf;
}

template <class T>
void DoublyLinkedList<T>::deleteCurrent()
{
    node *buf = current;
    count--;

    if (count == 0) {
        pos = 0;
        firstNode = lastNode = NULL;
    } else {
        if (!buf->next){
            lastNode = buf->prev;
            current = lastNode;
            current->next = NULL;
            pos--;
        } else {
            current = buf->next;
            current->prev = buf->prev;
        }
        if (!buf->prev){
            firstNode = buf->next;
            buf->next->prev = NULL
                    ;
        } else {
            buf->prev->next = buf->next;
        }
    }
    delete buf;
}

template <class T>
void DoublyLinkedList<T>::operator ++()
{
    toStart();
}

template <class T>
void DoublyLinkedList<T>::operator --()
{
    toEnd();
}

template <class T>
void DoublyLinkedList<T>::operator ++(int)
{
    toStart();
}

template <class T>
void DoublyLinkedList<T>::operator --(int)
{
    toEnd();
}

template <class T>
void DoublyLinkedList<T>::operator >=(const T &)
{
    goRight();
}

template <class T>
void DoublyLinkedList<T>::operator <=(const T &)
{
    goLeft();
}

template <class T>
void DoublyLinkedList<T>::operator >>(const T &)
{
    deleteCurrent();
}

template <class T>
void DoublyLinkedList<T>::operator <<(const T &data)
{
    add(data);
}



template <class T>
size_t DoublyLinkedList<T>::position()
{
    return pos;
}

template <class T>
size_t DoublyLinkedList<T>::size()
{
    return count;
}

template <class T>
void DoublyLinkedList<T>::print()
{
    node *buf = firstNode;
    for (size_t i = 0; i < count; i++) {
        if (buf == current)
            std::cout << "^";
        std::cout << buf->data << " ";
        buf = buf->next;
    }
    std::cout << std::endl;
}

#endif // DOUBLYLINKEDLIST_H
