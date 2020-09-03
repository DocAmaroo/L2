#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	/* var */
	int sum=0;

	/* sum of all notes input */
	for (int i=1; i<argc; i++){

		int notes = atoi(argv[i]);
		sum += notes;
	}

	/* cout result (sum/nb_argument_giv_in_param) */
	printf("moyenne = %d\n", sum/(argc-1));
	return 0;
}

//gcc -Wall ex8.c -o ex8