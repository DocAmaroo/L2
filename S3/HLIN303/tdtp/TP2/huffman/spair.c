#include "pair.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	int n = atoi(argv[1]);
	if ( pair(n) ){
		printf("n est pair !\n");
	}
	else
		printf("n est impair !\n");
	return 0;
}