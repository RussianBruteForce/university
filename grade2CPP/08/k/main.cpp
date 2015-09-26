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
			try {
				t+t;
			} catch (exception &r){
				cerr << r.what() << endl;
			}
			break;
		case 'd':
			try {
				t-t;
			} catch (exception &r){
				cerr << r.what() << endl;
			}
			break;
		case 'p':
			try {
				t.Print();
			} catch (exception &r){
				cerr << r.what() << endl;
			}
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

