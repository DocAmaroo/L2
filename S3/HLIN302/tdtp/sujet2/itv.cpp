#include <iostream>
#include "itv.h"
using namespace std;

//définition d'une valeur par défault
Itv::Itv():bi(0.0), bs(0.0){}

Itv::Itv(double binf, double bsup) :bi(binf), bs(bsup){
	if (binf > bsup){
		cerr << "Invalide : (binf="<<binf<<"> bsup="<<bsup<<") pour les création de l'intervalle on les inverses";
		bi = bsup;
		bs = binf;
	}
}

//accesseur en lecture
double Itv::getbi() const{
	return bi;
}

double Itv::getbs() const{
	return bs;
}

//accesseur en écriture
void Itv::set_new_bi(double NEW_BI){
	if (NEW_BI > bs){
		cerr << "bi n'a pas été modifié car " << NEW_BI << ">" << bi << endl;
	}
	else{
		bi = NEW_BI;
	}
}

void Itv::set_new_bs(double NEW_BS){
	if (NEW_BS < bi){
		cerr << "bi n'a pas été modifié car " << NEW_BS << "<" << bi << endl;
	}
	else{
		bs = NEW_BS;
	}
}

//longueur
double Itv::longueur() const {
	return (bs-bi); 
}

// x€[bs,bi]
bool Itv::appartient(double x) const {
	return { (x>=bi) && (x<=bs) };
}

//afficher
void Itv::afficher() const{
	cout << "[" << bi << "," << bs << "]" << endl;
}

//egal a I2
bool Itv::egal(Itv I2) const {
	return ( (bi == I2.bi) && (bs == I2.bs) );
}

//inclus dans I2
bool Itv::inclus(Itv I2) const {
	return ( (bi >= I2.bi && bs < I2.bs) || (bi > I2.bi && bs <= I2.bs) );
}

//disjoint de I2
bool Itv::disjoint(Itv I2) const {
	return ( (bi > I2.bs || bi < I2.bi) && (I2.bi > bs || I2.bi < bi) );
}


//accolé à I2
bool Itv::accole(Itv I2) const {
	return ( (bi == I2.bs) || (bs == I2.bi));
}

//imbriqué avec I2
bool Itv::imbrique(Itv I2) const {
	return ( !accole(I2) && !disjoint(I2) && !inclus(I2) && !egal(I2));
}

//méthode translater
void Itv::translate(double x){
	bi += x;
	bs += x;
}

void translate(Itv I, double x){
	I.translate(x);
}

