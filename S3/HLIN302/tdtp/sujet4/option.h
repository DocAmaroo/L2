#ifndef _OPTION_H
#define _OPTION_H

#include <iostream>

class Option{

public:

	enum Type{
		AUCUN,
		ENTIER,
		REEL,
		BOOLEEN,
		CHAR,
		CHAINE
	};

private:

	int id_num;
	std::string intitule, raccourci, description;
	Type type;

public:

	Option();
	Option(int id_num, std::string intitule, std::string raccourci, std::string description, Type type);

	//accesseurs en lecture
	int getId() const;
	std::string getIntitule() const;
	std::string getRaccourci() const;
	std::string getDescription() const;
	Type getType() const;

	//accesseurs en écriture
	void setId(int new_id_num);
	void setIntitule(const std::string new_intitule);
	void setRaccourci(const std::string new_raccourci);
	void setDescription(const std::string new_description);
	void setType(Type new_type);

	//Affichage
	void print() const;

};

std::string Type_to_String(Option::Type type);

#endif