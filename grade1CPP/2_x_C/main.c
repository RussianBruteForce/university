#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int **malloc_square_matrix(size_t size)
{
    int **m = (int**)malloc(sizeof(int*)*size);
    for (size_t i = 0; i < size; i++)
        m[i] = (int*)malloc(sizeof(int)*size);
    return m;
}

void fill_square_matrix(int **m, size_t size, int min, int max)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            m[i][j] = rand()%abs(max-min+1)+min;
}

void free_square_matrix(int **m, size_t size)
{
    for (size_t i = 0; i < size; i++)
        free(m[i]);
    free(m);
}


void print_square_matrix(const int **m, size_t size)
{
    printf("Matrix %lux%lu\n#\t", size, size);
    for (size_t i = 0; i < size; i++)
        printf("*%lu\t", i);

    printf("\n\n");
    for (size_t i = 0; i < size; i++) {
        printf("*%lu\t", i);
        for (size_t j = 0; j < size; j++) {
            printf(" %i\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


long sum_str(const int *str, size_t size)
{
    long counter = 0;
    for (size_t i = 0; i < size; i++)
        counter += str[i];

    return counter;
}

int is_negative_str(const int *str, size_t size)
{
    for (size_t i = 0; i < size; i++)
        if (str[i] < 0)
            return 1;
    printf("got not_neg\n");
    return -1;
}

long sum_of_negative_str(const int **m, size_t size)
{
    long sum = 0;
    for (size_t i = 0; i < size; i++)
        if (is_negative_str(m[i], size))
            sum += sum_str(m[i], size);
    return sum;
}

size_t last_column_witout_zero(const int **m, size_t size)
{
    for (size_t j = size; j > 0; j--) {
        for (size_t i = 0; i < size; i++) {
            if (m[i][j] == 0)
                break;
            else if (i == size -1)
                return j;
        }
    }
    return size;
}

int main(void)
{
    size_t n;
    int max;
    printf("Enter n and boundary value (through the gap):\n\t>");
    scanf("%lu %i", &n, &max);
    int ** m = malloc_square_matrix(n);

    fill_square_matrix(m, n, -max, max);
    print_square_matrix((const int **)m, n);

    long s = sum_of_negative_str((const int**)m, n);
    printf("Summ of elements at rows with at least negative element %li\n", s);

    size_t c = last_column_witout_zero((const int**)m, n);
    if (c != n)
        printf("Last column witout zero have index is %lu\n", c);
    else
        printf("There is no columns witout zero!\n");


    free_square_matrix(m, n);
    return 0;
}

