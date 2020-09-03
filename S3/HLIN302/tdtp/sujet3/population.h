#ifndef POPULATION_H
#define POPULATION_H
#include "cellule.h"

#define N 50

class Population{

private:

	Cellule T[N][N];
	
	//return number of cell with same color
  	size_t nb_cell(Cellule::Color) const;

public:

	Population();

	//initialise n cell randomly
	void init(size_t);

	// interogation accesors
	size_t nb_alive() const;
	size_t nb_dead() const;
	size_t nb_birth() const; 
	size_t nb_dying() const;

	//copy of cell
	Cellule getCellCopy(size_t i, size_t j) const;
  	const Cellule& getCell(size_t i, size_t j) const;

  	// print a cell
  	void printCell(size_t i, size_t j) const;

  	//print population
  	void print() const;


  	//nb voisin of a cell
  	size_t nb_voisin(size_t i, size_t j) const;

  	//update Color
  	void updateColor();

  	//next population
  	Population next() const;
};




#endif