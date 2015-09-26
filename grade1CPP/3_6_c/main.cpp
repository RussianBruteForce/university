#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "sdfgsdfsdfxertertertert";

    cout << str << endl;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == 'x') {
            str.erase(i,1);
            str.insert(i,"ks");
            break;
        }
    }
    cout << str << endl;
    return 0;
}

