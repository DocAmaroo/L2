#include "tableau-int.h"
#include <iostream>
TableauInt::TableauInt(): _donnees(new int[1]), _n(0), _alloc(1){}
TableauInt::TableauInt(size_t n): _donnees(new int[n]), _n(n), _alloc(n){}
TableauInt::TableauInt(const TableauInt& T): _donnees(new int[T.size()]), _n(T.size()), _alloc(T.size()){
  for (size_t i = 0; i < T.size(); i++) {
    _donnees[i] = T[i];
  }
}

TableauInt::~TableauInt(){
  delete[] _donnees;
}

size_t TableauInt::size() const{ return _n; }

int& TableauInt::at(const size_t &n){
  if( n >= _n ){
    std::cerr << "Tu es moche" << std::endl;
    std::terminate();
  }
  return _donnees[n];
}

int& TableauInt::operator[](const size_t &n){
  return at(n);
}

const int& TableauInt::at(const size_t &n) const{
  if( n >= _n ){
    std::cerr << "Tu es moche" << std::endl;
    std::terminate();
  }
  return _donnees[n];
}

const int& TableauInt::operator[](const size_t &n) const{
  return at(n);
}

TableauInt& TableauInt::operator=(const TableauInt &T){
  if( this != &T ){
    delete[] _donnees;
    _donnees = new int[T.size()];
    _n = T.size();
    _alloc = _n;
    for (size_t i = 0; i < T.size(); i++) {
      _donnees[i] = T[i];
    }
  }
  return *this;
}

void TableauInt::extend(){
  if( !(_n < _alloc)){
    _alloc = 2 * _alloc;
    int* temp = new int[_alloc];
    for (size_t i = 0; i < _n; i++) {
      temp[i] = _donnees[i];
    }
    delete[] _donnees;
    _donnees = temp;
    std::cout << "Tableau Etendu : " << _alloc << std::endl;
  }
}

void TableauInt::push_back(int entier) {
  extend();
  _donnees[_n] = entier;
  _n++;
}
// FIN METHODES TABLEAUINT
void write(std::ostream& flux, const TableauInt& T){
  flux << "[";
  for (size_t i = 0; i < T.size()-1; i++) {
    flux << T[i] << "|";
  }
  flux << T[T.size()-1] << "]" << std::endl;
}
