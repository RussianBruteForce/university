#ifndef TREE_H
#define TREE_H

#include <iostream>

template <class T>
class Tree {
public:
	const Tree& operator+(const Tree& i){
		uint key, v;
		std::cout << "Enter pair key-value:\n\t>";
		std::cin >> key >> v;
		this->Add(key,v);
		return i;
	}

	const Tree& operator-(const Tree& i){
		uint key;
		std::cout << "Enter key:\n\t>";
		std::cin >> key;
		this->Del(this->root, key);
		return i;
	}

	struct Node {
		Node (uint k, T d, Node *lC, Node *rC)
		{
			key = k;
			data = d;
			lChild = lC;
			rChild = rC;
		}

		uint key;
		T data;
		Node *lChild, *rChild;
	};
	Tree();
	~Tree();

	void Add(uint key, T value);
	void Add(uint key, T value, Node* L);
	int Del(Node *target, uint key, Node *parent = nullptr);
	void Print();
	void Print(Node* L);
	Node *root;
private:
	static Node* findMaxNodeRec(Node *target) {
		if (!target)
			return target;
		if (target->rChild)
			return findMaxNodeRec(target->rChild);
		return target;
	}
	static Node* findMinNodeRec(Node *target) {
		if (!target)
			return target;
		if (target->lChild)
			return findMinNodeRec(target->lChild);
		return target;
	}
	static void recDel(Node *target) {
		if (target->lChild)
			recDel(target->lChild);
		else if (target->rChild)
			recDel(target->rChild);
		delete target;
	}
};

template <class T>
Tree<T>::Tree() {
	root = nullptr;
}
template <class T>
Tree<T>::~Tree() {
	recDel(root);
}

template <class T>
void Tree<T>::Add(uint key, T value) {
	if (!root)
		root  = new Node(key, value, nullptr, nullptr);
	else
		Add(key,value,root);
}

template <class T>
void Tree<T>::Add(uint key, T value, Node *L) {
	if (L == nullptr)
		L = new Node(key, value, nullptr, nullptr);
	else if (key > L->key) {
		if (!L->rChild)
			L->rChild = new Node(key, value, nullptr, nullptr);
		else
			Add(key, value, L->rChild);
	} else if (key < L->key) {
		if (!L->lChild)
			L->lChild = new Node(key, value, nullptr, nullptr);
		else
			Add(key, value, L->lChild);
	} else
		L->data = value;
}

template <class T>
int Tree<T>::Del(Node *target, uint key, Node *parent) {
	if (!root)
		return 0;
	if (target->key > key) {
		Del(target->lChild, key, target);
	} else if (target->key < key) {
		Del(target->rChild, key, target);
	} else {
		if (target->lChild && target->rChild) {
		} else if (target->lChild) {
			auto localMax = findMaxNodeRec(target->lChild);
			target->key = localMax->key;
			Del(target->lChild, localMax->key, target);
		} else if (target->rChild) {
			if (target->lChild == parent) {
				parent->lChild = target->rChild;
			} else {
				parent->rChild = target->rChild;
			}
			delete target;
		} else {
			if (!parent) {
				delete target;
				root = nullptr;
				return 2;
			}
			if (parent->lChild == target) {
				parent->lChild = nullptr;
			} else {
				parent->rChild = nullptr;
			}
			delete target;
		}
	}
	return 1;
}

template <class T>
void Tree<T>::Print()
{
	Print(root);
}

template <class T>
void Tree<T>::Print(Node *L)
{
	if (!L)
		return;
	Print(L->lChild);
	std::cout << "Key: " << L->key << "  \tData: " << L->data << std::endl;
	Print(L->rChild);
}

#endif // TREE_H
