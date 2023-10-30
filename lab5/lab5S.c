#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>

double f(double x);
void Trap(double a, double b, int n, double* global_result);

int main(int argc, char* argv[])
{
	double global_result = 0.0;
	double a, b;
	int n;

	printf("Enter a, b and n: ");
	scanf("%lf %lf %d", &a, &b, &n);
	printf("Init pos: %.1lf   End pos: %.1lf   Seg num: %d \n", a, b, n);
	Trap(a, b, n, &global_result);

	printf("Approx result: %.14e\n", global_result);
	return 0;
}

double f(double x)
{
	return exp(x);
}

void Trap(double a, double b, int n, double* global_result)
{
	double h, x, result;
	
	h = (b-a)/n;
	result = (f(a) + f(b))/2;
	
	for(int i = 1; i <= n-1; i++)
	{
		x = a + i * h;
		result += f(x);
	}
	result = result*h;

	*global_result += result;
}
