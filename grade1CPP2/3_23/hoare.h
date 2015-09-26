#ifndef HOARE_H
#define HOARE_H

#include "profiler_and_sorting.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

class Hoare : public profiler_and_sorting {
public:
	Hoare();
	Hoare(std::string fname);
	void print();
	void qsort(size_t first, size_t step);
	size_t size();

private:
	std::vector<double> m;
	void sort(std::vector<double>& arr, size_t left, size_t right);
};

Hoare::Hoare() : profiler_and_sorting()
{
	reset_profiler();
	srand(time(NULL));
	for (size_t i = 0; i < SIZE; i++)
		m.push_back((double)rand()/rand());
}

Hoare::Hoare(std::string fname) : profiler_and_sorting()
{
	reset_profiler();
	std::ifstream file(fname, std::ios::in);
	if (!file) {
		std::cerr << "Can't open file " << fname << '!' << std::endl;
		exit(0);
	}

	while (!file.eof()) {
		double buf;
		file >> buf;
		m.push_back(buf);
	}

	file.close();
}

void Hoare::sort(std::vector<double> &arr, size_t left, size_t right)
{
	if (right >= m.size())
		right = m.size() - 1;
	size_t i = left, j = right;
	double pivot = m[(left + right) / 2];
	//double pivot = rand() % (right - left) + left +1;

	while (i <= j) {
		while (m[i] < pivot) {
			p_comparison();
			i++;
		}
		while (m[j] > pivot) {
			p_comparison();
			j--;
		}
		if (i <= j) {
			p_swap();
			std::iter_swap(m.begin() + i, m.begin() + j);
			if (!(i== right))
				i++;
			if (j!=0)
				j--;
		}
	};

	if (left < j)
		sort(m, left, j);
	if (i < right)
		sort(m, i, right);
}


void Hoare::print()
{
	std::cout << "*** Array start ***\n";
	for (auto &x: m)
		std::cout << std::setw(10) << x << std::endl;
	std::cout << "*** Array end ***\n";
}

void Hoare::qsort(size_t first, size_t step)
{
	srand(time(NULL));
	std::cerr << "S" << std::endl;
	//sort(m,first,m.size()-1);
	if (first + step >= m.size())
		return;
	std::cerr << "X" << std::endl;
	for (size_t i = first+step; i <= m.size(); i += step)
		sort(m,i-step,i-1);
}

size_t Hoare::size()
{
	return m.size();
}

#endif // HOARE_H
