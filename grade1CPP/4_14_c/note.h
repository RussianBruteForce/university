#ifndef NOTE_H
#define NOTE_H

#include <string>
#include <iostream>

struct NOTE {
    std::string surname, name;
    unsigned long long telephone;
    unsigned short date[3];

    void print() const {
        std::cout << "Фамилия:\t" << surname
                  << "\nИмя:\t\t" << name
                  << "\nТелефон:\t" << telephone
                  << "\nДР:\t\t" << date[0] << '.' << date[1] << '.' << date[2]
                  << std::endl;
    }
    static NOTE readNote() {
        std::string surname, name;
        unsigned long long telephone;
        unsigned short dd,mm,yy;
        std::cout << "Введите фамилию:\n\t>";
        std::cin >> surname;

        std::cout << "Введите имя:\n\t>";
        std::cin >> name;

        std::cout << "Введите телефон:\n\t>";
        std::cin >> telephone;

        std::cout << "Введите ДР (ДД ММ ГГ):\n\t>";
        std::cin >> dd >> mm >> yy;

        return {surname, name, telephone, {dd,mm,yy}};
    }
    bool checkName(std::string name) const {
        if (this->name.compare(name) != 0)
            return false;
        else
            return true;
    }
};

#endif // NOTE_H
