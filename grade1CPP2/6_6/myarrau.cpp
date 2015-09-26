#include <iostream>

using namespace std;



template<class T>
class MyArrau {
public:

	struct node{
		T data;
		node *next;
		node *prev;
	};
	MyArrau();
	~MyArrau();
	void add(T t);
	void print();
	node* arrStart() {
		return start;
	}
	int sizef(){
		return size;
	}
	void clear() {
		node *buf = start;
		while(buf) {
			node* d = buf;
			buf =buf->next;
			delete d;
		}
		start =end = NULL;
		size = 0;
	}

protected:
	node
	*start,
	*end;
	int size;
};

template<class T>
MyArrau<T>::MyArrau()
{
	start = end= NULL;
	size = 0;
}

template<class T>
MyArrau<T>::~MyArrau()
{
	clear();
}

template<class T>
void MyArrau<T>::add(T t)
{
	node *buf = new node;
	buf->data = t;
	size++;

	if (!start) {
		start = buf;
		end = buf;
		buf->next = NULL;
		buf->prev = NULL;
	} else {
		buf->prev = end;
		buf->next = NULL;
		end->next = buf;
		end = buf;
	}
}

template<class T>
void MyArrau<T>::print()
{
	node *buf = start;
	while(buf){
		cout << buf->data;
		buf =buf->next;
	}
	cout << endl;
}
