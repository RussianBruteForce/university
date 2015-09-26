#include <iostream>
#include <string>
#include <functional>
#include "doublylinkedlist.h"

using namespace std;


int main()
{
    try {
        DoublyLinkedList<int> il;
        DoublyLinkedList<float> fl;
        DoublyLinkedList<string> sl;

        try {
            auto x = fl;
        } catch (exception &r){
            cerr << r.what() << endl;
        }

        try {
            il.print();
        } catch (exception &r){
            cerr << r.what() << endl;
        }

        try {
            sl.deleteCurrent();
        } catch (exception &r){
            cerr << r.what() << endl;
        }

        try {
            sl.goRight();
        } catch (exception &r){
            cerr << r.what() << endl;
        }

        for (int i = 0 ; i < 10; i++) {
            il.add(666);
            fl.add(6.66);
            sl.add("выапвап");
        }

        il.print();
        fl.print();
        sl.print();

        try {
            il.goLeft();
        } catch (exception &r){
            cerr << r.what() << endl;
        }
        try {
            il.toStart();
        } catch (exception &r){
            cerr << r.what() << endl;
        }

        fl.toEnd();
        try {
            fl.goRight();
        } catch (exception &r){
            cerr << r.what() << endl;
        }
        try {
            fl.toEnd();
        } catch (exception &r){
            cerr << r.what() << endl;
        }
    } catch (...) {
        auto eptr = std::current_exception();
        try {
            if (eptr) {
                std::rethrow_exception(eptr);
            }
        } catch(const std::exception& e) {
            std::cout << "Упустили: " << e.what() << "\n";
        }
    }

    return 0;
}

