#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char* argv[])
{
	int n = argc;
	n = atoi(argv[1]);
	mpf_t euler, div, fat, one;

	mpf_init2(euler, 2097152);
	mpf_set_ui(euler, 1);
	mpf_init2(div, 2097152);
	mpf_set_ui(div, 1);
	mpf_init2(fat, 2097152);
	mpf_set_ui(fat, 1);
	mpf_init2(one, 2097152);
	mpf_set_ui(one, 1);

	for (int i = 1; i < n; i++)
	{
		mpf_mul_ui(fat, fat, i);
		mpf_div(div, one, fat);
		mpf_add(euler, euler, div);
	}

  	gmp_printf("\neuler(%d): %.65Ff\n", n, euler);

	mpf_clear(euler);
	mpf_clear(fat);
	mpf_clear(div);
	mpf_clear(one);

	return 0;
}
