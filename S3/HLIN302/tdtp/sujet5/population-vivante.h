#ifndef __POPULATION_VIVANTE_H
#define __POPULATION_VIVANTE_H
#include "cellule.h"

#define NMAX 10000

class PopulationVivante {
 private:
  Cellule T[NMAX];
  size_t alive;
  size_t N;
  float probabilite;

  //Récupère le nombre de voisin
  size_t nb_voisins_vivants(size_t, size_t) const;

  //Accède a la cellule (i,j) et si c'est pas vivant NULL
  const Cellule* at(size_t i, size_t j)const;
  Cellule* at(size_t i, size_t j);

  // Mise à jour des couleurs des cellules qui décède
  void updateColors();

  //Retourne le nombre de cellule de la couleur donnée
  size_t nb_cellules(Cellule::Couleur) const;

 public:

  //Construction d'une population vide
  PopulationVivante(size_t n, float p);

  //Création de n cellules vivantes aléatoires
  //Semble moins utilie que regen()
  void init(size_t);

  //Accesseurs en lecture
  size_t nb_vivants()    const;
  size_t nb_deces()     const;
  size_t nb_morts()      const;
  size_t nb_naissances() const;
  size_t get_dimension() const;
  float get_probabilite() const;

  //Accesseurs en lecture d'une cellule
  Cellule getCelluleCopie(size_t i, size_t j) const;

  //Accesseurs en écriture
  void kill(size_t i, size_t j);
  void birth(size_t i, size_t j);
  void set_probabilite(float prob);
  void set_dimension(size_t d);


  //Affichage d'une cellule
  void printCell(size_t i, size_t j) const;
  //Affichage de la population
  void print() const;

  //Calcul de la population suivante
  PopulationVivante next() const;

  //Regéneration de la PopulationVivante
  void regen();
};

#endif
