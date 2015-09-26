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
	DoublyLinkedList(const DoublyLinkedList& old);
	~DoublyLinkedList();

	void toStart();
	void toEnd();
	void goRight();
	void goLeft();
	void add(const T&  data);
	void deleteCurrent();

	void handle_array();
	T getCurrent();
	void addToEnd(const T& data);

	void operator ++();
	void operator --();
	void operator ++(int);
	void operator --(int);
	void operator >=(const T& data);
	void operator <=(const T& data);
	void operator >>(const T& data);
	void operator <<(const T& data);

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

template <class T> // конструктор копирования
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& old)
{
	firstNode = lastNode = nullptr;
	this->pos = old.pos;
	count = 0;

	std::cout << "\nP: " << old.pos << "\n" << "N: " << this->pos << "\n";

	if (old.count == 0) // зачем нам что-то делать, если список пуст?
		return;

	auto c_old = old.firstNode; // для бега по старому списку
	for (size_t i = 0; i < old.count; i++) { // столько раз, сколько элементов в старом списке
		auto buf = new node;
		buf->data = c_old->data; // копируем данные элемента списка
		if (!firstNode) { // если мы создаем первый элемент
			firstNode = lastNode = buf;
			buf->prev = nullptr;
			buf->next = nullptr;
		} else { // иначе суем в конец
			lastNode->next = buf;
			buf->next = nullptr;
			buf->prev = lastNode;
			lastNode = buf;
		}
		count++;
		c_old = c_old->next; // к следующему элементу
	}
}

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
void DoublyLinkedList<T>::handle_array()
{
	std::cout << "HANDLER" << std::endl;
	node *buf = firstNode;
	for (size_t i = 0; i < count; i++) {
		std::cout << buf->data << " ";
		buf = buf->next;
	}
	std::cout << std::endl;
}

template <class T>
T DoublyLinkedList<T>::getCurrent()
{
	return current->data;
}

template <class T>
void DoublyLinkedList<T>::addToEnd(const T &data)
{
	node *buf = new node;
	buf->data = data;
	//    count++;

	if (count++ != 0) {
		buf->prev = lastNode;
		buf->next = nullptr;
		lastNode->next = buf;
		lastNode = buf;
	} else
		add(data);

	current = buf;
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
void DoublyLinkedList<T>::operator ++(int r)
{
	toStart();
}

template <class T>
void DoublyLinkedList<T>::operator --(int r)
{
	toEnd();
}

template <class T>
void DoublyLinkedList<T>::operator >=(const T &data)
{
	goRight();
}

template <class T>
void DoublyLinkedList<T>::operator <=(const T &data)
{
	goLeft();
}

template <class T>
void DoublyLinkedList<T>::operator >>(const T &data)
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
