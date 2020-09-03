#include <iostream>
#include <fstream>
#include "Rdv.h"

// 1.1 -> Empilement manuel
int main(int argc, char const *argv[])
{
	Rdv rdv1("Lucien Crapaud", Rdv::AUTRE);
	Rdv rdv2("Ugues Ubuntu", Rdv::VACCIN);
	Rdv rdv3("Camille Leroi", Rdv::CONTROLE);
	Rdv rdv4("Adolf Filipe", Rdv::CERTIFICAT);
	Rdv rdv5("Serge Seluj", Rdv::MALADIE);
	Rdv rdv6("Enzo Rossignol", Rdv::MALADIE);

	rdv1.setProchainRDV(rdv5);
	rdv5.setProchainRDV(rdv2);
	rdv2.setProchainRDV(rdv3);
	rdv3.setProchainRDV(rdv6);
	rdv6.setProchainRDV(rdv4);
	// RDV4 n'a pas de prochain rendez-vous.

	std::cout << "Le rendez-vous après celui de " << rdv3.getNomPatient() << " est celui de "
			  << rdv3.getProchainRDV().getNomPatient() << " ! " << std::endl; 
	return 0;
}