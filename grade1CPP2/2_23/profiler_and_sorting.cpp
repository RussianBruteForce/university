#include "profiler_and_sorting.h"

profiler_and_sorting::profiler_and_sorting()
{
	reset_profiler();
}

void profiler_and_sorting::sort_rows(double **array, int n, int m, SortingType s)
{
	auto x = get_rows(array,n,m);
	for (size_t i = 0; i < x.size(); i++) {
		if (s == SortingType::bubble) {
			bubble_sorting(x[i],n);
		} else if (s == SortingType::selection){
			selection_sorting(x[i],n);
		} else if (s == SortingType::insertion){
			selection_sorting(x[i],n);
		} else
			break;
		if (i%2 == 0)
			reverse_array(x[i],m);
	}
	//get_array(x,n,array);
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

std::vector<double*> profiler_and_sorting::get_rows(double** array, int n, int m)
{
	std::vector<double*> ret;
	for(int i = 0; i < n; i++) {
		//ret.push_back(new double[m]);
		ret.push_back(array[i]);
		//for (int j = 0; j < m; j++)
		//	ret[i][j]=array[i][j];
	}
	return ret;
}

void profiler_and_sorting::reverse_array(double* array, int size)
{
	for (int i = 0; i < size/2; i++)
		std::swap(array[i], array[size-i-1]);
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
	// внешний цикл. i – позиция первого неотсортированного элемента на данной итерации
	for (int i = 0; i < size - 1; i++) {
		int min = i; // min – позиция минимального элемента
		// внутренний цикл. если найден элемент строго меньший текущего минимального, записываем его индекс как минимальный
		for(int j = i + 1; j < size; j++) {
			p_comparison();
			if(array[j] > array[min])
				min = j;
		}
		if(min != i) {// минимальный элемент не является первым неотсортированным, обмен нужен
			p_swap();
			std::swap(array[i], array[min]);
		}
	}
}

void profiler_and_sorting::insertion_sorting(double* array, int size)
{
	int tmp, item; // индекс предыдущего элемента
	for (int i = 1; i < size; i++)
	{
		tmp = array[i]; // инициализируем временную переменную текущим значением элемента массива
		item = i-1; // запоминаем индекс предыдущего элемента массива
		p_comparison();
		while(item >= 0 && array[item] > tmp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			array[item + 1] = array[item]; // перестановка элементов массива
			p_swap();
			array[item] = tmp;
			item--;
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
