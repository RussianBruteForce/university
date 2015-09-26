#include <iostream>
#include "tree.h"

using namespace std;

/*
 * Реализовать LABEL(n, T) CREATEi(n, T1, T2), ROOT(T)
 *
 * 1 и 2.23
 */

static tree* CREATE2(uint n, tree* L1, tree* L2)
{
	auto ret = new tree;
	ret->root = new tree::node(n, L1->root, L2->root);
	delete L1;
	delete L2;
	return ret;
}

static tree::node* ROOT(tree *L)
{
	return L->root;
}

static tree::node* LABEL(int n, tree *L)
{
	return L->root->find(n);
}

int main()
{
	tree *T1 = new tree(), *T2 = new tree(), *T3;

	cout << "First tree (T1)\n";
	for (int i = 0; i < 3; i++) {
		cout << "Enter T1[" << i << "]\n\t>";
		int buf = 0;
		cin >> buf;
		T1->add(buf);
	}
	cout << "~T1\n";
	T1->print();


	cout << "First tree (T2)\n";
	for (int i = 0; i < 3; i++) {
		cout << "Enter T2[" << i << "]\n\t>";
		int buf = 0;
		cin >> buf;
		T2->add(buf);
	}
	cout << "~T2\n";
	T2->print();

	int root;
	cout << "Enter root of resulting tree(T3)\n\t>";
	cin >> root;
	cout << "CREATE2(" << root << "),T1,T2):\n";
	T3 = CREATE2(root,T1,T2);
	cout << "~T3\n";
	T3->print();

	cout << "ROOT(T3):\n"
		<< ROOT(T3)->data << endl;

	int l;
	cout << "Enter argument for LABEL()\n\t>";
	cin >> l;
	cout << "LABEL(" << l << ", T3)\n"
		<< LABEL(l,T3)->data << endl;

	return 0;
}
