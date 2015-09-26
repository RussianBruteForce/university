#include <iostream>

using namespace std;

int main()
{

    const int k = 5, l = 6;
    int x[k] = {1,4,5,6,7}, y[l]={54,2,1,7,32,-4};

    int counter = 0;
    for (int i =0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            if (x[i] == y[j]) {
                counter += 1;
            }
        }
    }

    cout << "Совпадающих " << counter << endl;
    return 1;
}
