#include <stdio.h>
#include <stdlib.h>

int getsize(int integer){
	int i=integer,res=0;
	while( i > 0 ){ res++; i /= 10; }
	return res;
}

char* integer_to_string(int param, int size){

	char* param_char = malloc( (size+1) * sizeof(char) );
	int i=size-1, j=param;
	while ( i >= 0 ){

		param_char[i] = j%10 + 48;
		j /= 10;
		i--;
	}

	return param_char;
 
}


int main(int argc, char const *argv[])
{

	int integer = 354;
	int size = getsize(integer);
	char* param_char = integer_to_string(integer,size);
	printf("param_char = %s\n", param_char);
	return 0;
}