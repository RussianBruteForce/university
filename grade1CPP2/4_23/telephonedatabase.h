#ifndef TELEPHONEDATABASE_H
#define TELEPHONEDATABASE_H

#include "doublylinkedlist.h"
#include <fstream>
#include <string>

#define TARIFF 13

struct user{
	std::string surname;
	unsigned long telephone;
	unsigned long time;
};

class TelephoneDataBase : public DoublyLinkedList<user>
{
public:
	TelephoneDataBase(std::string file) : DoublyLinkedList() {readFromFile(file);}
	TelephoneDataBase() = delete;
	void print();
	void printUser(std::string surname);
	void printBill(unsigned long telephone);
	void setTime(unsigned long telephone, unsigned long time);
	void incTime(std::string surname, unsigned long time);
	static std::string timeToString(unsigned long time);
	static unsigned long HMSToTime(size_t h, size_t m, size_t s);
private:
	node* findUser(std::string surname);
	node* findUser(unsigned long telephone);
	void readFromFile(std::string fname);
};

#endif // TELEPHONEDATABASE_H
