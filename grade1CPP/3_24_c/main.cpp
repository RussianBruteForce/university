#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string read_file(string name)
{
    ifstream file(name,ios::in);
    if (!file) {
        cerr << "Can't open file " << name << '!' << endl;
        exit(0);
    }
    string str;

    file >> str;

    file.close();
    return str;
}

bool is_latin_number(string &str)
{
    for (auto x: str) {
        switch (x) {
        case 'I':
        case 'V':
        case 'X':
        case 'L':
        case 'C':
        case 'D':
        case 'M':
            break;
        default:
            return false;
            break;
        }
    }
    return true;
}

unsigned int get_arab_from_latin(string &str)
{
    unsigned int ret = 0;
    for (auto x: str) {
        switch (x) {
        case 'I':
            ret += 1;
            break;
        case 'V':
            ret += 5;
            break;
        case 'X':
            ret += 10;
            break;
        case 'L':
            ret += 50;
            break;
        case 'C':
            ret += 100;
            break;
        case 'D':
            ret += 500;
            break;
        case 'M':
            ret += 1000;
            break;
        default:
            return 0;
            break;
        }
    }
    return ret;
}

int main()
{
    cout << "Hello World!" << endl;
    cout << "Enter filename to open:\n\t>";
    cout.flush();
    string filename;
    cin >> filename;
    auto str = read_file(filename);

    if (!is_latin_number(str))
        cout << "Error! It's not a latin num!" << endl;
    else {
        auto x = get_arab_from_latin(str);
        cout << "Arab: " << x << endl;
    }

    return 0;
}

