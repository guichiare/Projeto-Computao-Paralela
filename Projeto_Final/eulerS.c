#include <stdio.h>
#include <stdlib.h>

long double fat(int n);

long double Euler(int n);

int main(int argc, char* argv[])
{
	int n = argc;
	n = atoi(argv[1]);
	long double num = Euler(n);
	printf("\neuler(%d): %.65Lf \n", num);
  
	return 0;
}

long double fat(int n)
{
	long double r = 1;
	for (int i = 1; i <= n; i++)
		r *= i;
	return r;
}

long double Euler(int n)
{
	long double euler = 0;
	for (int i = 0; i < n; i++)
		euler += 1.0/(fat(i));
	return euler;
}
