#ifndef _TAB_OPTION
#define _TAB_OPTION
#include "option.h"

#define NMAX_OPTS 10

class TabOption{

private:

	size_t nb_options;
	Option tab_options[NMAX_OPTS];

public:

	TabOption();

	int getOptIndex(std::string opt) const;
	void ajouter_option(Option opt);
	void afficher_option() const;
	int getId(std::string opt) const;
	bool Option_to_Argument(std::string arg) const;
	bool option_identique(Option opt) const;
	Option::Type optionArgumentType(const std::string &opt) const ;

};


#endif