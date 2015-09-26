#include <stdio_ext.h>
#include <malloc.h>
#include "../in.h"

#define AUTO
#define MAX_FILE_NAME_LENGHT 255
typedef unsigned int _alenght;

int **malloc_square_matrix(const _alenght n)
{
	int **m = (int**)malloc(sizeof(int*)*n);
	for (_alenght i = 0; i < n; i++)
		m[i] = (int*)malloc(sizeof(int)*n);
	return m;
}

#ifdef AUTO
void auto_fill_square_matrix(FILE *f, int **m, const _alenght n)
{
	for (_alenght i = 0; i < n; i++) {
		for (_alenght j = 0; j < n; j++)
			fscanf(f, "%i", &m[i][j]);
		fgetc(f);
	}
}

#endif //AUTO

void free_square_matrix(int **m, const _alenght size)
{
	for (_alenght i = 0; i < size; i++)
		free(m[i]);
	free(m);
}

void manual_fill_square_matrix(int **m, const _alenght n)
{
	for (_alenght i = 0; i < n; i++) {
		for (_alenght j = 0; j < n; j++) {
			int buf;
			char str[50];
			sprintf(str, "\nВведите значение для A[%i][%i]: ",
				i,
				j);
			get_int(str, &buf);
			m[i][j] = buf;
			printf("A[%i][%i] = %i", i, j, m[i][j]);
		}
	};
}

void fill_square_matrix(int **m, const _alenght n)
{
	for (_alenght i = 0; i < n; i++)
		for (_alenght j = 0; j < n; j++)
			m[i][j] = 666;
}

void fill_square_identity_matrix(int **m, const _alenght n)
{
	for (_alenght i = 0; i < n; i++)
		for (_alenght j = 0; j < n; j++)
			if (j != i)
				m[i][j] = 0;
			else
				m[i][j] = 1;
}

void print_square_matrix(const int **m, const _alenght size)
{
	printf("\nМатрица %ix%i\n№\t", size, size);
	for (_alenght i = 0; i < size; i++)
		printf("*%i\t", i);
	printf("\n\n");
	for (_alenght i = 0; i < size; i++) {
		printf("*%i\t", i);
		for (_alenght j = 0; j < size; j++) {
			printf(" %i\t", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int **same_size_square_matrix_multiplication(const int **a, const int **b, const _alenght n)
{
	int **c = malloc_square_matrix(n);
	for (_alenght i = 0; i < n; i++)
		for (_alenght j = 0; j < n; j++) {
			c[i][j] = 0;
			for(_alenght r = 0; r < n; r++)
				c[i][j] +=
				                a[i][r]
				                *
				                b[r][j];
		}
	return c;
}

int **same_size_square_matrix_substraction(const int **a, const int **b, const _alenght n)
{
	int **c = malloc_square_matrix(n);
	for (_alenght i = 0; i < n; i++)
		for (_alenght j = 0; j < n; j++)
			c[i][j] =
			                a[i][j]
			                -
			                b[i][j];
	return c;
}

void square_matrix_multiplication_by_constant(int _const, int **m, const _alenght n)
{
	for (_alenght i = 0; i < n; i++)
		for (_alenght j = 0; j < n; j++)
			m[i][j] *= _const;
}

int main(void)
{
	_alenght n = 0;
#ifndef AUTO
	long long x = 0;
	do {
		get_long("Введите порядок матрицы А: ", &x);
	} while (x < 0);
	n = x;
#else //AUTO
	FILE *input_file = NULL;
	char *f_name = (char *)malloc(MAX_FILE_NAME_LENGHT + 1);
	do {
		printf("\nВведите имя файла со строкой: ");
		while (scanf("%s", f_name) != 1) {
			printf("\nВведите имя файла со строкой: ");
			__fpurge(stdin);
		}
	} while ((input_file = fopen(f_name,"r")) == NULL);
	free(f_name);
	fscanf(input_file, "%u", &n);
	fgetc(input_file);
#endif //AUTO
	int **m = malloc_square_matrix(n);
	int **e = malloc_square_matrix(n);
#ifndef AUTO
	manual_fill_square_matrix(m, n);
#else //AUTO
	auto_fill_square_matrix(input_file, m, n);
	fclose(input_file);
#endif //AUTO
	//fill_square_matrix(m, n); //debug function
	fill_square_identity_matrix(e, n);
	square_matrix_multiplication_by_constant(3, e, n);
	int **s = same_size_square_matrix_substraction((const int**)m,
	                                               (const int**)e,
	                                               n);
	free_square_matrix(m, n);
	free_square_matrix(e, n);
	int **f = same_size_square_matrix_multiplication((const int**)s,
	                                                 (const int**)s,
	                                                 n);
	free_square_matrix(s, n);
	printf("\nРезультрующая матрица:");
	print_square_matrix((const int**)f, n);
	free_square_matrix(f, n);
	return 0;
}
