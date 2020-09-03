//============================================================================
// Name        : TP4.cpp
// Author      : Canta Thomas
// Version     : /
// Copyright   : Your copyright notice
// Description : cpp file
//============================================================================

//AB.cpp


//SortieLatex.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include "AB.h"


using namespace std;

Sommet::Sommet(Sommet& s){
  racine = s.racine; 

  FGP = s.FGP; 

  if (s.SAD != NULL){
    SAD = new Sommet(*s.SAG);
    SAD->Pere = this;
  }
  else
    SAD = NULL;
  
  if (s.SAG != NULL){
    SAG = new Sommet(*s.SAD);
    SAG->Pere = this;
  }
  else
    SAG = NULL;
}


bool Sommet::FeuilleP(){
  return (SAG==NULL && SAD == NULL);
}

void Sommet::SupprimerSAG(){
  SAG = NULL;
}

void Sommet::SupprimerSAD(){
  SAD = NULL;
}

void Sommet::GrefferSAG(AB g){
  SupprimerSAG();
  SAG = g;
  g->Pere = this;
 }

void Sommet::GrefferSAD(AB d){
  SupprimerSAD();
  SAD = d;
  d->Pere = this;
 }


void Sommet::RemplacerPourLePerePar(AB Ar){
  if (Pere != NULL and Ar != NULL){
    if (FGP) {
      Pere->GrefferSAG(Ar);
    }
    else {
      Pere->GrefferSAD(Ar);
    }
  }
}

//SortieLatex.cpp

typedef int Valeur;

class Sommet;

typedef Sommet* AB;

void SortieLatex(AB Ar, std::string filepath);

std::string* TikzRecursAB(int ligne,int gauche, int droite, int numeroPere, int typeFils, AB Ar);

std::string * TikzRecursAB(int ligne,int gauche, int droite, int numeroPere, int typeFils, AB Ar){
  std::ostringstream ossnum, osslign,osscol,ossnumPere, ossbal, ossnum2Pere,ossnumRac;

      std::string stres("");

      if (Ar) {
    ossnumPere<<numeroPere;
    ossnumRac<<"(\\textcolor{red}{" << Ar->racine << "})\\\\this=\\textcolor{red}{" <<Ar <<"}\\\\Pere=\\textcolor{red}{"<<Ar->Pere << "} (FGP=\\textcolor{red}{" << (Ar->FGP?"Gauche":"Droit") <<"})";

    if (Ar->Pere )ossnum2Pere<<Ar->Pere->racine; else ossnum2Pere<<0;

    int numero;
    if (typeFils==-1) { numero=1; } else { numero= 2*numeroPere + typeFils; }
    ossnum<<numero;
    osslign<<ligne;
    int mil = (gauche + droite)/2;

    osscol<<mil;

    stres="\\node[draw, color=black, rounded corners=5pt, text width=3cm, text centered] (SZ" + ossnum.str()    + ") at " +
	  "("   + osscol.str()    + ", " + osslign.str() + ") " + 
	  "{ "  + ossnumRac.str() + "};\n";

    if (typeFils!=-1) stres+="\\draw[->, >=latex, color=blue] (SZ"+ossnumPere.str()+") -- (SZ"+ossnum.str() +");\n";

    if (Ar->SAG) stres+=*TikzRecursAB(ligne-3,gauche,mil-13,numero,0,Ar->SAG);
    if (Ar->SAD) stres+=*TikzRecursAB(ligne-3,mil+13,droite,numero,1,Ar->SAD); 
 }
  return new std::string(stres);
}

std::string * TikzAB(AB Ar){
  return TikzRecursAB(1,1,10,1,-1,Ar);
}

 void SortieLatex(AB Ar, std::string filepath){ //don't insert garbage in filepath, its std::system-ised.
 std::ofstream fichier(filepath.c_str(), std::ios::out | std::ios::trunc);
 std::string preamb ("\\documentclass{article} \n \\usepackage{tikz} \n \\begin{document} \n \\resizebox{300pt}{!}{\n \\begin{tikzpicture}\n");
  std::cout<<preamb<<"\n";
std::string post("\\end{tikzpicture}\n } \\end{document} \n"); //rsz box end?
  std::cout<<post<<"\n";
 std::cout<<*TikzAB(Ar)<<"\n";
std::string   res1(preamb + *TikzAB(Ar));
 std::string   res(res1 + post);
 //std::cout<<res1<<"\n";
  fichier <<res<<"\n";
  fichier.close();

  std::ostringstream system_CARE;
  // /dev/null 2>&1 isnt enough to mute pdflatex...
  system_CARE << "mkdir pdflatex_temp > /dev/null 2>&1;" 
              << "pdflatex -output-directory=\"./pdflatex_temp\" -interaction=nonstopmode \"" << filepath << "\" >/dev/null 2>&1;"
	      << "mv ./pdflatex_temp/*.pdf ./ > /dev/null 2>&1;";
  std::system(system_CARE.str().c_str());
  return;
}


Sommet::Sommet(Valeur v){
  racine = v;
  Pere = NULL;
  SAG = NULL;
  SAD = NULL; 
}

int main(){
  
  AB A0 = new Sommet(6);
  cout << "A0 = " << A0->racine << endl;

  AB A1 = new Sommet(0);
  cout << "A1 = " << A1->racine << endl;

  AB A2 = new Sommet(0);
  cout << "A2 = " << A2->racine << endl;

  AB A3 = new Sommet(2);
  cout << "A3 = " << A3->racine << endl;

  AB A4 = new Sommet(3);
  cout << "A4 = " << A4->racine << endl;

  AB A5 = new Sommet(2);
  cout << "A5 = " << A5->racine << endl;

  AB A6 = new Sommet(3);
  cout << "A6 = " << A6->racine << endl;

  A2->GrefferSAG(A5);
  A2->GrefferSAD(A6);  
  A1->GrefferSAG(A3);
  A1->GrefferSAD(A4);
  A0->GrefferSAG(A1);
  A0->GrefferSAD(A2);

  AB A7 = new Sommet(*A0);
  cout << "Racine de A7 = " << A7 << A7->racine << endl;

  A7->SupprimerSAG();
  A7->SupprimerSAD();

  bool A7feuille = A7->FeuilleP();
  if(A7feuille){
    cout << " A7 est une feuille !" << endl;
  }
  else{
    cout << "A7 n'est pas une feuille" << endl;
  }

  //impression
  SortieLatex(A0, "monfichier");
  
  return 0;

}

// affichage en pdf :
// source /net/apps/texlive/set_texlive
// g++ AB.cpp
// ./a.out
