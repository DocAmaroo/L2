//============================================================================
// Name        : TP6.cpp
// Author      : Canta Thomas
// Version     : /
// Copyright   : Your copyright notice
// Description : cpp file
//============================================================================

// Mettre dans le même dossier AB.h !

#include "Tas.h"
#include "AB.h"
#include <iostream>
#include <cmath>

ArbreParfait::ArbreParfait(int h){
  hauteur = h;
  tailleMax = pow(2,h+1)-1;
  IndicePremierSommetLibre = 0;
  contenu = new int[tailleMax];
}


void ArbreParfait::Echanger(indiceDansTableauSommet a, indiceDansTableauSommet b){

  int tmp = contenu[a];
  contenu[a] = contenu[b];
  contenu[b] = tmp;
  
}


int ArbreParfait::AjouteSommetArbreParfait(int s){
  if(IndicePremierSommetLibre < tailleMax){
    contenu[IndicePremierSommetLibre] = s;
    IndicePremierSommetLibre++;
    return 1;
  }
  else{
    return -1;
  }
}


bool ArbreParfait::SommetValide(indiceDansTableauSommet h){
  return ( h < IndicePremierSommetLibre );
}

indiceDansTableauSommet ArbreParfait::Racine(){
  
  return contenu[0];
  
}

indiceDansTableauSommet ArbreParfait::Pere(indiceDansTableauSommet i){

  return i == 0 ? 0 : (i - 1)/2 ;

}


indiceDansTableauSommet ArbreParfait::FilsGauche(indiceDansTableauSommet i){

  return (i * 2) + 1;

}

indiceDansTableauSommet ArbreParfait::FilsDroit(indiceDansTableauSommet i){

  return (i * 2) + 2;
  
}


bool ArbreParfait::FeuilleP(indiceDansTableauSommet i){
  
  return ( SommetValide(i) && !SommetValide(FilsGauche (i)) && !SommetValide(FilsDroit (i)) );
  
}


void ArbreParfait::SupprimerArbreParfait(indiceDansTableauSommet i){

  Echanger(i, IndicePremierSommetLibre -1);
  IndicePremierSommetLibre--;
  
}

//compile : g++ -Wall Tas.cpp -o tas
//execute : ./tas