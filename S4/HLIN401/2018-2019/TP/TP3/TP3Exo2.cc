#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "AffichageMaisons.h"
#include <limits.h>

#define dcouv 100

void GenererMaisons(int n, int coordMaisons[][2])
{
  for(int i=0;i<n;i++)
  {
    coordMaisons[i][0]=10+rand()%593;
    coordMaisons[i][1]=10+rand()%773;
  }
}

void Initialiser(int n, int a[])
{
  for(int i(0); i<n ;i++) 
    a[i]=0;
}

bool Couvre(int i, int j, const int coordMaisons[][2])
{

  if ( i == j )  { return true; }
  size_t distance = sqrt( pow(coordMaisons[i][0]-coordMaisons[j][0],2) +  pow(coordMaisons[i][1]-coordMaisons[j][1],2));

  return distance <= dcouv;

}

int ChoixProchaineMaison(int n, const int coordMaisons[][2], const int dejaCouvertes[])
{

  int nbMaisonCouverte, maxCouverte = 0, positionMaisonQuiCouvreLePlus = 0;

  for (int i = 0; i < n; i++)
  {
    nbMaisonCouverte = 0;
    for (int j = 0; j < n; j++)
    { 
      if ( Couvre(i, j, coordMaisons) && (dejaCouvertes[j] == 0))
        nbMaisonCouverte++;
    }

    if (nbMaisonCouverte > maxCouverte) {
      maxCouverte = nbMaisonCouverte;
      positionMaisonQuiCouvreLePlus = i;
    }

  }
  return positionMaisonQuiCouvreLePlus;
}

/*
 * function : printDejaCouverte
 * description : affiche le tableau "dejaCouvertes" 
*/
void printDejaCouverte(int n, int dejaCouvertes[]){
  cout << "\n### Liste des maison couverte ###\n[ ";
  for(int i=0; i < n; i++){ (i != n-1)? cout << dejaCouvertes[i] << ", " : cout << dejaCouvertes[i]; }
    cout << " ]\n";
}

/*
 * function : printEmetteur
 * description : affiche le tableau "emetteurs" 
*/
void printEmetteur(int n, int emetteurs[]){
  cout << "\n### Liste des emetteurs ###\n[ ";
  for (int i = 0; i < n; i++){  (i != n-1)? cout << emetteurs[i] << ", " : cout << emetteurs[i]; }
    cout << " ]\n";

}

int ChoixEmetteurs(int n, const int coordMaisons[][2], int emetteurs[])
{

  int nbCouvert(0), totalCouvert(0), totalEmetteur(0), maisonOpt(0);

  int dejaCouvertes[n];
  for(int i(0); i < n; i++)
    dejaCouvertes[i] = 0;

  if ( n == 0 ){ return 0; }
  if ( n == 1 ){ emetteurs[0] = 1, dejaCouvertes[0] = 1; return 1; }

  while(totalCouvert != n)
  {
    maisonOpt = ChoixProchaineMaison(n, coordMaisons, dejaCouvertes);
    emetteurs[maisonOpt] = 1;
    totalEmetteur++;

    for (int i(0); i < n; i++){
      if (Couvre(i, maisonOpt, coordMaisons) && (dejaCouvertes[i] == 0)){
        dejaCouvertes[i] = 1;
        totalCouvert+=1;
      }
    }
  }

  return totalEmetteur;
}

int suivant(int n, int tab[])
{
  int i = 0;
  while (i < n and tab[i] == 1) tab[i++] = 0;
  if (i == n) return 1;
  tab[i] = 1;
  return 0;
}

bool couvreTout(int n, const int coordMaisons[][2], const int emetteurs[]) {
  int couverts[n];
  Initialiser(n, couverts);

  for(int i(0); i<n; i++) {
    if(emetteurs[i] == 1) {
      for(int j(0); j<n; j++) {
        if(Couvre(i, j, coordMaisons)) couverts[j] = 1;
      }
    }
  }

  int nbCouverts(0);
  for(int i(0); i<n; i++) {
    if(couverts[i] == 1) nbCouverts++;
  }

  return nbCouverts == n;
}

void recopier(int n, int tab1[], int tab2[]) {
  for(int i(0); i<n; i++)
    tab2[i] = tab1[i];
}

int ChoixEmetteursOpt(int n, const int coordMaisons[][2], int emetteurs[])
{
  if(n==0) return 0;

  int tab[n];
  Initialiser(n, tab);

  int minEmetteurs = INT_MAX;
  int tabMin[n];

  while(!suivant(n, tab)) {
    int nbEmetteurs(0);
    for(int i(0); i<n; i++) {
      if(tab[i] == 1) nbEmetteurs++;
    }

    if(couvreTout(n, coordMaisons, tab)) {
      if(nbEmetteurs < minEmetteurs) { 
        recopier(n, tab, tabMin);
        minEmetteurs = nbEmetteurs;
      }
    }
  }

  recopier(n, tabMin, emetteurs);

  return minEmetteurs;
}

int main(int argc, char** argv)
{
  int n;
  if (argc < 2)
  {
    cout << "Entrer le nombre de maisons: ";
    cin >> n;
  }
  else
  {
    n = atoi(argv[1]);
  }
  
  srand(time(NULL));

  int coordMaisons[n][2]; // coordonnées des maisons dans le plan
  int emetteurs[n];       // numéro des maisons que l'on choisit pour placer des émetteurs

  GenererMaisons(n, coordMaisons);
  AffichageMaisons(n, coordMaisons, "Maisons");
  Initialiser(n, emetteurs);

  int dejaCouvertes[n];
  for( int i = 0; i < n; i++){
    dejaCouvertes[i] = 0;
  }

  int nbEmetteurs = ChoixEmetteurs(n, coordMaisons, emetteurs);
  cout << "Nombre d'émetteurs placés : "<< nbEmetteurs << endl;
  AffichageMaisonsEmetteurs(n, coordMaisons, emetteurs, "Emetteurs");

  int emetteursOpt[n];
  Initialiser(n, emetteursOpt);
  int nbEmetteursOpt = ChoixEmetteursOpt(n, coordMaisons, emetteursOpt);
  cout << "Nombre d'émetteurs optimal : " << nbEmetteursOpt << endl;
  AffichageMaisonsEmetteurs(n, coordMaisons, emetteursOpt, "EmetteursOpt");
  

  return 0;
}

#undef dcouv