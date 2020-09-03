#ifndef TABLEAUINT_H
#define TABLEAUINT_H
#include <iostream>

class TableauInt{
private:
  int * _donnees;
  size_t _n;
  size_t _alloc;
public:
  // Constructeur
  TableauInt();
  TableauInt(size_t n);
  TableauInt(const TableauInt &T);
  //Destructeur
  ~TableauInt();
  //Accesseur
  size_t size() const; // _n
  int& at(const size_t &n); // la case n par ref
  const int& at(const size_t &n) const;
  //Surchage de []
  const int& operator[](const size_t &n) const;
  int& operator[](const size_t &n);
  TableauInt& operator=(const TableauInt &Tab);
  //Extension
  void extend();
  //push_back
  void push_back(int);
};

void write(std::ostream&, const TableauInt&);

#endif
