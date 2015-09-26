#include <iostream>
#include "hoare.h"

using namespace std;

int main()
{
	string s;
	cout << "Filename or `r` for random\n\t>";
	cin >> s;
	Hoare *h;
	if (s.size() == 1 && s[0] == 'r')
		h = new Hoare();
	else
		h = new Hoare(s);
	cout << "Size: " << h->size() << endl;
	size_t first = h->size(), step = 0;
	while (first > h->size() - 1) {
		cout << "Enter start\n\t>";
		cin >> first;
	}
	while (step < 2) {
		cout << "Enter step\n\t>";
		cin >> step;
	}
	h->qsort(first, step);
	h->print();
	cout << "C: " << h->get_comparison() << "\tS: " << h->get_swaps() << endl;
	delete h;
	return 0;
}

