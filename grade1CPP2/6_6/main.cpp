#include <iostream>
#include "mystring.cpp"

using namespace std;

/*
 * Писал не по своей воле.
 * Извините...
 */

void stringToMyString(string s, MyString &ms) {
	for (int i = 0; i <s.size(); i++) {
		ms.add(s[i]);
	}
}

int main()
{
	MyString mstr;
	string str;
	cin >> str;
	stringToMyString(str,mstr);
	mstr.proc();
	mstr.print();
	return 0;
}

