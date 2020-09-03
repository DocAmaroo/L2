#include "option.h"
using namespace std;

Option::Option(): id_num(-1), intitule("N/A"), raccourci("N/A"), description("N/A"), type(AUCUN){};

Option::Option(int _id_num, std::string _intitule, std::string _raccourci, std::string _description, Type _type) :
id_num(_id_num), intitule(_intitule), raccourci(_raccourci), description(_description), type(_type){};

//accesseurs en lecture
int Option::getId() const { return id_num; }
std::string Option::getIntitule() const { return intitule; }
std::string Option::getRaccourci() const { return raccourci; }
std::string Option::getDescription() const { return description; }
Option::Type Option::getType() const{ return type; }

//accesseurs en écriture
void Option::setId(int new_id_num) { id_num = new_id_num; }
void Option::setIntitule(const std::string new_intitule) { intitule = new_intitule; }
void Option::setRaccourci(const std::string new_raccourci) { raccourci = new_raccourci; }
void Option::setDescription(const std::string new_description){ description = new_description; }
void Option::setType(Type new_type){ type = new_type; }

//Affichage
void Option::print() const{

	cout << "Id_num = " << id_num << endl;
	cout << "Intitule = " << intitule << endl;
	cout << "Raccourci = "<< raccourci << endl;
	cout << "Description = " << description << endl;
	cout << "Type = " << Type_to_String(type) << endl;

}

std::string Type_to_String(Option::Type type){
	std::string tmp;
	switch(type){
		
		case Option::AUCUN : tmp = "[no_type]";
		break;
		
		case Option::ENTIER : tmp = "[entier]";
		break;
		
		case Option::REEL: tmp = "[reel]";
		break;

		case Option::BOOLEEN: tmp = "[booleen]";
		break;

		case Option::CHAR: tmp = "[char]";
		break;

		case Option::CHAINE: tmp = "[chaine]";
		break;
	}
	return tmp;
}