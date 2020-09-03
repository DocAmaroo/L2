#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	// Crée la variable fp comme fichier
	FILE * fp;
	int size;
	// "Ouvre" le fichier en mode lecture dans fp
	fp = fopen( "text.txt" , "r" );
	if( fp == NULL )  {
		// Si fp n'existe pas erreur
		perror ("Error opening file");
		return(-1);
	}
	char ch;
	//Met le pointeur au début du fichier
	fseek(fp, 0L, SEEK_SET);
	// Met dans ch le caractère au niveau du pointeur et rajoute +1 au pointeur
	ch = fgetc(fp);
	printf("%c",ch);
	// Dirige le pointeur a la fin du fichier
	fseek(fp, 0L, SEEK_END);
	// Trouve la taille du fichier en prenant tous les caractère avant le pointeur
	size = ftell(fp);
	// "Ferme" le fichier
	fclose(fp);

	printf("La taille du fichier est de %d octet\n", size);
	return 0;
}

//gcc -Wall Exemple.c -o exemple 