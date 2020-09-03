#include <iostream>
#include "cellule.h"
using namespace std;


//define
#define PrintCell(c1,i,j) cout << "l'adresse de la cellule tab[" << i << "][" << j << "] est à l'adresse mémoire " << &c1 << endl;
#define PrintVoisines(c1,c2) cout << "La cellule " #c1 "" << (c1.estVoisine(c2)? " est " : " n'est pas ") << "voisine avec " #c2 "." << endl;
#define PrintCelColor(c,color) cout << #c << (cel_color(c,color) ? " est " : " n'est pas ") << color_to_string(color) << "." << endl;

int main(int argc, char const *argv[])
{
	
	Cellule c1(false, 0, 0);
	Cellule c2(true, 0, 1);
	Cellule c3(false, 0, 2);
	Cellule c4(true, 1, 0);
	Cellule c5(false, 1, 1);
	Cellule c6(true, 1, 2);
	Cellule c7(false, 2, 0);
	Cellule c8(true, 2, 1);
	Cellule c9(false, 2, 2);

	Cellule tab[3][3];
	tab[0][0] = c1;
	tab[0][1] = c2;
	tab[0][2] = c3;
	tab[1][0] = c4;
	tab[1][1] = c5;
	tab[1][2] = c6;
	tab[2][0] = c7;
	tab[2][1] = c8;
	tab[2][2] = c9;

	for(int i=0; i < 3; i++){
		for (int j=0; j < 3; j++){
			PrintCell(tab[i][j],i,j);
			tab[i][j].print();

		}
	}

	int k,l;
	int b;
	cout << " Vous voulez changer une cellule ? si oui laquelle ? ";
	cin >> k >> l;
	cout << " Vivante ou morte ? (Vivante = 1 | Morte = 0) ";
	cin >> b;
	tab[k][l] = Cellule(b,k,l);

	for(int i=0; i < 3; i++){
		for (int j=0; j < 3; j++){
			PrintCell(tab[i][j],i,j);
			tab[i][j].print();

		}
	}



}


//g++ -Wall cellule.cpp cellule-main.cpp -o cell


//, c2;
// c2.setVivante(!c2.getVivante());
// c2.setX(c1.getX());
// c2.setY(c1.getX() + c1.getY());
// PrintCell(c1); PrintCell(c2);
// c1.test_cell(); c2.test_cell();
// PrintVoisines(c1, c2); PrintVoisines(c2, c1);
// PrintCelColor(c1,Cellule::BLACK);
// return 0;