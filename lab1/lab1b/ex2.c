#include <stdio.h>

char MediaFinal(float n1, float n2, float n3, float T);

int main(void) {
	float n1, n2, n3, T;
	n1 = 8;
	n2 = 10;
	n3 = 10;
	T = 10;
	printf("Notas: |N1:%.1f|N2:%.1f|N3:%.1f|ME:%.1f|\n", n1, n2, n3, T);
	printf("Avaliação do aluno: %c\n", MediaFinal(n1, n2, n3, T));
	return 0;
}

char MediaFinal(float n1, float n2, float n3, float T)
{
	float medF = (n1 + 2*n2 + 2*n3 + T)/7;
	printf("Média Final: %f\n", medF);
	if (medF >= 9)
		return 'A';
	if (medF >= 7.5)
		return 'B';
	if (medF >= 6)
		return 'C';
	if (medF >= 4)
		return 'D';
	return 'E';
}
