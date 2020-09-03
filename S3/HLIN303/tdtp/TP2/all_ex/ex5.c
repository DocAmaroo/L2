#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[], char *env[])
{
	/* affiche le nb de param */
	printf("#====================================================================\n\n");
	printf("il y a %i argument(s) passé en paramètres : \n", (argc-1) );

	for (int i=1; i<argc; i++){
		printf("argument %i = %s \n", i,argv[i]);
	}
	printf("\n#====================================================================\n\n");

	/*
	printf("variable environnement = %s \n", env);
	*/
	printf("\n#====================================================================\n");
	return 0;
}
/*


Exercice 6 :

Fichier prétraité : gcc ex5.c -E > pretraite
Fichier assembleur : gcc ex5.c -S > assembleur
Fichier objet : gcc -Wall ex5.c -o ex5.o

*/