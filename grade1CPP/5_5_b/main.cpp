#include <iostream>

using namespace std;

struct listt {
    int val;
    listt * next;
};

int FF(listt *z)
{
    int k; listt *q;
    if (z == NULL) {
        return 0;
    }
    for (q=z, z=z->next, k = 1; z!=q; k++, z = z->next);
    return k;
}

int main()
{
    listt a={3,NULL},b={2,&a},c={1,&b},*ph=&c;
    int x = 0;
    x = FF(ph);
    cout << x << endl;
    return 0;
}

