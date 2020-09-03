#include <iostream>
#include "cellule.h"
using namespace std;


//define
#define PrintCell(c1) cout << "l'adresse de la cellule " #c1 " est à l'adresse mémoire " << &c1 << endl;
#define PrintVoisines(c1,c2) cout << "La cellule " #c1 "" << (c1.estVoisine(c2)? " est " : " n'est pas ") << "voisine avec " #c2 "." << endl;
#define PrintCelColor(c,color) cout << #c << (cel_color(c,color) ? " est " : " n'est pas ") << color_to_string(color) << "." << endl;	

int main(int argc, char const *argv[])
{
	
	Cellule c1(true, 1, 2), c2;
	c2.setVivante(!c2.getVivante());
	c2.setX(c1.getX());
	c2.setY(c1.getX() + c1.getY());
	PrintCell(c1); PrintCell(c2);
	c1.test_cell(); c2.test_cell();
	PrintVoisines(c1, c2); PrintVoisines(c2, c1);
	PrintCelColor(c1,Cellule::BLACK);
	return 0;
}


//g++ -Wall cellule.cpp cellule-main.cpp -o cell