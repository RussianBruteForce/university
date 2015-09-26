#include <string>

using namespace std;

struct node {
	string famil; // фамилия
	string inic; //инициалы
	string name; // название книги
	int year;
	int colich; // колдичество  библиотеке
	node* next; // следущая нода
};

class myList {
public:
	myList();
	void add(string f, string i, string n, int y, int c);
	void del(node *n);
	int len();

protected: // чтобы было доступно в наследнике
	int vsego;
	node* first;
};


myList::myList()
{
	vsego = 0;
	first = NULL;
}

void myList::add(string f, string i, string n, int y, int c)
{
	node *buf = new node;
	buf->famil = f;
	buf->inic = i;
	buf->name = n;
	buf->year = y;
	buf->colich = c;
	buf->next = NULL;
	if (!first) {
		first = buf;
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
	node *buf = first;
	while(buf->next != n) // ищем предыдущую ноду
		buf = buf->next;
	buf->next = n->next;
	delete n;
}

int myList::len()
{
	return vsego;
}
