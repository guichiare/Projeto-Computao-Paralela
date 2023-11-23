#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

void Euler(int n, mpf_t* global_result);

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	int tdc = atoi(argv[2]);

	mpf_t global_result;
	mpf_init2(global_result, 33220);
	mpf_set_ui(global_result, 1);

 	#pragma omp parallel num_threads(tdc)
		Euler(n, &global_result);

  	gmp_printf("\neuler(%d): %.65Ff\n", n, global_result);

	FILE *f;
	f = fopen("eulerresult.txt", "w");
	mpf_out_str(f, 10, 0, global_result);
	fclose(f);

	mpf_clear(global_result);

	return 0;
}

void Euler(int n, mpf_t* global_result)
{
	mpf_t euler, div, fat, one;

	mpf_init2(euler, 33220);
	mpf_init2(div, 33220);
	mpf_init2(fat, 33220);
	mpf_init2(one, 33220);
	mpf_set_ui(euler, 0);
	mpf_set_ui(div, 1);
	mpf_set_ui(fat, 1);
	mpf_set_ui(one, 1);
	int tdr = omp_get_thread_num();
	int tdc = omp_get_num_threads();
	printf("\n Thread %d of %d in execution.", tdr, tdc);
	
	int li = tdr*n/tdc;
	int ln = li+n/tdc;
	if (li == 0) li = 1;
	for (int i = 1; i < li; i++)
		mpf_mul_ui(fat, fat, i);
	for (li; li < ln; li++)
	{
		mpf_mul_ui(fat, fat, li);
		mpf_div(div, one, fat);
		mpf_add(euler, euler, div);
	}

# pragma omp critical
	mpf_add(*global_result, *global_result, euler);

	mpf_clear(euler);
	mpf_clear(fat);
	mpf_clear(div);
	mpf_clear(one);
}
