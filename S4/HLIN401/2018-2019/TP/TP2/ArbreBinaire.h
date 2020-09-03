#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

template<typename E>
struct noeud {
  E val;
  noeud<E>* pere;
  noeud<E>* filsG;
  noeud<E>* filsD;
};

template<typename E>
struct ArbreBinaire {
  noeud<E>* racine;
};

template<typename E>
ArbreBinaire<E>* ArbreVide(){
  ArbreBinaire<E>* arbre = (ArbreBinaire<E>*) malloc(sizeof(ArbreBinaire<E>));
  arbre->racine = NULL;
  return arbre;
}

template<typename E>
noeud<E>* creerNoeud(E valeur) {
  noeud<E>* x = (noeud<E>*) malloc(sizeof(noeud<E>));
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

template<typename E>
int dessinNoeud(noeud<E>* N, ofstream& output, int c)
{
  output << "  N" << c << " [label = \"" << N->val << "\"];" << endl;
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

template<typename E>
noeud<E>* sousarbre(int n, E T[], int i) {
  noeud<E>* P = creerNoeud(T[i]);
  if (2*i + 1 < n) {
    noeud<E>* G = sousarbre(n, T, 2*i+1);
    P->filsG = G;
    G->pere = P;
  }
  if (2*i+2 < n) {
    noeud<E>* D = sousarbre(n, T, 2*i+2);
    P->filsD = D;
    D->pere = P;
  }
  return P;
}

template<typename E>
ArbreBinaire<E>* arbre(int n, E T[]) {
  ArbreBinaire<E>* A = ArbreVide<E>();
  A->racine = sousarbre(n, T, 0);
  return A;
}

template<typename E>
void dessinArbre(ArbreBinaire<E>* arbre, string name)
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
  
template<typename E>
void dessinTas(int n, E T[], string name)
{
  ArbreBinaire<E>* A = arbre(n, T);
  dessinArbre(A, name);
}
