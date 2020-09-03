#include <iostream>
#include "livre.h"

using namespace std;

Livre::Livre(): auteur("NULL"), titre("NULL"), annee(0), livre(NULL), genre(AUTRE){}

Livre::Livre(string _auteur, string _titre, int _annee, GENRE _genre):
auteur(_auteur), titre(_titre), annee(_annee), genre(_genre), livre(NULL){}



Livre* Livre::empilerSur(){ return livre; }

void Livre::modifLivre(Livre* nouveau_livre_pointe){ livre = nouveau_livre_pointe; }

void Livre::printLivre(){ cout<< "Auteur : " << auteur << " | Titre : " << titre << " | annee : " << annee << " | genre : " << genre_to_string(genre) << endl; }

std::string genre_to_string(GENRE genre){

	switch(genre){
		case ROMAN: return "Roman";
		case FANTASY : return "Fantasy";
		case SF : return "Science Fiction";
		case BD : return "Bande Dessiné";
		default : return "Autre";
	}
}