#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
struct Element
{
	T data;
	Element* next;
	Element* previous;
};

template <class T>
class Spisok
{
private:
	int kolvo;
	Element<T> *begin;
public:
	Spisok();
	~Spisok();
	void showAll();
	T goFirst();
	T goLast();
	void operator >= (T);
	void operator <= (T);
	void operator << (T&);
	void operator >> (T&);
};

template <class T>
Spisok<T>::Spisok()
{
	kolvo = 0;
	begin = NULL;
}

template <class T>
Spisok<T>::~Spisok(){}

template <class T>
void Spisok<T>::showAll()
{
    if (!kolvo)
        throw "Список пуст!";
	Element<T> *tek = begin;
	for (int p = 0; p < kolvo; p++)
	{
		cout << tek->data << " ";
		tek = tek->next;
	}
    cout << "\n\n";
}

template <class T>
void Spisok<T>::operator << (T& output)
{
	if (kolvo == 0)
	{
        throw "Список пуст. Переменная не изменена\n";
	}
	else
	{
		output = goFirst();
	}
}

template <class T>
void Spisok<T>::operator >> (T& output)
{
	if (kolvo == 0)
	{
        throw "Список пуст. Переменная не изменена\n";
	}
	else
	{
		output = goLast();
	}
}

template <class T>
void Spisok<T>::operator >= (T znachenie)
{
	Element<T> *adding = (Element<T>*)malloc(sizeof(Element<T>));
	adding->data = znachenie;
	adding->next = NULL;
	if (kolvo == 0)
	{
		adding->previous = NULL;
		begin = adding;
	}
	else
	{
		Element<T> *tek = begin;
		for (int p = 0; p < kolvo - 1; p++)
		{
			tek = tek->next;
		}
		tek->next = adding;
		adding->previous = tek;
	}
	kolvo++;
}

template <class T>
void Spisok<T>::operator <= (T znachenie)
{
	Element<T> *adding = (Element<T>*)malloc(sizeof(Element<T>));
	adding->data = znachenie;
	adding->previous = NULL;
	if (kolvo == 0)
    {
		adding->next = NULL;
		begin = adding;
	}
	else
	{
		adding->next = begin;
		begin->previous = adding;
		begin = adding;
	}
	kolvo++;
}

template <class T>
T Spisok<T>::goFirst()
{
	T a = begin->data;
	if (kolvo == 1)
	{
		begin = NULL;
	}
	else
	{
		begin = begin->next;
		begin->previous = NULL;
	}
	kolvo--;
	return a;
}

template <class T>
T Spisok<T>::goLast()
{
	T a;
	if (kolvo == 1)
	{
		a = begin->data;
		begin = NULL;
	}
	else
	{
		Element<T> *tek = begin;
		for (int p = 0; p < kolvo - 1; p++)
		{
			tek = tek->next;
		}
		a = tek->data;
		tek = tek->previous;
		tek->next = NULL;
	}
	kolvo--;
	return a;
}
