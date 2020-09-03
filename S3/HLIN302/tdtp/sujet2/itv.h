#ifndef ITV_H
#define ITV_H

class Itv
{
private:
	//attributs
	double bi;
	double bs;

public:
	//constructeurs
	Itv();
	Itv(double bi, double bs);

public:
	//accesseur en lecture
	double getbi() const;
	double getbs() const;

	//accesseur en écriture
	void set_new_bi(double NEW_BI);
	void set_new_bs(double NEW_BS);

	//longueur
	double longueur() const;

	// x€[bs,bi]
	bool appartient(double x) const;

	//afficher
	void afficher() const;


	/* compléments*/

	//égal a I1
	bool egal(Itv I2) const;

	//inclus dans I1
	bool inclus(Itv I2) const;

	//disjoint de I1
	bool disjoint(Itv I2) const;

	//accolé à I1
	bool accole(Itv I2) const;

	//imbriqué avec I1
	bool imbrique(Itv I2) const;

	//méthode translater
	void translate(double x);

};

#endif
