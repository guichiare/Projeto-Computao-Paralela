#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>

double f(double x);

int Trap(double a, double b, int n);

int main(int argc, char* argv[])
{
	double result = 0.0;
	double a = 0;
	double b = 100;
	int n = 10;
	int td_count;

	td_count = strtol(argv[1], NULL, 10);
	printf("Teste reduction");
	printf("threads count: %d\n", td_count);
	//printf("Enter a, b and n: ");
	//scanf("%lf %lf %d", &a, &b, &n);
	printf("Init pos: %.1lf   End pos: %.1lf   Seg num: %d \n", a, b, n);
	
# pragma omp parallel num_threads(td_count) reduction(+:result)
	result += Trap(a, b, n);

	printf("\n\n");
	printf("Approx result: %lf \n", result);
	return 0;
}

double f(double x)
{
	return exp(x);
}

int Trap(double a, double b, int n)
{
	double h, x, td_result;
	double la, lb;
	int i, ln;
	int td_rank = omp_get_thread_num();
	int td_count = omp_get_num_threads();
	printf("\n Thread %d in execution.", td_rank);
	
	h = (b-a)/n;
	ln = n/td_count;
	la = a+td_rank*ln*h;
	lb = la+ln*h;
	td_result = (f(la) + f(lb))/2;
	
	for(i = 1; i <= ln-1; i++)
	{
		x = la + i * h;
		td_result += f(x);
	}
	td_result = td_result*h;

	return td_result;
}
