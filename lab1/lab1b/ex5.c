#include <stdio.h>
int lin = 3;
int col = 3;

void PrintMatriz(int matriz[][col], int lin, int col);
void MultLin(int matriz[][col], int lin, int col, int linC, int mult);
void MultCol(int matriz[][col], int lin, int col, int colC, int mult);

int main(void) {
	int temp;
	int matriz[lin][col];
	for (int i=0; i<lin; i++)
		for (int j=0; j<col; j++)
		{
			printf("\nDigite o valor da posição [%d][%d]: ", i, j);
			scanf("%d", &temp);
			matriz[i][j] = temp;
		}
	PrintMatriz(matriz, lin, col);
	MultLin(matriz, lin, col, 1, 0);
	MultCol(matriz, lin, col, 1, 2);
	PrintMatriz(matriz, lin, col);
	return 0;
}

void PrintMatriz(int matriz[][col], int lin, int col)
{ 
	for (int i=0; i<lin; i++)
	{
		printf("\n||");
		for (int j=0; j<col; j++)
			printf(" %d |", matriz[i][j]);
		printf("|\n");
	}
	printf("\n");
}

void MultLin(int matriz[][col], int lin, int col, int linC, int mult)
{
	if(linC >= lin || linC < 0)
	{
		printf("Linha Inválida\n");
	}
	else
	{
		for(int i=0; i < col; i++)
			matriz[linC][i] *= mult;
	}
}

void MultCol(int matriz[][col], int lin, int col, int colC, int mult)
{
	if(colC >= col || colC < 0)
	{
		printf("Linha Inválida\n");
	}
	else
	{
		for(int i=0; i < lin; i++)
			matriz[i][colC] *= mult;
	}
}
