#include "tableau-cellule.h"
#include <iostream>

TableauCellule::TableauCellule(): _tabcel(new Cellule[1]), _n(0), _alloc(1){};
TableauCellule::TableauCellule(size_t n): _tabcel(new Cellule[n]), _n(n), _alloc(n){};
TableauCellule::TableauCellule(const TableauCellule &T): _tabcel(new Cellule[T._n]), _n(T._n), _alloc(T._n){
  for (size_t i = 0; i < T._n; i++) {
    _tabcel[i] = T[i];
  }
}

TableauCellule::~TableauCellule(){
  delete[] _tabcel;
};

const Cellule& TableauCellule::operator[](const size_t &n) const{
  return _tabcel[n];
}

Cellule& TableauCellule::operator[](const size_t &n){
  return _tabcel[n];
};

TableauCellule& TableauCellule::operator=(const TableauCellule &T){
  if( this != &T ){
    delete[] _tabcel;
    _tabcel = new Cellule[T._n];
    _n = T._n;
    _alloc = _n;
    for (size_t i = 0; i < _n; i++) {
      _tabcel[i] = T[i];
    }
  }
  return *this;
}

void TableauCellule::extend(){
  if( !(_n < _alloc)){
    _alloc = 2 * _alloc;
    Cellule* temp = new Cellule[_alloc];
    for (size_t i = 0; i < _n; i++) {
      temp[i] = _tabcel[i];
    }
    delete[] _tabcel;
    _tabcel = temp;
  }
}

void TableauCellule::push_back(Cellule cel) {
  extend();
  _tabcel[_n] = cel;
  _n++;
}



void cellread(std::istream& flux, Cellule& C){
  unsigned int x,y,b;
  std::cout << "X =";
  flux>>x;
  std::cout << "Y =";
  flux>>y;
  std::cout << "Vivante =";
  flux>>b;
  C.setX(x);
  C.setY(y);
  C.setVivante(b);
}
void TableauCellule::read(std::istream& flux){
  for (size_t i = 0; i < _n; i++) {
    cellread(flux,_tabcel[i]);
  }
}
void cellwrite(std::ostream& flux, Cellule& C){
  flux <<"X :"<< C.getX() <<" Y :"<< C.getY() <<" Vivante:"<< C.getVivante() <<std::endl;
}
void TableauCellule::write(std::ostream& flux){
  for (size_t i = 0; i < _n; i++) {
    cellwrite(flux,_tabcel[i]);
  }
}

int TableauCellule::find(Cellule& C){
  for (size_t i = 0; i < _n; i++) {
    if( identique(_tabcel[i],C) ){
      return i;
    }
  }
  return -1;
}

bool identique(const Cellule& C1, const Cellule& C2){
  if( C1 == C2 ){
    return true;
  } else {
    return false;
  }
}

void TableauCellule::erase(int idx){
  if (idx>=0 && idx<(int)_n){
    for(size_t i=idx;i<_n-1;i++)
    _tabcel[i]=_tabcel[i+1];
    _n--;
  }
}
