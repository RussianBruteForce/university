#ifndef GARAGEDATABASE_H
#define GARAGEDATABASE_H

#include "database.h"
#include <string>
#include <fstream>
#include <cstring>

class GarageDataBase : public DataBase
{
public:
    GarageDataBase() = delete;
    GarageDataBase(std::string filename) : DataBase(){
        readFile(filename);
    }
private:
    void readFile(std::string filename);
};

#endif // GARAGEDATABASE_H
