#include "profiler_and_sorting.h"

profiler_and_sorting::profiler_and_sorting()
{
    reset_profiler();
}

void profiler_and_sorting::sort_columns(double **array, int n, int m, SortingType s)
{
    auto x = get_columns(array,n,m);
    for (auto *i: x) {
        if (s == SortingType::bubble) {
            bubble_sorting(i,n);
        } else {
            selection_sorting(i,n);
        }
    }
    get_array(x,n,array);
}

void profiler_and_sorting::reset_profiler()
{
    swaps = comparison = 0;
}

unsigned int profiler_and_sorting::get_swaps()
{
    return swaps;
}

unsigned int profiler_and_sorting::get_comparison()
{
    return comparison;
}

std::vector<double *> profiler_and_sorting::get_columns(double **array, int n, int m)
{
    std::vector<double*> ret;
    for(int i = 0; i < m; i++) {
        ret.push_back(new double[n]);
        for (int j = 0; j < n; j++)
            ret[i][j]=array[j][i];
    }
    return ret;
}

void profiler_and_sorting::get_array(std::vector<double *> c, int n, double **array)
{
    for(std::size_t i = 0; i < c.size(); i++) {
        for (int j = 0; j < n; j++)
            array[j][i] = c[i][j];
    }
}

void profiler_and_sorting::bubble_sorting(double *array, int size)
{
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++) {
            p_comparison();
            if(array[j] < array[j + 1]) {
                p_swap();
                std::swap(array[j], array[j + 1]);
            }
        }
}

void profiler_and_sorting::selection_sorting(double *array, int size)
{
    /* внешний цикл. i – позиция первого неотсортированного элемента на данной итерации */
    for (int i = 0; i < size - 1; i++) {
        int min = i; /* min – позиция минимального элемента */
        /* внутренний цикл. если найден элемент строго меньший текущего минимального, записываем его индекс как минимальный */
        for(int j = i + 1; j < size; j++) {
            p_comparison();
            if(array[j] > array[min])
                min = j;
        }
        if(min != i) {/* минимальный элемент не является первым неотсортированным, обмен нужен */
            p_swap();
            std::swap(array[i], array[min]);
        }
    }
}

void profiler_and_sorting::p_swap()
{
    swaps++;
}

void profiler_and_sorting::p_comparison()
{
    comparison++;
}
