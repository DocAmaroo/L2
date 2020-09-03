#ifndef RDV_H
#define RDV_H

#include <string>
#include <iostream>

class Rdv
{
public:
	enum Type {
		CONTROLE,
		MALADIE, 
		VACCIN, 
		CERTIFICAT, 
		AUTRE
	};

	Rdv(const std::string& nomPatient, Type type);

	void setProchainRDV(Rdv& prochainRDV); // Je passe le RDV par référence
	Rdv& getProchainRDV() const;           // pour que ce soit plus pratique.
										   // Mais au final ça ne l'est pas tout le temps LOL

	std::string getNomPatient() const;
	Type getType() const;

	friend std::ostream& operator<<(std::ostream&, const Rdv&);

private:
	std::string _nomPatient;
	Type _type;
	Rdv* _prochainRDV; // Doit contenir l'adresse donc un pointeur.
};

std::string typeToString(Rdv::Type type);

#endif