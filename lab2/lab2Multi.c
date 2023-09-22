#include <stdio.h>
#include <mpi.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main(int argc, char *argv[]) {
    int n = 10; // Change this to the number for which you want to calculate factorial

    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    unsigned long long localResult = factorial(n / MPI_COMM_SIZE);
    unsigned long long globalResult;

    MPI_Reduce(&localResult, &globalResult, 1, MPI_UNSIGNED_LONG_LONG, MPI_PROD, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Factorial of %d is %llu\n", n, globalResult);
    }

    MPI_Finalize();

    return 0;
}
