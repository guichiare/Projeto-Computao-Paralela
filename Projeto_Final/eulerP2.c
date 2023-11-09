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

# pragma omp parallel num_threads(tdc)
	Euler(n, &global_result);

	printf("\n\n");
	printf("euler(%d): %.65Lf \n", n, global_result);
	return 0;
}

long double fat(int n)
{
	long double r = 1.0;
	for (int i = 1; i <= n; i++)
		r *= i;
	return r;
}

void Euler(int n, long double* global_result)
{
	long double euler = 0.0;
	int tdr = omp_get_thread_num();
	int tdc = omp_get_num_threads();
	printf("\n Thread %d of %d in execution.", tdr, tdc);

	for (int li = tdr; li < n; li += tdc)
		euler += 1.0/(fat(li));
	printf("\n thread %d euler: %.65Lf", tdr, euler);
# pragma omp critical
	*global_result += euler;
}
