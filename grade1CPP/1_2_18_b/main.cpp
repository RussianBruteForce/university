#include <iostream>
#include <math.h>

using namespace std;

// a_i =(1+i*a_(i-2))^2
double get_a_i(int n) {
    if (n < 2)
        return 0;
    else if (n == 2)
        return 1;
    else
        return pow((1+n*get_a_i(n-2)), 2);
}

double get_summ(int n) {
    double ret = 0;
    for (int i = 0; i < n; i++)
        ret += get_a_i(i);
    return ret;
}

int main()
{
    unsigned x;
    char ch;
    while(true){
        cout << "Enter n (or q for quit):\n\t>";
        cin.get(ch);
        cin.putback(ch);
        cin >> x;
        if (ch != 'q')
            cout << "Summ to a_n = " << get_summ(x) << endl;
        else
            break;
        cin.ignore(50,'\n');
    }
    return 0;
}

