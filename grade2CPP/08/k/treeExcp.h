#ifndef TREEEXCP_H
#define TREEEXCP_H

#include <iostream>
#include <exception>

using namespace std;

class empty_tree_deleting : public exception {
public:
	virtual const char* what() const noexcept override {
		return "Удаление из пустого списка!\n";
	}
};
class empty_tree_printing : public exception {
public:
	virtual const char* what() const noexcept override {
		return "Вывод пустого списка!\n";
	}
};
#endif // TREEEXCP_H
