#include <iostream>
#include "tree.h"

using namespace std;

void PrintMenu()
{
	cout << "Menu" << endl;
	cout << "a -- add" << endl;
	cout << "d -- del" << endl;
	cout << "p -- print" << endl;
	cout << "q -- quit" << endl;
	cout << "\t>";
}

int main()
{
	Tree<int> t;
	while(true) {
		char ch = '\0';
		PrintMenu();
		cin >> ch;
		switch (ch) {
		case 'a':
			t+t;
			break;
		case 'd':
			t-t;
			break;
		case 'p':
			cout << "try" << endl;
			t.Print();
			break;
		case 'q':
			cout << "Bye!" << endl;
			return 0;
		default:
			break;
		}
	}
	return 0;
}

