#include <iostream>
#include "FileDeRDV.h"

using namespace std;


FileDeRDV::FileDeRDV(): file_rdv( new RDV[1] ), nb_rdv(0), alloc(0){}


FileDeRDV::FileDeRDV(int _nb_rdv): file_rdv( new RDV[_nb_rdv] ), nb_rdv(_nb_rdv), alloc(_nb_rdv){}


void FileDeRDV::extendAlloc(){

	if ( nb_rdv >= alloc ){

		alloc *= 2;
		RDV* new_file = new RDV[alloc];

		for (int i = 0; i < nb_rdv; i++){ 
			new_file[i] = file_rdv[i];
		}
		
		delete[] file_rdv;
		file_rdv = new_file;
		delete[] new_file;
	}

}

void FileDeRDV::ajouterRDV(RDV &rdv){

	// On vérifie si on a assez d'allocation mémoire
	extendAlloc();

	file_rdv[nb_rdv+1] = rdv;

	if (nb_rdv != 0 ){
	
		file_rdv[nb_rdv-1].modifRDV( &file_rdv[nb_rdv] );
	}

	nb_rdv++;
}


void FileDeRDV::printFile(){

	for (int i = 0; i < nb_rdv; i++)
	{
		file_rdv[i].printRDV();
	}

}