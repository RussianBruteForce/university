#include <iostream>
#include <cstdlib>

// не мой код, честно

using namespace std;

void bubbleSort(int* arr, int size)
{
    int tmp, i, j;

    for(i = 0; i < size - 1; ++i) // i - номер прохода
    {
        for(j = 0; j < size - 1; ++j) // внутренний цикл прохода
        {
            if (arr[j + 1] < arr[j])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int main() {
    int n,m;
    cout <<("Enter N \n");
    cin >>n;
    cout<<(": Enter M:\n");
    cin>>m;

    int i,j,k=0;
    int** ma=new int *[n];
    for(i=0;i<n;i++) ma[i]=new int[m];

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ma[i][j] = rand()%10;
            if (rand()%2)
                ma[i][j] *= -1;
        }
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
            cout << ma[i][j]<<" ";
        cout << " \n";
    }
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            if ((ma[i][j]==0) && ma[i][j-i]!=ma[i][j]) k++;
        }
    }
    cout <<"columns with 0: "<< k<< endl;

//    int r, d = 0;
//    for(i=0;i<n;i++){
//        for(j=0;j<m;j++){
//            int* l = new int;
//            for ( r=0; r<d; r++) {
//                l[d] = ma[i][j] ;
//                if (l[d]==10) h++;

//            }

//            cout << " | " <<  l[d] << " | ";

//        } } cout << "Pov : "<< h << endl;
    int x[m*n];
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            x[i*m+j] = ma[i][j];

    bubbleSort(x,n*m);


    for (int i = 1; i < n*m; i++) {
        if (x[i] == x[i-1]) {
            cout << "Min pov: " << x[i] << endl;
            break;
        }
    }
    for(i=0;i<n;i++) delete [] ma[i];
    delete [] ma;
    return 0;
}
