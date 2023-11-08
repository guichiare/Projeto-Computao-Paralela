#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

long double fat(int n);

void Euler(int n, long double* global_result);

int main(int argc, char* argv[])
{
	long double global_result = 0.0;
	int n = atoi(argv[1]);
	int tdc = atoi(argv[2]);

	printf("threads count: %d\n", tdc);

# pragma omp parallel num_threads(tdc) reduction(+:global_result)
	Euler(n, &global_result);

	printf("\n\n");
	printf("\neuler(%d): %.65Lf \n", n, global_result);
	return 0;
}

long double fat(int n)
{
	long double r = 1;
	for (int i = 1; i <= n; i++)
		r *= i;
	return r;
}

void Euler(int n, long double* global_result)
{
	long double euler = 0;
	int tdr = omp_get_thread_num();
	int tdc = omp_get_num_threads();
	int li = tdr*n/tdc;
	int ln = li+n/tdc;
	printf("\n Thread %d in execution.", tdr);

	for (li; li < n; li++)
		euler += 1.0/(fat(li));

# pragma omp critical
	*global_result += euler;
}
