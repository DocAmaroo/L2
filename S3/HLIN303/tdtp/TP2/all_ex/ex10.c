#include <stdio.h>

int puissance(int x, int n){
	int puis=1;
	while(n > 0){
		puis *= x;
		n--;
	}
	return puis;
}

int string_to_integer(char* param, int size){

	int i=0, param_int = 0;
	while ( i <= size ){
		param_int += (param[i]-48)*puissance(10,size-i);
		i++;
	}

	return param_int;

}

int main(int argc, char const *argv[])
{

	char character[] = "123";
	int size = sizeof(character)-2;
	int res, n, proof;
	
	res = string_to_integer(character,size);

	printf("donner une valeur : "); scanf("%d", &n);
	proof = res + n;

	printf("%d + %d = %d\n",res,n,proof);

	return 0;
}