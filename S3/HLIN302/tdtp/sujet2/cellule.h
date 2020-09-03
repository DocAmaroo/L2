#ifndef CELLULE_H
#define CELLULE_H

#include <iostream>
#include <string>

class Cellule
{

public:

	//color
	enum Color {
	BLACK, //dead cell
	BLUE, //new or resurrect cell
	GREEN, //growing cell
	RED, //dying cell
	YELLOW //birth & die
	};

private:

	//attributs
	size_t age;
	unsigned int x, y;
	Color color;


public:
	//constructeur
	Cellule();
	Cellule(bool state, unsigned int position_x, unsigned int position_y);

	//accesseurs en lecture
	unsigned int getX() const;
	unsigned int getY() const;
	bool getVivante() const;
	Color getColor() const;

	//accesseurs en écriture
	void setX(unsigned int posx);
	void setY(unsigned int posy);
	void setVivante(bool state);

	//Méthode
	void test_cell() const;
	bool estVoisine(Cellule c) const;
	void doitMourir();

};

bool cel_color(Cellule c, Cellule::Color color);

std::string color_to_string(Cellule::Color);

#endif