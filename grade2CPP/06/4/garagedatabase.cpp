#include "garagedatabase.h"


void GarageDataBase::readFile(std::string filename)
{
    std::ifstream file(filename,std::ios::in);
    if (!file) {
        std::cerr << "Can't open file " << filename << '!' << std::endl;
        exit(0);
    }
    std::cout << "Читаем файл…";

    while(!file.eof()) {
        size_t id = 0, route = 0;
        char driver[32];
        file >> id >> driver >> route;

        Bus buf;
        buf.id = id;
        strcpy(buf.driver, driver);
        buf.route = route;
        add(buf);
    }

    file.close();
    std::cout << "\tГотово!" << std::endl;
}
