#ifndef PROFILER_AND_SORTING_H
#define PROFILER_AND_SORTING_H

#include <vector>
#include <iostream>

enum class SortingType {
	bubble,
	selection,
	insertion
};

class profiler_and_sorting
{
public:
	profiler_and_sorting();
	void sort_rows(double ** array, int n, int m, SortingType s = SortingType::bubble);
	void reset_profiler();
	unsigned int get_swaps();
	unsigned int get_comparison();
private:
	unsigned int swaps, comparison;
	static std::vector<double*> get_rows(double ** array, int n, int m);
	static void reverse_array(double *array, int size);
	void bubble_sorting(double *array, int size);
	void selection_sorting(double *array, int size);
	void insertion_sorting(double *array, int size);
	void p_swap();
	void p_comparison();
};

#endif // PROFILER_AND_SORTING_H
