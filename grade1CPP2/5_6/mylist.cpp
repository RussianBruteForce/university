#include <string>

using namespace std;

struct node {
	int i;
	node* next; // следущая нода
	node* pred; // предыдущая
};

class myList {
public:
	myList();
	int len();
	const myList& operator+(int i) {
		add(i);
	}
	const myList& operator-(const myList&) {
		del(ukaz);
	}
	const myList& operator++(int) {
		ukaz = ukaz->next;
	}
	const myList& operator--(int) {
		ukaz = first;
	}

	void print();

protected: // чтобы было доступно в наследнике
	void add(int i);
	void del(node *n);
	int vsego;
	node* first;
	node* ukaz;
};


myList::myList()
{
	vsego = 0;
	first = NULL;
	ukaz = NULL;
}

void myList::add(int i)
{
	node *buf = new node;
	buf->i = i;
	buf->next = NULL;
	if (!first) {
		first = buf;
		ukaz = first;
	} else {
		node * buf2 = first;
		while (buf2->next) // ищем конец списка
			buf2 = buf2->next;
		buf2->next = buf;
	}
	vsego++;
}

void myList::del(node* n)
{
	if(!n)
		return;

	if(n == first) {
		node* b = n;
		n = first = ukaz = n->next;
		delete b;
		return;
	}
	node *buf = first;
	if (!buf->next)
		first = ukaz = NULL;
	delete buf;
	while(buf->next != n) // ищем предыдущую ноду
		buf = buf->next;
	buf->next = n->next;
	ukaz = buf;
	delete n;
	vsego--;
}

int myList::len()
{
	return vsego;
}

void myList::print()
{
	node *buf = first;
	while (buf) {
		cout << " " << buf->i;
		if (buf == ukaz)
			cout << "*";
		buf = buf->next;
	}

	cout << endl;
}
