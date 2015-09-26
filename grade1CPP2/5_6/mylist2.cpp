#include "mylist.cpp"

class myList2: public myList {
public:
	myList2();
	myList2& operator+(int i) {
		node* buf = new node;
		buf->i= i;
		if (!first) {
			first = last =buf;
			buf->next = buf->pred = NULL;
			ukaz = first;
		} else {
			node* buf2 = ukaz->next;
			buf->next = ukaz->next;
			buf->pred = ukaz;
			ukaz->next = buf;
			ukaz->next = buf;
		}
	}
	const myList2& operator>>(const myList2&) {
		ukaz = last;
	}
	const myList2& operator<<(const myList2&) {
		ukaz = first;
	}
	const myList2& operator>(const myList2&) {
		ukaz = ukaz->next;
	}
	const myList2& operator<(const myList2&) {
		ukaz = ukaz->pred;
	}
private:
	node* last; // конец
};


myList2::myList2()
{
	first = NULL;
	last = NULL;
	ukaz = NULL;
	vsego = 0;
}
