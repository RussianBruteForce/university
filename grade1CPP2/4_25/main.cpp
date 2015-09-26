#include <iostream>
#include "mdeque.h"
using namespace std;

int main()
{
	MDeque<int> q;
	MStack<int> s;

	int tmp;
	while (true) {
		cout << "MENU\n" <<
			"a -- push to stack\n" <<
			"s -- pop to stack\n" <<
			"q -- push front to deque\n" <<
			"w -- push back to deque\n" <<
			"e -- pop front to deque\n" <<
			"r -- pop back to deque\n\t>";
		char ch;
		cin >> ch;
		switch (ch) {
		case 'a':
			cin >> tmp;
			s >> tmp;
			s.print();
			break;
		case 's':
			s << NULL;
			s.print();
			break;
		case 'q':
			cin >> tmp;
			q < tmp;
			q.print();
			break;
		case 'w':
			cin >> tmp;
			q > tmp;
			q.print();
			break;
		case 'e':
			q << NULL;
			q.print();
			break;
		case 'r':
			q >> NULL;
			q.print();
			break;
		default:
			break;
		}
	}

	return 0;
}

