#ifndef _RDV_H
#define _RDV_H

enum TYPE_RDV
{
	CONTROLE,
	MALADIE,
	VACCIN,
	CERTIFICAT,
	AUTRE
};

class RDV
{

private:
	std::string nom;
	std::string nom_patient;
	TYPE_RDV type;
	RDV* prochain_rdv;

public:
	RDV();
	RDV(std::string nom_patient, TYPE_RDV type);
	void printRDV() const;

	void modifRDV(RDV* rdv_suivant);
	RDV* getRdvSuivant() const;

};

std::string type_to_string(TYPE_RDV const type);

#endif