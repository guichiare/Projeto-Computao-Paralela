#include <stdio.h>

void PrintPyramid(int num);

int main(void) {
	int num;
	printf("Digite um número: ");
	scanf("%d", &num);
	printf("\n");
	PrintPyramid(num);
	return 0;
}

void PrintPyramid(int num)
{
	if(num%2 == 0)
	{
		printf("Escolha um número impar.\n");
		return;
	}
	int temp = 0;
	int space;
	for(int i = 0; i < num/2+1; i++)
	{
		space = temp;
		for(int j = 0; j < space; j++)
			printf(" ");
		for(int j = 1; j <= num-temp; j++)
		{
			printf("%d ", i+j);
		}
		printf("\n");
		temp += 2;
	}
}
