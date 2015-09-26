#include <iostream>
#include <string>
#include "garagedatabase.h"
#include "list.h"
#include "antifool.h"

using namespace std;

void askAndAddBus(GarageDataBase &db)
{
    size_t id = 0, route = 0;
    string driver;
    AntiFool::read(id, "Введите уникальный номер автобуса");
    AntiFool::read(driver,"Введите водителя");
    AntiFool::read(route, "Введите маршрут");
    Bus b;
    b.id = id;
    strcpy(b.driver, driver.c_str());
    b.route = route;

    db.add(b);
}

int main()
{
    GarageDataBase db1("w");
    DataBase db2;

    while(true) {
            size_t id = 0;
            char choice = 'q';
            cout << "\nМеню!" << endl;
            cout << "\tg Показать гараж" << endl;
            cout << "\tp Показать автобусы в пути" << endl;
            cout << "\ta Создать автобус в гараже" << endl;
            cout << "\td Уничтожить автобус в гараже" << endl;
            cout << "\tw Отправить автобус из гаража" << endl;
            cout << "\te Вернуть автобус в гараж" << endl;
            cout << "\tq для выхода" << endl;
            cout << "\t>";
            AntiFool::read(choice);
            switch (choice) {
            case 'g':
                if (!db1.print())
                    cout << "Нет аввтобусов в гараже!" << endl;
                break;
            case 'p':
                if (!db2.print())
                    cout << "Нет автобусв в пути!" << endl;
                break;
            case 'a':
                askAndAddBus(db1);
                break;
            case 'd':
                AntiFool::read(id, "Введите номер автобуса");
                db1.deleteByID(id);
                break;
            case 'w':
                AntiFool::read(id, "Введите номер автобуса");
                if (!db2.take(db1.getByID(id)))
                    cout << "Нет такого автобуса в гараже!" << endl;
                break;
            case 'e':
                AntiFool::read(id, "Введите номер автобуса");
                if (!db1.take(db2.getByID(id)))
                    cout << "Нет такого автобуса в пути!" << endl;
                break;
            case 'q':
                cout << "пока!" << endl;
                return 0;
                break;
            default:
		cout << "выбирать надо из того,ч то дают! :P" << endl;
                break;
            }
    }

    return 0;
}

