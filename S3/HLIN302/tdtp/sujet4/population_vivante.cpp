#include <iostream>
#include <cstdlib>
#include <exception>
#include "population_vivante.h"
using namespace std; 

#define CHECK_BOUND(i,j)						\
  if (i>=N || j>=N){							\
    std::cout<<"Accessing a Cell at ("<<i<<","<<j<<") out of range ... aborting"<<std::endl; \
    std::terminate();							\
  }									\

const Cellule* PopulationVivante::at(size_t i, size_t j) const {
  for (size_t k = 0 ; k < alive ; k++) {
    if ((T[k].getX() == i) && (T[k].getY() == j)) {
      return T+k;
    }
  }
  return NULL;
}

Cellule* PopulationVivante::at(size_t i, size_t j)  {
  for (size_t k = 0 ; k < alive ; k++) {
    if ((T[k].getX() == i) && (T[k].getY() == j)) {
      return T+k;
    }
  }
  return NULL;
}

size_t PopulationVivante::nb_voisins_vivants(size_t ci, size_t cj) const {
  size_t cpt=0;
  size_t imin,imax,jmin,jmax;
  imin = ci==0?ci:ci-1;
  imax = ci==(N-1)?ci:ci+1;
  jmin = cj==0?cj:cj-1;
  jmax = cj==(N-1)?cj:cj+1;
  
  for (size_t i = imin ; i <= imax ; i++) {
    for (size_t j = jmin ; j <= jmax ; j++) {
      if (at(i,j) != NULL) {
	cpt++;
      }
    }
  }
  return cpt - (at(ci,cj) != NULL ? 1 : 0);
}

void PopulationVivante::updateColors() {
  //calcule les cellules vivantes qui vont mourir  
  for (size_t i = 0; i < alive; i++) {
    size_t voisin=nb_voisins_vivants(T[i].getX(), T[i].getY());
    if ((voisin != 2) && (voisin != 3)) T[i].doitMourir();  
  }
}

PopulationVivante::PopulationVivante(size_t n, float prob) : alive(0), N(n), probability(prob) {
  reset();
}


size_t PopulationVivante::nb_cellules(Cellule::Couleur c) const {
  size_t cpt=0;
  for (size_t i = 0 ; i < alive ; i++) {
      if (CelluleEstDeLaCouleur(T[i],c)) {
	cpt++;
      }    
  }
  return cpt;
}

size_t PopulationVivante::nb_vivants()    const { return alive;}
size_t PopulationVivante::nb_deces()     const { return nb_cellules(Cellule::ROUGE)+nb_cellules(Cellule::JAUNE);}
size_t PopulationVivante::nb_morts()      const { return N*N-nb_vivants();}
size_t PopulationVivante::nb_naissances() const { return nb_cellules(Cellule::BLEU);}



Cellule PopulationVivante::getCelluleCopie(size_t i, size_t j) const {
  CHECK_BOUND(i,j);
  const Cellule* ptr=at(i,j);
  if (ptr==NULL) {
    return Cellule(false,i,j);
  } else {
    return *ptr;
  }
}



void PopulationVivante::printCell(size_t i, size_t j) const {
  CHECK_BOUND(i,j);
  getCelluleCopie(i,j).print();
}   

void PopulationVivante::kill(size_t i, size_t j) {
  CHECK_BOUND(i,j);
  const Cellule* ptr=at(i,j);
  if (ptr!=NULL) {
    size_t k=ptr-T; // retrouve la position dans le tableau
    for ( ; k < alive - 1 ; k++) {
      T[k]=T[k+1];
    }
    alive--;
  }
}
    
void PopulationVivante::birth(size_t i, size_t j) {
  if (alive+1<NMAX){
    CHECK_BOUND(i,j);
    Cellule* ptr=at(i,j);
    if (ptr==NULL) {
      T[alive]=Cellule(true,i,j);    
      alive++;
    }
    else{
      ptr->setVivante(true);
    }
  }
  else {
    std::cerr<<"PopulationVivante: Erreur -> trop de cellule vivante pour NMAX="<<NMAX<<std::endl;
    std::cerr<<"aborting...\n";
    std::terminate();
  }
}

void PopulationVivante::print() const {  
  cout<<endl;
  for (size_t i = 0 ; i < N ; i++) {
    for (size_t j = 0 ; j < N ; j++) {
      cout<<Couleur2String(getCelluleCopie(i,j).getCouleur());
    }
    cout<<endl;
  }
  cout<<endl;
}

PopulationVivante PopulationVivante::next() const {
  PopulationVivante POP(*this);
  for (size_t i = 0 ; i < N ; i++) {
    for (size_t j = 0 ; j < N ; j++) {
      size_t voisin=nb_voisins_vivants(i,j);
      if ((voisin == 3) || ((voisin == 2) && (at(i,j) != NULL))) {
	POP.birth(i,j);
      } else {
	POP.kill(i,j);
      }
    }
  }
  POP.updateColors();
  return POP;
}


/// NEW STUFF TD4

size_t PopulationVivante::getDimension() const {return N;}

float  PopulationVivante::getProbability() const {return probability;}

void PopulationVivante::setDimension(size_t n) {N=n; reset();}

void PopulationVivante::setProbability(float p) {probability=p; reset();}


void PopulationVivante::reset() {
  alive=0;
  srand(time(NULL));
  for (size_t i = 0 ; i < N ; i++) {
    for (size_t j = 0 ; j < N ; j++){
      if (((rand() % 10000) ) <= 10000.*probability)
	{
	  birth(i,j);
	}
    }
  }
  updateColors();
}
