#include <iostream>
#include "FileDeRdv.h"
#include <fstream>

using namespace std;

void nettoyerUneLigne(string& ligne) {
	if(ligne.size() < 1) return;
	int pos = ligne.find('#');
	if(pos != string::npos)
		ligne = ligne.substr(0, pos);

	for(int i(0); i<ligne.size()-1; i++) {
		if(ligne[i] == ' ' && ligne[i+1] == ' ')
			ligne = ligne.erase(i--, 1);
	}
}

bool sortirInfos(string& ligne, string& nom, Rdv::Type& type) {
	if(ligne.find("Rdv: ") == 0) {
		ligne = ligne.erase(0, 5);
		int pospace = ligne.find(' ');
		if(pospace == string::npos) return false;

		string typestr = ligne.substr(0, pospace);
		if(typestr == "CONTROLE")
			type = Rdv::CONTROLE;
		else if(typestr =="MALADIE")
			type = Rdv::MALADIE;
		else if(typestr == "VACCIN")
			type = Rdv::VACCIN;
		else if(typestr == "CERTIFICAT")
			type = Rdv::CERTIFICAT;
		else if(typestr == "AUTRE")
			type = Rdv::AUTRE;
		else 
			return false;
		nom = ligne.substr(pospace+1);
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	if(argc == 1) {
		cout << "Entre un fichier, patate." << std::endl;
		return 1;
	}

	ifstream file(argv[1]);
	if(!file.is_open()) {
		cout << "Ton fichier " << argv[1] << " existe pas, idiot." << std::endl;
		return 2;
	}

	FileDeRdv fileRdv;
	string ligne;
	int nb (0);
	while(!file.eof()) {
		getline(file, ligne);
		nettoyerUneLigne(ligne);
		string nom; Rdv::Type type;

		if(sortirInfos(ligne, nom, type)) {
			fileRdv.ajouterRDV(*(new Rdv(nom, type)));
		}
	}

	FileDeRdv copie(fileRdv);
	while(&copie.getPremierRDV() != NULL) {
		Rdv& prochain = copie.getPremierRDV();
		std::cout << prochain << std::endl;
		copie.supprimerRDV(prochain);
	}

	file.close();
}