#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP3.h"
using namespace std;



bool estTrieeLSC(ListeSC L){
  //   Res : Renvoie true si L est une ListeSC tri�e, false sinon 

  if (estVideLSC(L) || estVideLSC(L->succ))
    return true;
  else
    return (L->info < (L->succ)->info) &&  estTrieeLSC(L->succ);
}



bool estListeIntervalle(ListeSC L){
  //   Res : renvoie true si L est une Liste intervalle, renvoie false sinon 
  // A COMPLETER
  ListeSC P = L;

  if (P == NULL || P->succ == NULL ) // si la liste est null ou son successeurs est null on renvoie true
  {
    return true;
  }

  while( P->succ != NULL ){ // tant que l'�l�ment suivant de la liste n'est pas null faire

    if( P->info+1 != (P->succ)->info ){ // si l'�l�ment [i]+1 est diff�rent de [i+1]
      return false; // on renvoie faux
    }

    P = P->succ;
  }

  return true;
}

ListeSC consListeIntervalle1(int l, int p){
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 
  //     Complexit� : l^2 / O(n^2)
  assert(l>0);
  
  int i; ListeSC L;
  L=NULL;
  for(i=0 ; i < l; i++)    
    insererFinLSC( L, p+i );
  return L;
}

ListeSC consListeIntervalle2(int l, int p){
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p
  //     Complexit� : l / O(n)

  assert(l>0);

  int k = l;
  ListeSC L; L=NULL; // on cr�e une variable L de type ListeSC qui vaut NULL

  for(int i=0; i < l; i++){

    L = creerLSC(p+k-1, L); // On cr�er une nouvelle liste avec comme nouvelle �l�ments p+k-1;
    k--; // on d�cr�mente k;

  }
  return L;
}


ListeSC consListeIntervalle3(int l, int p){
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 
  //     Complexit� : l / O(n)

  // Version r�cursive
  assert(l>0);

  if( l < 2 ) { // si l est inf�rieur � 2 alors on cr�e une liste compos� de l est la liste NULL
    
    return creerLSC(p, NULL);
  }

  else { // sinon on rajoute un �l�ment a la liste
    
    return creerLSC(p, consListeIntervalle3( l-1, p+1 ));
  
  }
}

void transfListeIntervalle(ListeSC L){
  // Donn�e : L est une liste tri�e non vide  
  // Res : modifie L en y inserant des �l�ments de sorte qu'elle soit une Liste Intervalle

  assert((L!=NULL));
  assert(estTrieeLSC(L));

  // A COMPLETER
  ListeSC P = L;
  if( estListeIntervalle(P) ){ // si la liste est d�j� une intervalle on affiche un message et on sort de la fonction
    cout << "Vous avez rentre une intervalle ! Recommencer en enlevant quelques chiffres et laisser la magie vous surprendre" << endl;
    exit(0);
  }

  // BROUILLON :
  // 1 4 5 6 8
  // ( 1+1 ) != 4 => 1 2 4 5 6 8
  // ( 2+1 ) != 4 => 1 2 3 4 5 6 8...
  while(P->succ != NULL){ // Tant que le sucesseur n'est pas NULL

    // Si l'�l�ment point� + 1 n'est pas �gal � la valeur de l'�lement suivant alors
    //    On l'ins�reApr�s la liste L, la nouvelle valeur a ajout�s
    if( ! (P->info+1 == (P->succ)->info) ){ 
      insererApresLSC(L, P, P->info+1);
    }
    P = P->succ;
  }
}

ListeSC intersectionListesIntervalles(ListeSC l1, ListeSC l2){
  // Donn�e : l1 et l2 2 listes intervalles
  // Res : Renvoie l'intersection de l1 et l2; les �l�ments de la liste r�sultat sont recopi�s
  // Complexit� : O(n^2)
  assert(estListeIntervalle(l1));
  assert(estListeIntervalle(l2));

  // A COMPLETER
  if ( l1 == NULL ) { cout << "l1 est NULL" << endl; return l1; } // si l1 est NULL alors on renvoie l1
  if ( l2 == NULL ) { cout << "l2 est NULL" << endl; return l2; } // si l2 est NULL alors on renvoie l2

  ListeSC P1, P2, RES;
  RES = NULL;

  // on regarde qu'elle liste possede le plus petit �l�ments en d�but de liste
  if(l1->info <= l2->info){ P1 = l1; P2 = l2; } // si c'est L1, alors P1 = L1 et P2 = L2
  else{ P1 = l2; P2 = l1; } // sinon c'est l'inverse, P1 = L2 et P2 = L1

  while(P1 != NULL && P2 != NULL){ // tant que l'une des deux liste n'est pas NULL

    if(P1->info == P2->info){ // on compare les �l�ments de chaques listes, si il sont �gaux
      insererFinLSC(RES, P1->info); // on ins�re P1->info a la fin de la liste RES
      P2 = P2->succ; // et on prend la queue de la liste P2
    }

    P1 = P1->succ; // on test a chaque fois avec la queue de la liste
  }
  return RES  ;
}
  
void plusLgSsLiInterv(ListeSC &L){
  // Donn�e : L liste
  // Res : L est modifiee, elle est la lus longue sous-liste intervalle de la liste en entr�e
  // A COMPLETER
  if ( L == NULL ) { cout << "l1 est NULL" << endl; exit(0); } // si l1 est NULL alors on renvoie l1

  // while( L->succ != NULL ){

  //   if( ! (L->info+1 == (L->succ)->info) ) // si l'�lement + 1 n'est pas �gal a l'�l�ment suivant on le supprime
  //   {

  //     supprimerLSC(L, L->info);
  //     afficherLSC(L);

  //   }
  // }

}





