#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
#include "ArbreBinaire.h"

ArbreBinaire* ArbreVide(){
  ArbreBinaire* arbre = (ArbreBinaire*) malloc(sizeof(ArbreBinaire));
  arbre->racine = NULL;
  return arbre;
}

noeud* creerNoeud(int valeur) {
  noeud* x = (noeud*) malloc(sizeof(noeud));
  x->pere = NULL;
  x->filsG = NULL;
  x->filsD = NULL;
  x->val = valeur;
  return x;
}

void fauxNoeud(int c, string cote, ofstream& output) {
  output << "  " << cote << c << " [label=" << c << ", style = invis];" << endl;
  output << "  N" << c << "-> " << cote << c << " [style=invis];" << endl;
}

int dessinNoeud(noeud* N, ofstream& output, int c)
{
  output << "  N" << c << " [label = " << N->val << "];" << endl;
  int d = c;
  if (N->filsG) {
    output << "  N" << c << " -> N" << (c+1) << ";" << endl;
    d = dessinNoeud(N->filsG, output, c+1);
    if (!N->filsD) fauxNoeud(c, "D", output);
  }
  if (N->filsG or N->filsD) fauxNoeud(c, "C", output); 
  if (N->filsD) {
    if (!N->filsG) fauxNoeud(c, "G", output);
    output << "  N" << c << " -> N" << (d+1) << ";" << endl;
    d = dessinNoeud(N->filsD, output, d+1);
  }
  return d;
}

void dessinArbre(ArbreBinaire* arbre, string name)
{
  ofstream output;
  output.open(name + ".dot");
  output << "digraph G {" << endl;
  output << "  node [style=filled];" << endl;
  
  dessinNoeud(arbre->racine, output, 0);

  output << "}" << endl;
  output.close();

  if (!system(NULL)) exit (EXIT_FAILURE);
  string s = "dot -Tpdf " + name + ".dot > " + name + ".pdf";
  int i = system(s.c_str());
  if (i != 0) exit (EXIT_FAILURE);
}
  
