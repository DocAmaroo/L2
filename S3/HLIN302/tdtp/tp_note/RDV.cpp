#include <iostream>
#include "RDV.h"
using namespace std;


RDV::RDV(): nom_patient("Inconnue"), type(AUTRE), prochain_rdv(NULL){}

RDV::RDV(string _nom_patient, TYPE_RDV _type): nom_patient(_nom_patient), type(_type), prochain_rdv(NULL){}

void RDV::printRDV() const{ cout << "nom du patient : " << nom_patient << " | type de RDV : " << type_to_string(type) << endl; }

void RDV::modifRDV(RDV* rdv_suivant) {  prochain_rdv = rdv_suivant;  }

RDV* RDV::getRdvSuivant() const { return prochain_rdv; }

string type_to_string(TYPE_RDV const type) {

	switch(type){
		case CONTROLE: return "Controle";
		case MALADIE : return "Maladie";
		case VACCIN : return "Vaccin";
		case CERTIFICAT : return "Certificat";
		default : return "Autre";
	}
}