#ifndef TABLEAUCELLULE_H
#define TABLEAUCELLULE_H
#include "cellule.h"

class TableauCellule{
private:
  Cellule * _tabcel;
  size_t _n;
  size_t _alloc;
public:
  // Constructeurs
  TableauCellule();
  TableauCellule(size_t n);
  TableauCellule(const TableauCellule &T);
  ~TableauCellule();
  //Surcharge de []
  const Cellule& operator[](const size_t &n) const;
  Cellule& operator[](const size_t &n);
  //Surcharge de =
  TableauCellule& operator=(const TableauCellule &T);
  //Dynamisation des tableaux
  void extend();
  void push_back(Cellule cel);
  //read & write
  void read(std::istream& flux);
  void write(std::ostream& flux);
  //find
  int find(Cellule& C);
  //erase
  void erase(int);
};
bool identique(const Cellule& C1,const Cellule& C2);
void cellread(std::istream& flux, Cellule& C);
void cellwrite(std::ostream& flux, Cellule& C);
#endif
