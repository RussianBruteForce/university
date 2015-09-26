#include <iostream>
#include "tree.cpp"

using namespace std;

tree::node* leftmost_child(int n, tree* T) {
	tree::node *N = T->root->find(n);
	while (N->l) {
		N = N->l;
	}
	return N;
}

tree::node* right_sibling(int n, tree* T) {
	tree::node *N = T->root->find(n);
	while (N->l) {
		N = N->l;
	}
	return N;
}

tree::node* parent_traverse(tree::node *n, tree::node* T) {
	if(T->l == n || T->r == n)
		return T;
	tree::node *buf = parent_traverse(n,T->l);
	if (buf)
		return buf;
	buf = parent_traverse(n,T->r);
	if (buf)
		return buf;
	return NULL;
}

tree::node* parent(int n, tree* T) {
	tree::node *N = T->root->find(n);
	tree::node *buf = parent_traverse(N,T->root);
	return buf;
}

int main()
{
	tree *T1 = new tree;

	cout << "Tree (T1)\n";
	for (int i = 0; i < 5; i++) {
		cout << "Enter T1[" << i << "]\n\t>";
		int buf = 0;
		cin >> buf;
		T1->add(buf);
	}
	cout << "T1:\n";
	T1->print();

	int buf;
	cout << "Parent of: ";
	cin >> buf;
	tree::node *kek = parent(buf, T1);
	if (!kek)
		cout << "\nNo parents\n";
	else
		cout << "\nParent is: " << kek->data << endl;


	cout << "Most left of: ";
	cin >> buf;
	kek = parent(buf, T1);
	if (!kek)
		cout << "\nNo most left\n";
	else
		cout << "\nMost left is: " << kek->data << endl;

	cout << "Right sibling of: ";
	cin >> buf;
	kek = parent(buf, T1);
	if (!kek)
		cout << "\nNo right sibling\n";
	else
		cout << "\nRight sibling is: " << kek->data << endl;


			return 0;
}

