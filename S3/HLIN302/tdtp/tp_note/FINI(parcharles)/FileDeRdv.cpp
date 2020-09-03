#include "FileDeRdv.h"

FileDeRdv::FileDeRdv() : _premierRDV(NULL), _dernierRDV(NULL) {}

FileDeRdv::FileDeRdv(const FileDeRdv& autreFile) : 
_premierRDV(duplicate(autreFile._premierRDV)), _dernierRDV(duplicate(autreFile._dernierRDV)) {}

FileDeRdv& FileDeRdv::operator=(const FileDeRdv& autreFile) {
	if(this != &autreFile) {
		_premierRDV = duplicate(autreFile._premierRDV);
		_dernierRDV = duplicate(autreFile._dernierRDV);
	}
	return *this;
}
FileDeRdv::~FileDeRdv() {
	suppress(_premierRDV);
}

void FileDeRdv::ajouterRDV(Rdv& rdv) {
	if(_dernierRDV != NULL)
		_dernierRDV->setProchainRDV(rdv);

	_dernierRDV = &rdv;
	if(_premierRDV == NULL) _premierRDV = &rdv;
}

void FileDeRdv::supprimerRDV(Rdv& rdv) {
	if(_premierRDV != NULL)
		_premierRDV = &_premierRDV->getProchainRDV();
}

Rdv& FileDeRdv::getPremierRDV() {return *_premierRDV;}
Rdv& FileDeRdv::getDernierRDV() {return *_dernierRDV;}

void suppress(Rdv* rdv) {
	if(rdv == NULL) return;
	Rdv* next = &rdv->getProchainRDV();
	if(next) suppress(next);

	delete rdv;
}

Rdv* duplicate(const Rdv* rdv) {
	if(rdv == NULL) return NULL;
	Rdv* duplicat = new Rdv(*rdv);

	const Rdv* prochain = &rdv->getProchainRDV();
	if(prochain) duplicat->setProchainRDV(*duplicate(prochain));
	return duplicat;
}