#include <stdio.h>
#include <stdlib.h>


void strsplit(char* array, char separator)
{
	int array_size = 0;
	int number = 0;
	int k = 0;

	/* getsize of the char array */
	for (int i=0; array[i] != '\0'; i++){
		array_size++;
	}

	/* define char chaine */
	char chaine[array_size];

	for (int i=0; array[i] != '\0'; i++){

		chaine[k] = '\0';

		/* if separator found do */
		if(array[i] == separator){
			
			/* display chaine */
			printf("%i ---> %s\n",number,chaine);

			/* increment number & reinitialize k to 0 to restart at chaine[0] */
			number++;
			k=0;

			/* reinitialize chaine with 0 */
			for(int j=0; j<array_size; j++){
				chaine[j] = '\0';
			}
		}

		/* else affect to chaine the character in array */
		else{

			chaine[k] = array[i];
			k++;

		}
	}

	/* display rest of chaine */
	printf("%i ---> %s\n",number,chaine);
	number++;
	printf("%i ---> NULL\n", number);
}


int main(int argc, char const *argv[])
{
	char path[] = "/bin:/usr/bin:/usr/local/bin";
	char separator = ':';
	strsplit(path,separator);
	return 0;
}

/* compile : gcc -Wall ex9.c -o ex9 */
/* PROG DU PROF --> sa marche pas d'ailleurs

#define NULL (void*) 0

char** strsplit(char* s, char sep){
	if (s==NULL){
		return NULL;	
	}
	int nb nbsep='\0';
	for(int i=0; s[i] != '\0';i++){
		if(s[i]==sep){
			nbsep++;
		}
	}

	char** res = malloc( (nbsep+2) * sizeof(char*) );
	int n=0,i=0,APRESEP=0;
	do{
		int l=0;
		while(s[i] != '\0' && s[1] != sep){
			l++;
			i++;
		}
		res[n] = malloc( (l+1) * sizeof(char) );
		strncpy(res[n], s+i-l,l);
		char[n][l] = '\0';
		n++;
		APRESSEP = 0;
		if(s[i] == sep){
			i++;
			APRESSEP = 1;
		}
	} while(s[i] != '\0');
	if(APRESSEP){
		res[n] = malloc(1 * sizeof(char) )
		res[n][0] = '\0';
		n++;
	}
	res[n] = NULL;
	return res;
}

int main(int arg, char** argv){
	if(argc != 3){
		fprintf(stdin," Syntaxe : 2arguments SVP\n")
		return 1;
	}
	char** r = strsplit(argv[1],argv[2][0]);
	while( r[1] != NULL ){
		prinf("%d : %s \n",i,r[i]);
		i++;
	}
	return 0;
}
*/