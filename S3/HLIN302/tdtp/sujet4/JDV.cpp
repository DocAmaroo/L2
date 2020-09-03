#include "JDV.h"
#include "population_vivante.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

JeuDeLaVie::JeuDeLaVie():POP(8,0.25){}

void JeuDeLaVie::nettoie(string &ligne){

	int pos = ligne.find_first_of('#'); // on cherche le premier #
	
	if (pos != string::npos){ // si "#" dans la ligne
		ligne = ligne.substr(0,pos); // alors on prend tous ce qu'il y a avant le #
}

	for( int i=0; i < pos ;i++){ // on passe en revu la ligne
		if (ligne.at(i) == ' '){ //si il y a un espace (" ")...
			ligne.erase(i,1); // ...on le supprime
	}
}
}

bool JeuDeLaVie::findCleVal(string &ligne, string &cle, string &valeur){

	nettoie(ligne);
	
	if( ligne == string("") ){ // si ma ligne est vide
		return false; // renvois false
	}
	
	int pos = ligne.find_first_of(":"); // on cherche le premier ":"
	cle = ligne.substr(0,pos); // la clé est tout ce qui se trouve a gauche du ":"
	valeur = ligne.substr(pos+1); // la valeur est tout ce qui se trouve à droite du ":"

	nettoie(cle); // on les nettoies pour les lignes suivantes
	nettoie(valeur); // idem

	return true;
}

void JeuDeLaVie::traiteOption(string &cle, string &valeur, size_t num_ligne){

	if( cle == "Dimension"){
		POP.setDimension(atoi(valeur.c_str()) ); // convertie la chaine de charactère en un entier
	}

	else if( cle == "Probability"){
		POP.setProbability(atof(valeur.c_str()));
	}

	else if( cle == "Cell" ){
		size_t x,y;
		size_t pos = valeur.find_first_of("x, ");
		if( pos == string::npos || valeur[pos] == '\0'){
			cerr << "Le fichier est mal formé. Vérifiez la syntaxe de la ligne "<< num_ligne << endl;
		}
		else {
			x = atoi(valeur.substr(0, pos).c_str());
			y = atoi(valeur.substr(pos).c_str());
			POP.birth(x,y);    
		}
	}
}

void JeuDeLaVie::init(string file){

	ifstream input(file.c_str());
	string cle, valeur;
	size_t num_ligne=0;

	if (!input.is_open()) {
		cerr << "Le fichier " << file << " n'a pas pu être ouvert." << endl;
		terminate();
	}
	string line;
	while (!input.eof()) {
		getline(input,line);
		if (!input.eof()) {
			if (findCleVal(line,cle,valeur))
				traiteOption(cle,valeur,num_ligne);
		}
		num_ligne++;
	} 
	input.close();
}

void JeuDeLaVie::run(size_t n) {
	POP.print();
	for(size_t i=0;i<n;i++){
		//system("clear");
		POP=POP.next();
		POP.print();
		//std::this_thread::sleep_for(std::chrono::seconds(1));

	}
}


