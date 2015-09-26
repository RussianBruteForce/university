#include "mylist.cpp"

using namespace std;

class myLib: public myList {
public:
	void vydat(string k);
	void vernut(string k);
	void print();
	void find(string f);
	void print_k(node* n);
};


void myLib::vydat(string k)
{
	node *buf = first;
	while (buf) {
		if(buf->name == k)
		{
			if (buf->colich == 0) {
				cout << "Kniga " << k << " konchilas'!" << endl;
				return;
			}
			buf->colich--;
			cout << "Vydano! \nKnig " << k << " ostalos " << buf->colich << endl;
			return;
		}
		buf = buf->next;
	}
	cout << "Takoy knigi netu(((" << endl;
}

void myLib::vernut(string k)
{
	node *buf = first;
	while (buf) {
		if(buf->name == k)
		{
			buf->colich++;
			cout << "Vernuto)))! \n Teper knig " << k << " est' " << buf->colich << endl;
			return;
		}
		buf = buf->next;
	}
	cout << "Takoy knigi nikogda nebilo!" << endl;
}

void myLib::print()
{
	node *buf = first;
	while (buf) {
		print_k(buf);
		buf = buf->next;
	}
}

void myLib::find(string f)
{
	node *buf = first;
	while (buf) {
		if(buf->famil == f)
		{
			print_k(buf);
		}
		buf = buf->next;
	}
}

void myLib::print_k(node* n)
{
	cout << "\"" << n->name << "\" " << n->famil << " " << n->inic
	     << ", " << n->year << " = " << n->colich<< endl;
}
