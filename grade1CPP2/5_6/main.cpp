#include <iostream>
#include "mylist2.cpp"

using namespace std;

int main()
{
	myList l1;
	myList2 l2;
	int i;
	while (true) {
		cout << "L1" <<endl;
		l1.print();
		cout << "L2" <<endl;
		l2.print();

		cout << "lab 4 var 6" << endl;
		cout << "menu" << endl;
		cout << "0 - L1 Vykhod" << endl;
		cout << "1 - L1 V nachalo" << endl;
		cout << "2 - L1 Sled" << endl;
		cout << "3 - L1 Udalit'" << endl;
		cout << "4 - L1 Dobavit'" << endl;
		cout << "5 - L2 V konec" << endl;
		cout << "6 - L2 V nachalo" << endl;
		cout << "7 - L2 Pred" << endl;
		cout << "8 - L2 Sled" << endl;
		cout << "9 - L2 Dobavit\n : ";
		int v;
		cin >> v;
		switch (v) {
		case 0:
			return 0;
			break;
		case 1:
			l1--;
			break;
		case 2:
			l1++;
			break;
		case 3:
			l1 - l1;
			break;
		case 4:
			cout << "Vvedite int : ";
			cin >> i;
			l1 + i;
			cout << endl;
			break;
		case 5:
			l2 >> l2;
			break;
		case 6:
			l2 << l2;
			break;
		case 7:
			l2 < l2;
			break;
		case 8:
			l2 > l2;
			break;
		case 9:
			cout << "Vvedite int : ";
			cin >> i;
			l2 + i;
			cout << endl;
			break;
		}
	}
	return 0;
}

