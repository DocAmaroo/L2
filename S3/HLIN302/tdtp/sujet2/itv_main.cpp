#include <iostream>
#include "itv.h"
using namespace std;




int main(int argc, char const *argv[])
{
	Itv I1(1,2), I2(3,3);
	cout << "I1.getbi & I1.getbs = " << I1.getbi() << " et " << I1.getbs() << endl;

	cout << "Appel I1.set_new_bs(3)" << endl; I1.set_new_bs(3);

	cout << "Appel I1.set_new_bi(1)" << endl; I1.set_new_bi(1);

	cout << "Appel I1.longueur() : " << I1.longueur() << endl;

	cout << "I1.appartient(2.9) [0=false 1=true] : " << I1.appartient(2.9) << endl;

	cout << "I1.afficher() : "; I1.afficher();

	cout << "#==================================================="<<endl;

	cout << "I2.getbi & I2.getbs = " << I2.getbi() << " et " << I2.getbs() << endl;

	cout << "Appel I2.set_new_bs(10)" << endl; I2.set_new_bs(10);

	cout << "Appel I2.set_new_bi(5)" << endl; I2.set_new_bi(5);

	cout << "Appel I2.longueur() : " << I2.longueur() << endl;

	cout << "I2.appartient(2.9) [0=false 1=true] : " << I2.appartient(2.9) << endl;

	cout << "I2.afficher() : "; I2.afficher();
	
	cout << "#==================================================="<<endl;
	cout << "#                     COMPLEMENT					 "<<endl;
	cout << "#==================================================="<<endl;
	cout << "appel I1.egal(I2) [0=false 1=true] : " << I1.egal(I2) << endl;

	cout << "appel I1.inclus(I2) [0=false 1=true] : " << I1.inclus(I2) << endl;

	cout << "appel I1.disjoint(I2) [0=false 1=true] : " << I1.disjoint(I2) << endl;

	cout << "appel I1.accole(I2) [0=false 1=true] : " << I1.accole(I2) << endl;

	cout << "appel I1.imbrique(I2) [0=false 1=true] : " << I1.imbrique(I2) << endl;

	cout << "appel I1.translate(I2,3) [0=false 1=true] : ";

	I1.translate(3);
	
	I1.afficher();

	return 0;
}