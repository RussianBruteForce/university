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

bool ask_writing()
{
	cout << "Write to file?[y/N]\n\t";
	cout.flush();
	char ch;
	cin >> ch;
	if (ch == 'y')
		return true;
	return false;
}

void write_file(string name, double ** matrix, int n, int m)
{
	ofstream file(name,ios::out);
	if (!file) {
		cerr << "Can't open file " << name << '!' << endl;
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			file << matrix[i][j];
		file << '\n';
	}

	file.close();
}

void print_matrix(double ** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < m; j++)
			cout << setw(10) << matrix[i][j] << ' ';
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

	cout << "Select sorting type [b/s/i] (or other to exit): " << endl << "\t> ";
	char st = ' ';
	cin >> st;
	switch (st) {
	case 'b':
		p.sort_rows(matrix,n,m,SortingType::bubble);
		break;
	case 's':
		p.sort_rows(matrix,n,m,SortingType::selection);
		break;
	case 'i':
		p.sort_rows(matrix,n,m,SortingType::insertion);
		break;
	default:
		cout << "bye!" << endl;
		delete_matrix(matrix,n);
		return 0;
		break;
	}
	print_matrix(matrix,n,m);
	cout << "\nProfiler:\n\tSwaps: " << p.get_swaps() << "\tComparison: " << p.get_comparison() << endl;
	if (ask_writing())
		write_file("o",matrix,n,m);
	delete_matrix(matrix,n);

	return 0;
}

