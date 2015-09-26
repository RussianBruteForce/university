#ifndef PROFILER_AND_SORTING_H
#define PROFILER_AND_SORTING_H

#include <utility>
#include <vector>

enum class SortingType {
    bubble,
    selection
};

class profiler_and_sorting
{
public:
    profiler_and_sorting();
    void sort_columns(double ** array, int n, int m, SortingType s);
    void reset_profiler();
    unsigned int get_swaps();
    unsigned int get_comparison();
private:
    unsigned int swaps, comparison;
    std::vector<double*> get_columns(double ** array, int n, int m);
    void get_array(std::vector<double*> c, int n, double ** array);
    void bubble_sorting(double *array, int size);
    void selection_sorting(double *array, int size);
    void p_swap();
    void p_comparison();
};

#endif // PROFILER_AND_SORTING_H
