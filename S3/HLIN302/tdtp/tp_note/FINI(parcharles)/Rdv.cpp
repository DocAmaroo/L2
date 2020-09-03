#include "Rdv.h"

Rdv::Rdv(const std::string& nomPatient, Type type) : 
_nomPatient(nomPatient), _type(type), _prochainRDV(NULL) {}

void Rdv::setProchainRDV(Rdv& prochainRDV) {
	_prochainRDV = &prochainRDV;
} 

Rdv& Rdv::getProchainRDV() const {
	return *_prochainRDV;
}

std::string Rdv::getNomPatient() const { return _nomPatient; }

Rdv::Type Rdv::getType() const { return _type; }

std::string typeToString(Rdv::Type type) {
	switch(type) {
		case Rdv::CONTROLE: return "CONTROLE";
		case Rdv::MALADIE: return "MALADIE";
		case Rdv::VACCIN: return "VACCIN";
		case Rdv::CERTIFICAT: return "CERTIFICAT";
		default: return "AUTRE";
	}
}

std::ostream& operator<<(std::ostream& os, const Rdv& rdv) {
	os << "Rdv: " << typeToString(rdv.getType()) << " " << rdv.getNomPatient();
	return os;
}