#include <stdio.h>
int lin = 5;
int col = 5;

int MinNumLine(int m[][col], int lin, int col);
void PrintMatriz(int m[][col], int lin, int col);

int main(void) {
	int matriz[lin][col];
	for (int i=0; i<lin; i++)
		for (int j=0; i<col; i++)
			matriz[i][j] = 9;
	matriz[2][4] = 5;
	matriz[3][0] = 2;
	matriz[1][2] = 7;
	PrintMatriz(matriz, lin, col);
	printf("Linha do menor numero: %d\n", MinNumLine(matriz, lin, col));
	return 0;
}

int MinNumLine(int m[][col], int lin, int col) 
{
	int temp;
	int tempL;
	for (int i=0; i<lin; i++)
		for (int j=0; i<col; i++)
			if (m[i][j] < temp || i == 0 && j == 0)
			{
				temp = m[i][j];
				tempL = i;
			}
	return tempL;
}

void PrintMatriz(int m[][col], int lin, int col) 
{ 
	for (int i=0; i<lin; i++)
	{
		printf("\n||");
		for (int j=0; j<col; j++)
			printf(" %d |", m[i][j]);
		printf("|\n");
	}
	printf("\n");
}
