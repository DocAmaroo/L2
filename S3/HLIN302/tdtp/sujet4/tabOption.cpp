#include "tabOption.h"
using namespace std;

TabOption::TabOption(): nb_options(0), tab_options(){};

void TabOption::ajouter_option(Option opt){

	if(NMAX_OPTS == nb_options){
		cerr << "[ \033[1;43mError\033[0m ]: Nombre d'option maximum atteint" << endl;
		terminate();
	}

	if( option_identique(opt) ){

	}

	else{
		tab_options[nb_options] = opt;
		nb_options++;
	}

}

void TabOption::afficher_option() const{

	cout << "=============" <<endl;
	for(size_t i=0; i < nb_options; i++){
		tab_options[i].print();
		cout << "=============" <<endl;
	}
}

int TabOption::getOptIndex(string opt) const {

	bool found = false;
	size_t i = 0;
	while( !found && (i < nb_options) ){
		found = ( (tab_options[i].getIntitule() == opt) || (tab_options[i].getRaccourci() == opt) );
		i++;
	}
	return found? i-1 : -1;

}

int TabOption::getId(string opt) const{

	int index = getOptIndex(opt);
	return ( (index>=0)? tab_options[index].getId() : -1);

}

bool TabOption::Option_to_Argument(string arg) const{

	int index = getOptIndex(arg);
	return ( tab_options[index].getType() != Option::AUCUN );

}

bool TabOption::option_identique(Option opt) const{

	bool found = false;
	for(int i=0; i < NMAX_OPTS; i++){
		if( (tab_options[i].getId() == opt.getId()) || (opt.getIntitule() == tab_options[i].getIntitule()) || (opt.getRaccourci() == tab_options[i].getRaccourci() ) ){
			{ 
				cerr << "[ \033[1;43mWarning\033[0m ]: L'identifiant " << opt.getIntitule() << " est déjà utilisé ]"<< endl;
				found = true;
			}
		}
	}
	return found;
}


Option::Type TabOption::optionArgumentType(const string &opt) const{

	size_t index = getOptIndex(opt);
	return tab_options[index].getType();
}