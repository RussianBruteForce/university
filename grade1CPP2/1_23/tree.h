#ifndef TREE_H
#define TREE_H

#include <iostream>

class tree
{
public:
	struct node {
		int data;
		node *l, *r;

		node(int data, node *l = nullptr, node *r = nullptr)
		{
			this->data = data;
			this->l = l;
			this->r = r;
		}

		void add(int n)
		{
			if      (n > data){
				if (!r)
					r=new node(n);
				else
					r->add(n);
			} else if (n < data){
				if (!l)
					l=new node(n);
				else
					l->add(n);
			} else
				data = n;
		}

		node *find(int n)
		{
			if (!this)
				return nullptr;

			if (data == n)
				return this;
			else if (n > data)
				return r->find(n);
			else
				return l->find(n);
		}
	};

	tree() : root(nullptr) {}

	void add(int n)
	{
		if (!root)
			root = new node(n);
		else
			root->add(n);
	}

	void print()
	{
		print(root);
	}

	node* root;

private:
	static void print(node *L)
	{
		if (!L)
			return;
		print(L->l);
		std::cout << L->data << std::endl;
		print(L->r);
	}

};

#endif // TREE_H
