#include <stdio.h>
#include <stdlib.h>

int impair(unsigned int i){
	if (i==0)
		return 0;
	else
		return pair(i-1);
}

int pair(unsigned int i){
	if (i==0)
		return 1;
	else
		return impair(i-1);
}

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

// compile : gcc -Wall ppair.c -o ppair
/* warning: implicit declaration of function ‘pair’; did you mean ‘impair’? [-Wimplicit-function-declaration]
   return pair(i-1);
          ^~~~
          impair */