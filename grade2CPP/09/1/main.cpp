#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;


    matrix a,b;

    vector<vector<int> > i = {{1,2,3},
                              {4,5,6},
                              {7,8,9}};
    vector<vector<int> > j = {{1,2,3},
                              {4,5,6},
                              {7,8,9}};
    a.setData(i);
    b.setData(j);
    //cin >> m;
    cout << a << "\n" <<  b;
    cout << "summ:\n" << a+b;
    cout << "mult:\n" << a*b;
    return 0;
}

