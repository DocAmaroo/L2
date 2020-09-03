#ifndef FILEDERDV_H
#define FILEDERDV_H

#include "Rdv.h"

class FileDeRdv
{
public:
	FileDeRdv(); 
	FileDeRdv(const FileDeRdv& autreFile);
	FileDeRdv& operator=(const FileDeRdv& autreFile);
	~FileDeRdv();

	void ajouterRDV(Rdv& rdv); // Met un rendez-vous à la fin.
	void supprimerRDV(Rdv& rdv); // Supprime le premier RDV.

	Rdv& getPremierRDV();
	Rdv& getDernierRDV();

private:
	Rdv* _premierRDV;
	Rdv* _dernierRDV;
};

void suppress(Rdv* rdv);
Rdv* duplicate (const Rdv* rdv);

#endif