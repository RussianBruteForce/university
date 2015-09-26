#include <iostream>
#include <string>
#include "antifool.h"

using namespace std;


int main()
{
    char ch;
    int i;
    uint ui;
    string str;

    AntiFool::read(ch,"char");
    cout << ch << endl;

    cout << "INT: " << endl;
    AntiFool::read(i);
    cout << i << endl;

    AntiFool::read(ui,"unsigned");
    cout << ui << endl;

    AntiFool::read(str,"string");
    cout << str << endl;
    return 0;
}

