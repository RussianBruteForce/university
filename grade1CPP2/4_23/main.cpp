#include <iostream>
#include "telephonedatabase.h"

using namespace std;

int main()
{
	TelephoneDataBase db("w");
	while (true) {
		char ch;
		cout << "*** MENU ***\n" <<
			"p -- print list\n" <<
			"u -- info about user\n" <<
			"a -- set time\n" <<
			"b -- print bill\n" <<
			"q -- quit\n\t>";
		cout.flush();
		cin >> ch;
		switch (ch) {
		case 'p':
			db.print();
			break;
		case 'u':
		{
			string s;
			cout << "\nSurname >";
			cout.flush();
			cin >> s;
			db.printUser(s);
		}
			break;
		case 'a':
		{
			unsigned long t, tt;
			cout << "\nTelephone >";
			cout.flush();
			cin >> t;
			cout << "\nTime (in sec.) >";
			cout.flush();
			cin >> tt;
			db.setTime(t,tt);
		}
			break;
		case 'b':
		{
			unsigned long t;
			cout << "\nTelephone >";
			cout.flush();
			cin >> t;
			db.printBill(t);
		}
			break;
		case 'q':
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}

