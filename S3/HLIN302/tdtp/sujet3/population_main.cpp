#include "population.h"
#include <unistd.h>
using namespace std;

int main(int argc, char const *argv[])
{
	Population jeu;
	jeu.init(1000);
	jeu.print();
	while(true){
		jeu = jeu.next();
		jeu.print();
		usleep(70000);
	}
	return 0;
}

// g++ -Wall population.cpp population_main.cpp cellule.cpp -o pop