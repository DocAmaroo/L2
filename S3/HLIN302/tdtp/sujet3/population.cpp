#include <iostream>
#include "population.h"
#include <exception>
using namespace std;

#define VERIF(i,j) if (i>=N || j>=N){ \
cout<<"Cell at ["<<i<<","<<j<<"] out of range\n...Aborting"<<endl; terminate() ;}


Population::Population(){
	for (size_t i = 0 ; i < N ; i++) {
		for (size_t j = 0 ; j < N ; j++) {
			T[i][j].setX(i);
			T[i][j].setY(j);
			T[i][j].setVivante(false);
		}
	}
}

size_t Population::nb_cell(Cellule::Color color) const {
	size_t same_color_cell=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			if ( cel_color(T[i][j], color) ){
				same_color_cell++;
			}
		}
	}
	return same_color_cell;
}

void Population::init(size_t n){
	srand(time(NULL));
	if(nb_alive()==0 && n <= N*N){
		size_t i,j;
		for (size_t k = 0 ; k < n ; k++) {
			do {
				i=rand()% N;
				j=rand()% N;
			} 
			while ((T[i][j]).getVivante());
			T[i][j].setVivante(true);
		}
	}
}

size_t Population::nb_alive() const{ return N*N-nb_dead() ;}
size_t Population::nb_dead() const{ return nb_cell(Cellule::BLACK) ;}
size_t Population::nb_dying() const{ return nb_cell(Cellule::RED)+nb_cell(Cellule::YELLOW) ;}
size_t Population::nb_birth() const{ return nb_cell(Cellule::BLUE) ;}

Cellule Population::getCellCopy(size_t i, size_t j) const{ 
	VERIF(i,j);
	return T[i][j];
}

const Cellule& Population::getCell(size_t i, size_t j) const{ 
	VERIF(i,j);
	return T[i][j];
}

void Population::printCell(size_t i, size_t j) const {
	VERIF(i,j);
	T[i][j].print();
}

void Population::print() const {
	for (size_t i = 0 ; i < N ; i++) {
		for (size_t j = 0 ; j < N ; j++) {
			cout<<color_to_string(T[i][j].getColor());
		}
		cout<<endl;
	}
	cout<<endl;

}

size_t Population::nb_voisin(size_t i, size_t j) const{
	size_t imin,imax,jmin,jmax;

	imin = i==0? 0 : i-1;
	imax = i==(N-1)? i : i+1;
	jmin = j==0? j : j-1;
	jmax = j==(N-1)? j : j+1;

	size_t res=0;
	for(size_t k=imin; k <= imax; k++ ){
		for( size_t l=jmin; l <= jmax; l++){

			//if coord k==i && l==j pass
			if( k==i && j==l ){
				continue;
			}

			if( T[k][l].getVivante()){
				res++;
			}
		}
	}
	return res;
}

Population Population::next() const{
	Population POP(*this);
	for(size_t i=0; i < N; i++){
		for (size_t j=0; j < N; j++){
			size_t nbvoisin = nb_voisin(i,j);
			if ( (nbvoisin == 2 && T[i][j].getVivante()) || nbvoisin == 3)
				POP.T[i][j].setVivante(true);
			else
				POP.T[i][j].setVivante(false);
		}
	}

	POP.updateColor();
	return POP;
}


void Population::updateColor(){
	for(size_t i=0; i < N; i++){
		for (size_t j=0; j < N; j++){
			if(nb_voisin(i,j) != 2 && nb_voisin(i,j) != 3 && T[i][j].getVivante()){
				T[i][j].doitMourir();
			}		
		}
	}
}