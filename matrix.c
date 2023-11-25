#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

void calc();
int **createArray(int rows, int cols);
void initializeArray(int rows, int cols, int **array);
void printArray(int rows, int cols, int **array);
void freeArray(int rows, int **array);
int **product(int M, int N, int L, int **matA, int **matB);
double getElapsedTImeInMicroSeconds();

int main()
{
    // Obtain seconds in microseconds to avoid loss of digits
    double start_time = getElapsedTImeInMicroSeconds();

    calc();

    double end_time = getElapsedTImeInMicroSeconds();
    double tdiff = end_time - start_time;

    // Convert microseconds to seconds
    printf("%lf\n", tdiff / 1000000);

    return 0;
}

void calc()
{
    int m = 100;
    int n = 100;
    int l = 100;

    int **matA = createArray(m, n);
    int **matB = createArray(n, l);

    // Initialize each element of the matrix
    // with a random number from 0 to 99
    initializeArray(m, n, matA);
    initializeArray(n, m, matB);

    int **matC = product(m, n, m, matA, matB);

    printArray(m, l, matC);

    freeArray(m, matA);
    freeArray(n, matB);
    freeArray(m, matC);
}

int **createArray(int rows, int cols)
{
    int **array = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    return array;
}

void initializeArray(int rows, int cols, int **array)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = rand() % 100;
        }
    }
}

void printArray(int rows, int cols, int **array)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void freeArray(int rows, int **array)
{
    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}

int **product(int M, int N, int L, int **matA, int **matB)
{
    int **matC = createArray(M, M);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < L; j++)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
            {
                sum += matA[i][k] * matB[k][j];
            }
            matC[i][j] = sum;
        }
    }

    return matC;
}

double getElapsedTImeInMicroSeconds()
{
    struct timeval timer;
    gettimeofday(&timer, NULL);

    // tv_usec is microseconds
    return (double)timer.tv_sec * 1000000 + timer.tv_usec;
}