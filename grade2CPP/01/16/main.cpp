#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "profiler_and_sorting.h"

using namespace std;

double ** read_file(string name, int &n, int &m)
{
    ifstream file(name,ios::in);
    if (!file) {
        cerr << "Can't open file " << name << '!' << endl;
        exit(0);
    }

    file >> n >> m;

    auto x = new double*[n];
    for (int i = 0; i < n; i++) {
        x[i] = new double[m];
        for (int j = 0; j < m; j++)
           file >> x[i][j];
    }

    file.close();
    return x;
}

void print_matrix(double ** matrix, int n, int m)
{
    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < m; j++)
            cout << setw(6) << matrix[i][j] << ' ';
    }
    cout << endl;
}

void delete_matrix(double ** matrix, int n)
{
    for(int i = 0; i < n-1; i++)
        delete [] matrix[i];
    delete [] matrix;
}

int main()
{
    int n,m;
    string filename;
    cout << "Write file name: " << endl << "\t> ";
    cin >> filename;
    auto matrix = read_file(filename,n,m);

    cout << "Read the matrix " << n << "×" << m << endl;

    print_matrix(matrix,n,m);
    profiler_and_sorting p;


    cout << "Select sorting type [b/s]: " << endl << "\t> ";
    char st = ' ';
    while (cin >> st) {
        if (st == 'b') {
            p.sort_columns(matrix,n,m,SortingType::bubble);
            break;
        } else if (st == 's') {
            p.sort_columns(matrix,n,m,SortingType::selection);
            break;
        } else
            cout << "Select sorting type [b/s]: " << endl << "\t> ";
    }

    print_matrix(matrix,n,m);
    cout << "\nProfiler:\n\tSwaps: " << p.get_swaps() << "\tComparison: " << p.get_comparison() << endl;
    delete_matrix(matrix,n);
    return 0;
}

