#ifndef _FILE_DE_RDV_H
#define _FILE_DE_RDV_H

#include "RDV.h"

class FileDeRDV
{

private:
	
	int nb_rdv;
	int alloc;
	RDV* file_rdv;

public:
	
	FileDeRDV();
	FileDeRDV(int nb_rdv);

	void extendAlloc();
	void ajouterRDV( RDV &rdv );
	void supprRDV();

	void printFile();
};


#endif