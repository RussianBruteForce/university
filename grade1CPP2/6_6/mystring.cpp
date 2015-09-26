#include "myarrau.cpp"

class MyString: public MyArrau<char> {
public:
	MyString() : MyArrau() {}
	MyString(const MyString *s) {
		node* buf = s->start;
		while (buf) {
			add(buf->data);
			buf = buf->next;
		}
	}

	void proc();
};


void MyString::proc()
{
	node * buf = start;
	while (buf) {
		char ch = buf->data;
		if (ch == 'x') {
			buf->data = 'k';
			node * s = new node;
			s->data = 's';
			buf->next->prev = s;
			s->prev = buf;
			s->next = buf->next;
			buf->next = s;
			size++;
			return;
		}
		buf= buf->next;
	}
}
