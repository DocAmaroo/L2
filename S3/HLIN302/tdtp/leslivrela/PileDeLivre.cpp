#include <iostream>
#include "PileDeLivre.h"

using namespace std;

pileDeLivre::pileDeLivre(): tab_livre(new Livre[1]), nb_livre(0), alloc(0){}

void pileDeLivre::extendAlloc(){

	if ( nb_livre >= alloc ){

		alloc *= 2;
		Livre* new_tab = new Livre[alloc];

		for (int i = 0; i < nb_livre; i++){ 
			new_tab[i] = tab_livre[i];
		}
		
		delete[] tab_livre;
		tab_livre = new_tab;
		delete[] new_tab;
	}

}

void pileDeLivre::empilerLivre(Livre livre){ 

	// On vérifie si on est pas a la fin de notre allocation
	extendAlloc();
	tab_livre[nb_livre+1] = livre;

	// Le nouveau livre est empiler sur le précédent livre
	livre.modifLivre(&tab_livre[nb_livre]);
	cout << "livre " << &livre << " empiler sur " << livre.empilerSur() << endl;
	cout << &tab_livre[nb_livre] << endl;
}

/*void pileDeLivre::depilerLivre(Livre livre){

	// On cherche ou est empiler le livre
	for( int i=0; i < nb_livre; i++ ){
		if ( &tab_livre[i] = &livre ){
			cout << " J'ai trouvé : &tab_livre = " << &tab_livre[i] << " et livre = " << &livre << endl;
		}
	}

}*/