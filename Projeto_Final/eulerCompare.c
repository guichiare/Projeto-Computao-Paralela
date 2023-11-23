#include <stdio.h>
#include <stdbool.h>
int main()
{
	FILE *fp1 = fopen("eulertrue.txt", "r");
	FILE *fp2 = fopen("eulerresult.txt", "r");

	if (fp1 == NULL || fp2 == NULL)
	{
    		printf("Error: could not open file");
		return 1;
	}
	int count = 0;
	char ch1, ch2;
	while (true)
	{
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);
		if (ch1 != ch2)
		{
			printf("o código alcançou %d casa decimais de euler\n", count);
			return 1;
		}
		count++;
	}
	
	fclose(fp1);
	fclose(fp2);

	return 0;
}
