#include <stdio.h>
#include <stdlib.h>


// Le taille du fichier est donnée en octet et un caractère est codé sur 8 bits.
// Donc tailleFichier = nombre de caractre
void distributionProba(FILE* fp, const int tailleFichier) {
	printf("==========================\n");
	printf("         dist_prob        \n");
	printf("==========================\n");

	int tab[128] = {0};
	fseek(fp, 0L, SEEK_SET);

	for(int i=0; i<tailleFichier; i++) {
		int cara = (int) fgetc(fp);
		if( cara > 127 ) continue;
		tab[cara]++;
	}



	int size=0,k=0;
	while (k < 127) {
		if( tab[k] != 0 ){ size++ ;}
		k++;
	}

	//return number of char appear 1 or more
	int dist_prob[2][size];
	int x=0;
	for (int cpt = 0; cpt < 127; cpt++){
		if( tab[cpt] != 0 ){
			dist_prob[0][x] = cpt;
			dist_prob[1][x] = tab[cpt];
			x++;
		}
	}

	int z=0;
	while ( z < size ){
		printf("tab[%d] = (%c) : %d | probabilité = [ %f%% ]\n", z, (char) dist_prob[0][z], dist_prob[1][z], ((float) dist_prob[1][z]/ (float) tailleFichier)*100.0 );
		z++;
	}

}

int main(int argc, char const *argv[]) {
	// Crée la variable fp comme fichier
	FILE * fp;
	int size;

	// "Ouvre" le fichier en mode lecture dans fp
	fp = fopen( argv[1] , "r" );
	if( fp == NULL )  {

		// Si fp n'existe pas erreur
		perror ("Error opening file");
		return(-1);
	}

	// Dirige le pointeur a la fin du fichier
	fseek(fp, 0L, SEEK_END);
	// Trouve la taille du fichier en prenant tous les caractère avant le pointeur

	size = ftell(fp);
	distributionProba(fp,size);

	// "Ferme" le fichier
	fclose(fp);
	
	return 0;
}

// gcc -Wall distri.c -o distri
// ./distri [file_name]
// for ( int j=0; j < 127; j++){
// 	printf("caractère num%d (%c) : %d\n",j,(char)j ,tab[j]);
// }


// printf("La taille du fichier est de : %ld bits & %d octet & %lf ko & %lf Mo & %lf Go\n", (long int)size*8, size, (double)size/1000 ,(double)size/1000000, (double)size/1000000000);

/* Correction prof
nboccurence

int taille = 0;
int nbocc[256];

int calculnbocc(char* nomfic){
	FILE* file = fopen(nomfic,"r");
	if (f=NULL)
	{
		return 1;
	}
	while( EOF != ( c = fgetc(f)) ){
		taille+=1;
		nbocc[c]++;
	}
	fclose(file);
	return 0;
} */