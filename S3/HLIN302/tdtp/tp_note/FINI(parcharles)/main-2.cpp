#include <iostream>
#include "FileDeRdv.h"
#include <fstream>

// 1.2 -> File de RDV
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	FileDeRdv file;
	for(int i(1); i<=100; i++) {
		Rdv* rdv = new Rdv(std::string("Patient_").append(std::to_string(i)), static_cast<Rdv::Type>(rand()%5));
		file.ajouterRDV(*rdv);
	}

	std::ofstream fichier("rendez-vous.cfg");
	FileDeRdv copie(file);
	while(&copie.getPremierRDV() != NULL) {
		Rdv& prochain = copie.getPremierRDV();
		std::cout << prochain << std::endl; 
		fichier << prochain << std::endl;
		copie.supprimerRDV(prochain);
	}
	fichier.close();
	return 0;
}