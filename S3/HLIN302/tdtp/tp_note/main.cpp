#include <iostream>
#include "RDV.h"
#include "FileDeRDV.h"
using namespace std;


// FileDeRDV ne compile pas je l'ai donc enlever dans le makeFile
// 
int main(int argc, char const *argv[])
{
	
	// MANUEL //

	RDV patient1("Michel",CONTROLE);
	RDV patient2("Josephine",VACCIN);
	RDV patient3("Martine",AUTRE);
	RDV patient4("Jacques",CERTIFICAT);
	RDV patient5("Sylvie",CONTROLE);
	patient1.printRDV();
	patient2.printRDV();
	patient3.printRDV();
	patient4.printRDV();
	patient5.printRDV();

	cout << endl;
	patient1.modifRDV(&patient2);
	patient2.modifRDV(&patient3);
	patient3.modifRDV(&patient4);
	patient4.modifRDV(&patient5);

	cout << "patient1 " << &patient1 << " prochain RDV " << patient1.getRdvSuivant() << endl; 
	cout << "patient2 " << &patient2 << " prochain RDV " << patient2.getRdvSuivant() << endl; 
	cout << "patient3 " << &patient3 << " prochain RDV " << patient3.getRdvSuivant() << endl; 
	cout << "patient4 " << &patient4 << " prochain RDV " << patient4.getRdvSuivant() << endl; 
	cout << "patient5 " << &patient5 << " prochain RDV " << patient5.getRdvSuivant() << endl; 

	cout << endl;
	cout << "#====================================#" << endl;
	cout << "Création de patient automatiquement" << endl;
	cout << endl;

	// AUTOMATIQUEMENT ///
	int nb_rdv = 100;
	RDV tab[nb_rdv];
	for (int i = 0; i < nb_rdv; i++)
	{
		string nom_patient = "Patient_<" + to_string(i) + ">";
		tab[i] = RDV(nom_patient,AUTRE);
		if ( i != 0 ){
			tab[i-1].modifRDV( &tab[i] );
		}
		// tab[i].printRDV();
	}

	FileDeRDV file;
	file.ajouterRDV( patient5 );

	return 0;
}