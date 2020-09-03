#include <iostream>
#include "livre.h"
#include "PileDeLivre.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Livre L1("patate","contre-attaque",1998,AUTRE);
	Livre L2("J. K. Rowling","Harry Potter et la chambre des secrets",1991,SF);
	Livre L3("J. K. Rowling","Harry Potter, les reliques de la mort",2014,SF);
	Livre L4("J. K. Rowling","Les animaus fantastiques",2016,SF);
	Livre L5("J. K. Rowling","les animaux fantastiques 2",2018,SF);
	Livre L6("Jesaispasquicest","Toy Story",1990, BD);
	
	L1.printLivre(); L2.printLivre(); L3.printLivre(); L4.printLivre(); L5.printLivre(); L6.printLivre();

	cout << "Empillage" <<endl;
	L2.modifLivre(&L6);
	L1.modifLivre(&L2);
	L3.modifLivre(&L1);
	L4.modifLivre(&L3);
	L5.modifLivre(&L4);
	cout << "L6 " << &L6 << " empiler sur " << L6.empilerSur() << endl; 
	cout << "L2 " << &L2 << " empiler sur " << L2.empilerSur() << endl; 
	cout << "L1 " << &L1 << " empiler sur " << L1.empilerSur() << endl; 
	cout << "L3 " << &L3 << " empiler sur " << L3.empilerSur() << endl; 
	cout << "L4 " << &L4 << " empiler sur " << L4.empilerSur() << endl; 
	cout << "L5 " << &L5 << " empiler sur " << L5.empilerSur() << endl; 

	return 0;
}