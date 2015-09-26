#include <iostream>
#include "taylor.cpp"

using namespace std;

/*
 * етот код написо спициальна( так зодумано(
 */

int main()
{
	taylor t;
	cout << "Enter x: ";
	cin >> t;
	cout << "\nEnter n: ";
	int n;
	cin >> n;
	t.setn(n);
	cout << endl << t;

	return 0;
}

