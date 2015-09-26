#ifndef MDEQUE_H
#define MDEQUE_H

#include "mstack.h"

template<class T>
class MDeque : public MStack<T> {
public:
	MDeque() = default;
	void operator > (const T& d) { MStack<T>::operator >>(d); }
	void operator < (const T& d) { this->push_front(d); }
	T operator >> (void *d) { return MStack<T>::operator <<(d);}
	T operator << (void *d) { return pop_front(); }
private:
	void push_front(const T& d)
	{
		this->s.push_front(d);
	}

	T pop_front()
	{
		T r = this->s.front();
		this->s.pop_front();
		return r;
	}
};

#endif // MDEQUE_H
