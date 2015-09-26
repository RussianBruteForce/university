#include <iostream>
#include <memory>
#include <vector>
#include "order.h"
#include "antifool.h"

using namespace std;

shared_ptr<Order> read_one()
{
    shared_ptr<Order> ret(new Order);

    AntiFool::read(ret->payer_account,"Enter payer account:");

    AntiFool::read(ret->recipient_account, "Enter recipient account:");

    AntiFool::read(ret->amount,"Enter amount:");

    AntiFool::read(ret->currency, "Enter currency:");

    return ret;
}

void print_one(const Order &o)
{
    cout << "###ORDER###\nPAYER:\t\t" << o.payer_account <<
            "\n  RECIPIENT:\t" << o.recipient_account <<
            "\n  AMOUNT:\t\t" << o.amount <<
            "\n  CURRENCY:\t" << o.currency << '\n' << endl;
}

void print_all(const vector<shared_ptr<Order>> &data)
{
    for (auto &x: data)
        print_one(*x);
}

template<typename T>
void buble_sort(T &data)
{
    for(size_t i = 0; i < data.size() - 1; i++)
        for(size_t j = 0; j < data.size() - i - 1; j++)
            if(data[j] < data[j + 1])
                swap(data[j], data[j + 1]);
}

void add_some(vector<shared_ptr<Order>> &data, size_t how)
{
    for (size_t i = 0; i < how; i++)
        data.push_back(read_one());
}

void print_menu()
{
    cout << "###MENU###\n" <<
            "\tq -- for exit\n" <<
            "\tp -- for print\n" <<
            "\ts -- for search\n" << endl;
}

vector<shared_ptr<Order>> search_by_amount(const vector<shared_ptr<Order>> &data,
                             const unsigned int amount)
{
    vector<shared_ptr<Order>> ret;
        for (auto &x: data)
            if (x->amount == amount)
                ret.push_back(x);
        return ret;
}

int main()
{
    vector<shared_ptr<Order>> data;
    add_some(data, 10);
    buble_sort(data);

    while(true) {
        print_menu();
        char ch;
        AntiFool::read(ch);
        switch (ch) {
        case 'q':
            return 0;
            break;
        case 'a':
            data.push_back(read_one());
            break;
        case 'p':
            print_all(data);
            break;
        case 's':
            unsigned int amount;
            AntiFool::read(amount, "Enter amount:");
            print_all(search_by_amount(data, amount));
            break;
        default:
            break;
        }
    }

    return 0;
}

