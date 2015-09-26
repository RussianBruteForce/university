#include <iostream>

using namespace std;

void F(int v, int A[], int m) {
    int i,n,a;
    for (i = 0, a = 2; a < v && i<m-1;a++){
        for (n = 2; n < a;n++) {
            if(a%n == 0)
                break;
        }
        if (n == a) A[i++]=a;
    }
    A[i] = 0;
}

void print(int A[]) {
    int i=0;
    while (i != 10)
        cout << A[i++] << ' ';
    cout <<endl;
}

int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    print(A);
    F(4,A,5);
    print(A);
    return 0;
}

