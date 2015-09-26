#include "telephonedatabase.h"

void TelephoneDataBase::print()
{
	node *buf = firstNode;
	size_t c = 0;
	while (buf) {
		std::cout << "\n*** user " << c++ << " ***\n" <<
			     "Surname: " << buf->data.surname << "\n" <<
			     "Telephone: " << buf->data.telephone << "\n" <<
			     "Time calls: " << timeToString(buf->data.time) << std::endl;
		buf = buf->next;
	}
}

void TelephoneDataBase::printUser(std::string surname)
{
	if (auto buf = findUser(surname))
		std::cout << "Telephone: " << buf->data.telephone << "\n" <<
			     "Time calls: " << timeToString(buf->data.time) << std::endl;
	else
		std::cout << "No such user!" << std::endl;
}

void TelephoneDataBase::printBill(unsigned long telephone)
{

	if (auto buf = findUser(telephone))
		std::cout << "Surname: " << buf->data.surname << "\n" <<
			     "Phone bill: " << TARIFF*buf->data.time <<
			     "$" << std::endl;
	else
		std::cout << "No such phone!" << std::endl;
}

void TelephoneDataBase::setTime(unsigned long telephone, unsigned long time)
{
	if (auto buf = findUser(telephone))
		buf->data.time = time;
	else
		std::cout << "No such phone!" << std::endl;
}

void TelephoneDataBase::incTime(std::string surname, unsigned long time)
{
	if (auto u = findUser(surname))
		u->data.time += time;
	else
		std::cout << "No such user!" << std::endl;
}

std::string TelephoneDataBase::timeToString(unsigned long time)
{
	std::string s;
	s.append(std::to_string(time/60/60));
	s.append(":");
	s.append(std::to_string(time/60%60));
	s.append(":");
	s.append(std::to_string(time%60%60));
	return s;
}

unsigned long TelephoneDataBase::HMSToTime(size_t h, size_t m, size_t s)
{
	return static_cast<unsigned long>(h)*60*60+static_cast<unsigned long>(m)*60+s;
}

DoublyLinkedList<user>::node*TelephoneDataBase::findUser(std::string surname)
{
	node *buf = firstNode;
	for (size_t i = 0; i < count; i++) {
		if (buf->data.surname == surname)
			return buf;
		buf = buf->next;
	}
	return nullptr;
}

DoublyLinkedList<user>::node*TelephoneDataBase::findUser(unsigned long telephone)
{
	node *buf = firstNode;
	for (size_t i = 0; i < count; i++) {
		if (buf->data.telephone == telephone)
			return buf;
		buf = buf->next;
	}
	return nullptr;
}

void TelephoneDataBase::readFromFile(std::string fname)
{
	std::ifstream file(fname, std::ios::in);
	if (!file) {
		std::cerr << "Can't open file " << fname << '!' << std::endl;
		exit(0);
	}

	while (!file.eof()) {
		std::string s;
		unsigned long p, t;
		file >> s >> p >> t;
		add({s,p,t});
	}

	file.close();
}
