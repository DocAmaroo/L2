#ifndef _JDV_H
#define _JDV_H
#include "population_vivante.h"

class JeuDeLaVie{

private:
	PopulationVivante POP;

	void nettoie(std::string &s);
	bool findCleVal(std::string &ligne, std::string &cle, std::string &valeur);

	void traiteOption(std::string &cle, std::string &valeur, size_t num_ligne);

public:
	JeuDeLaVie();

	void init(std::string file);
	void run(size_t step);
};

#endif