#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>

void random_array_filling(int *m, const int size, const int min, const int max)
{
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0; i < size; i++)
		m[i] = rand()%abs(max-min+1)+min;
}

void sort_array(int *m, const int size)
{
	printf("\nСортируем массив...");
	fflush(stdout);

	int buf;
	for (int j = 0; j < size; j++) {
		int f = 0;
		int min_ = j;
		for(int i = j; i < (size - j); i++) {
			if (m[i] > m[i + 1]) {
				buf = m[i];
				m[i] = m[i + 1];
				m[i + 1] = buf;
				f = 1;
			}
			if (m[i] < m[min_])
				min_ = i;
		}
		if (f == 0)
			break;
		if (min_ != j) {
			buf = m[j];
			m[j] = m[min_];
			m[min_] = buf;
		}
	}
	printf("\tOK\n");
}

void print_array(int *m, const int size)
{
	printf("\n#Массив: \nДесяток\t  1\t  2\t  3\t  4\t  5\t  6\t  7\t  8\t  9\t  10\n1\t");
	int decade = 1;
	for(int i = 0; i < size; i++) {
		if (m[i] >= 0)
			printf(" ");
		printf("%i\t", m[i]);
		if ((i+1)%10 == 0 && i !=size-1)
			printf("-->\n%i-->\t", ++decade);
	}
	printf("\n#Конец массива\n");
}

void print_last_nonzero(int *m, const int size)
{
	for(int i = size-1; i >= 0; i--)
		if (m[i] == 0) {
			printf("\nПослений не нулевой элемент имеет индекс %i и равен %i",
			       i+1,
			       m[i+1]);
			break;
		}
}

int find_max_repeated_num(int *m, const int size, const int lower_limit, const int upper_limit)
{
	int max_repeat_num = lower_limit-1;
	int buf = m[upper_limit-1];
	for(int i = size-1; i >= 0; i--)
		if (m[i] != buf)
			buf = m[i];
		else {
			max_repeat_num = m[i];
			break;
		}
	return max_repeat_num;
}

int count_zero(int *m, int size)
{
	int zero_count = 0;
	for(int i = 0; i < size; i++)
		if (m[i] == 0)
			zero_count++;
	return zero_count;
}

int maximum_of_negative(int *m, const int size)
{
	for(int i = size-1; i >= 0; i--)
		if (m[i] < 0)
			return m[i];
	return 0;
}

int main(void)
{
	unsigned int size;
	int min, max, buf = 0;
	do {
		printf("Ведите верхнюю и нижнюю границы значений для массива через запятую (min, max): ");

		buf = scanf("%i,%i", &min, &max);
		__fpurge(stdin);
	} while(buf != 2 || max < min);
	do {
		printf("\nВедите размер массива: ");
		buf = scanf("%u", &size);
		__fpurge(stdin);
	} while(buf != 1 || size <= 0);

	int m[size];
	char ans = 'n';
	do {
		printf("\nВвести с клавиатуры? (y\\N): ");
		scanf("%[yYnN]", &ans);
		__fpurge(stdin);
	} while (!(ans == 'y' ||
	           ans == 'Y' ||
	           ans == 'n' ||
	           ans == 'N' ||
	           ans == '\n'));
	if (ans == 'y' ||
	    ans == 'Y') {
		buf = 0;
		for(unsigned int i = 0; i < size; i++) {
			do {
				printf("\nВедите элемент %u (от %i до %i): ",
				       i+1,
				       min,
				       max);
				scanf("%i", &buf);
				__fpurge(stdin);
			} while(buf < min || buf > max);
			m[i] = buf;
			printf("\nЭлемент %i = %i", i+1, buf);
		}
	} else {
		printf("\n*** Массив будет заполнен случайно ***\n");
		random_array_filling(m, size, min, max);
	}
	printf("\n*** Массив заполнен ***\n");
	print_array(m, size);

	print_last_nonzero(m , size);

	sort_array(m, size);
	//print_array(m, size);

	printf("\nКол-во нулей: %i\n", count_zero(m, size));

	buf = find_max_repeated_num(m, size, min, max);
	if (buf != min-1)
		printf("\nМакс. повторяющееся число: %i\n", buf);
	else printf("\nПовторяющихся чисел нет.\n");

	buf = maximum_of_negative(m, size);
	if (buf)
		printf("\nМакс. отрицательное число в массиве: %i\n", buf);
	else
		printf("\nОтрицательных чисел в массиве нет.\n");

	return 0;
}
