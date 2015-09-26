#include <iostream>

using namespace std;

unsigned my_abs(int x){
    if (x < 0)
        return -x;
    else
        return x;
}

unsigned f(int x){
    return my_abs(my_abs(2*x+3)-1);
}

int main()
{
    int x;
    char ch;
    while (true) {
        cout << "Enter 'x' (or q for exit):\n\t>";
        cin.get(ch);
        cin.putback(ch);
        cin >> x;
        if (ch != 'q')
            cout << "f(" << x << ") = " << f(x) << endl;
        else
            break;
        cin.ignore(50, '\n');
    }
    return 0;
}

