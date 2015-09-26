#ifndef MSTACK_H
#define MSTACK_H

#include <deque>
#include <iostream>

template<class T>
class MStack
{
public:
	MStack() = default;
	void operator >> (const T& d) { push_back(d); }
	T operator << (void *d) { return pop_back(); }
	void print();

protected:
	void push_back(const T& d)
	{
		s.push_back(d);
	}

	T pop_back() {
		T r = s.back();
		s.pop_back();
		return r;
	}

	std::deque<T> s;
};

#endif // MSTACK_H

template <class T>
void MStack<T>::print()
{
	std::cout << "Printing:" << std::endl;
	for (auto &x: s)
		std::cout << x << std::endl;
}
