#ifndef DATABASE_H
#define DATABASE_H

#include "list.h"
#include "bus.h"

class DataBase : public List<Bus>
{
public:
    DataBase() : List() {}
    bool take(node *t);
    node *getByID(size_t ID);
    void deleteByID(size_t ID);
    bool print();
};

#endif // DATABASE_H
