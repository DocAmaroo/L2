#ifndef _PILEDELIVRE_H
#define _PILEDELIVRE_H

#include "livre.h"

class pileDeLivre
{

private:
	size_t nb_livre;
	size_t alloc;

public:
	pileDeLivre();	

	Livre* tab_livre;
	void empilerLivre(Livre livre);
	void depilerLivre(Livre livre);
	void extendAlloc();
	void push_back();
};



#endif 