#include <iostream>
#include "cellule.h"
using namespace std;

//default
Cellule::Cellule():age(0),x(0),y(0),color(BLACK){}

Cellule::Cellule(bool state, unsigned int position_x, unsigned int position_y):
age(state? 1 : 0), x(position_x), y(position_y), color(state? BLUE : BLACK){}

//accesseurs en lecture
unsigned int Cellule::getX() const{ return x; }
unsigned int Cellule::getY() const{ return y; }
bool Cellule::getVivante() const{ return age; }
Cellule::Color Cellule::getColor() const { return color; }

//accesseurs en écriture
void Cellule::setX(unsigned int position_x){ x = position_x; }
void Cellule::setY(unsigned int position_y){ y = position_y; }
void Cellule::setVivante(bool state){ 
	if (state) { 
		color = (age++ ? GREEN : BLUE);
	}
	else {
		age = 0;
		color = BLACK; 
	}
}

//methodes
void Cellule::test_cell() const {
	cout << "La cellule (à l'adresse mémoire " << this << ") = {"
	<< (age ? "vivante" : "morte")
	<< ", " << x << "x" << y << "}"
	<< endl; }

bool Cellule::estVoisine(Cellule c) const { return ( age && ( (x-c.x)*(x-c.x) + (y-c.y)*(y-c.y) ) <= 2 ); }

void Cellule::doitMourir(){
	if (age){
		color = (color == BLUE ? YELLOW : RED );
	}
}

bool cel_color(Cellule c, Cellule::Color color){
	return (c.getColor() == color);
}

string color_to_string(Cellule::Color c) {
	switch (c) {
		case Cellule::BLACK:
		return "\033[1;30mnoire\033[0m";

		case Cellule::BLUE:
		return "\033[1;34mbleue\033[0m";

		case Cellule::GREEN:
		return "\033[1;32mXvert\033[0m";

		case Cellule::RED:
		return "\033[1;31mXrouge\033[0m";

		case Cellule::YELLOW:
		return "\033[1;33mXjaune\033[0m";
	}
	return "non définis";
}

