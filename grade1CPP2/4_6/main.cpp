#include <iostream>
#include "mylib.cpp"

/*
 * Алерта!
 * Это написано специально!
 */

using namespace std;

int main()
{
	myLib lib;

	lib.add("Kostin","A. D.","Programirovanie",1666,3);
	lib.add("Natanov","D. R.","Algebra",1336,1);
	lib.add("Gorlov","A. L.","Matan",1337,4);

	string str;
	while (true) {
		cout << "lab 4 var 6" << endl;
		cout << "menu" << endl;
		cout << "0 - Vykhod" << endl;
		cout << "1 - Vidat' knigu" << endl;
		cout << "2 - Vernut knigu" << endl;
		cout << "3 - Naiti knigu" << endl;
		cout << "4 - Vivesti vse knigi\n : ";
		int v;
		cin >> v;
		switch (v) {
		case 0:
			return 0;
			break;
		case 1:
			cout << "Nazvanie\n : ";
			cin >> str;
			lib.vydat(str);
			break;
		case 2:

			cout << "Nazvanie\n : ";
			cin >> str;
			lib.vernut(str);
			break;
		case 3:

			cout << "Familia\n : ";
			cin >> str;
			lib.find(str);
			break;
		case 4:
			lib.print();
			break;
		}
	}
	return 0;
}

