#include "tabOption.h"
using namespace std;

 int main(int argc, char const *argv[])
 {
 	
 	TabOption option;
 	Option help(0, "help", "--help", "Affiche l'aide", Option::AUCUN);
 	Option version(1, "version", "--version", "Affiche la version", Option::REEL);
 	Option dimension(2, "dimension", "--dimension", "Initialise une matrice carrée de la dimension spécifiée ", Option::ENTIER);
 	Option probability(3, "probabilite", "--probability", " Définit la probabilité d’être en vie d’une cellule au démarrage ", Option::REEL);
 	Option config(4, "config", "--config", "Charge la configuration initiale du jeu", Option::CHAR);
 	//Option abc(5, "abc", "--config", "Charge la configuration initiale du jeu", Option::CHAR);


 	option.ajouter_option(help);
 	option.ajouter_option(version);
 	option.ajouter_option(dimension);
 	option.ajouter_option(probability);
 	option.ajouter_option(config);
 	//option.ajouter_option(abc);
 	option.afficher_option();

 	return 0;
 }