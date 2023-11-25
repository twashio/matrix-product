import time
import numpy as np
import random


def main():
    start_time = time.time()

    m = 100
    n = 100
    l = 100

    # Initialize each element of the matrix
    # with a random number from 0 to 99
    matA = np.ndarray((m, n))
    matB = np.ndarray((n, l))

    init_array(matA, m, n)
    init_array(matB, n, m)

    matC = np.dot(matA, matB)
    print(matC)

    end_time = time.time()
    print(end_time - start_time, "s")


def init_array(mat, m, n):
    for i in range(m):
        for j in range(n):
            mat[i][j] = random.randint(0, 100)


main()
