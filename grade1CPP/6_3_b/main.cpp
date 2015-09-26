#include <iostream>

using namespace std;

struct llist {
    int val;
    llist *next, *pred;
};

llist *fun(llist *z, int n)
{
    llist *q;
    for (q=z; n != 0; q = q->next, n--);
    if (q->next==q){delete q; return NULL;}
    if (q==z)z=q->next;
    q->pred->next = q->next;
    q->next->pred = q->pred;
    delete q;
    return z;
}

int main()
{
    llist a,b,c, *ph;
    a={3,&b,NULL};
    b={2,&c,&a};
    c={1,NULL,&b};
    ph = &c;
    cout << "vyvod: " <<fun(ph,0) << endl;
    return 0;
}

