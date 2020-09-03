#ifndef _LIVRE_H_
#define _LIVRE_H_


enum GENRE
{
	ROMAN,
	FANTASY,
	SF,
	BD,
	AUTRE
};

class Livre
{

private:
	std::string auteur;
	std::string titre;
	int annee;
	GENRE genre;
	Livre* livre;

public:
	Livre();
	Livre(std::string auteur, std::string titre, int annee, GENRE genre);

	Livre* empilerSur();
	void modifLivre(Livre* livre);
	void printLivre();
};

std::string genre_to_string(GENRE genre);

#endif 