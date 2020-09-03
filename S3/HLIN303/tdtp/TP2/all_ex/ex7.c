#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* var */
	int NB_NOTES = 0;
	float sum = 0;
	float notes = 0.0;

	/* input NB_NOTES */
	printf("rentrer le nombre de notes à saisir : ");
	scanf("%i", &NB_NOTES);

	printf("#==============\n");

	/* sum of all notes input */
	for (int i=0; i<NB_NOTES; i++){
		printf("note %i : ",i);
		scanf("%f", &notes);
		sum += notes;
	}

	printf("#==============\n");
	
	/* print result */
	printf("moyenne = %.2f \n", sum/NB_NOTES);
	return 0;
}

// compil : gcc -Wall ex7.c -o ex7