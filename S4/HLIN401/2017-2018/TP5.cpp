//============================================================================
// Name        : TP5.cpp
// Author      : Canta Thomas
// Version     : /
// Copyright   : Your copyright notice
// Description : cpp file
//============================================================================

#include "Arbo.h"

/******* Liste doublement chainee Début *******/

Cellule::Cellule (ContCellule A){
  fils=A;
  Apres=NULL;
}


ListeCellules Cellule::EstDansListeP(ContCellule A){
  if (fils==A) return this;
  if (Apres==NULL) return NULL;
  return Apres->EstDansListeP(A);
}



ListeCellules Cellule::AjouterSuccesseur(ContCellule A){
  if (!EstDansListeP(A)) {
    ListeCellules ptCell=new Cellule(A);
    ptCell->Apres=this;
    return ptCell;
  }
  
  return this;
}



ListeCellules Cellule::RetirerSuccesseur(ContCellule A){
  if (fils==A)
    return Apres;
  
  if (!Apres)
    return this;
  
  Apres=Apres->RetirerSuccesseur(A);

  return this;
}


/******* Liste doublement chainee Fin *******/

/************Arborescence Debut*************/


Sommet::Sommet(Valeur v){
  racine=v;
  ListeSuccesseurs=NULL;
}




ListeCellules Sommet::EstSuccesseurP(Arbo A){
  if (ListeSuccesseurs) return ListeSuccesseurs->EstDansListeP(A); 
  return NULL;
}



void Sommet::AjouterSuccesseur(Arbo A){
  if (!ListeSuccesseurs){
    ListeSuccesseurs=new Cellule(A);
    return;
  }
  if (! ListeSuccesseurs->EstDansListeP(A)) {
    ListeSuccesseurs= ListeSuccesseurs->AjouterSuccesseur(A);
  }
  return;
}



void Sommet::RetirerSuccesseur(Arbo A){
  if (ListeSuccesseurs &&  ListeSuccesseurs->EstDansListeP(A)) {
    ListeSuccesseurs= ListeSuccesseurs->RetirerSuccesseur(A);
  }
  return;
}

ostream& operator<<(ostream& os, Sommet& S){
  os<<S.racine<<" ";
  return os;
}

/************Arborescence Fin*************/

/************Traversee recursive Debut*************/

void TraverseePrefixeRec(Arbo A){
  if (!A) {
    cout<<endl;
    return;
  }
  
  cout<< *A<<" ";

  for (ListeCellules L=A->ListeSuccesseurs; L!=NULL;L=L->Apres){

    TraverseePrefixeRec(L->fils);

  }

  return;
}

/************Traversee recursive Fin*************/

/**********Pile Début*********/

Pile::Pile(){
  Sommet=NULL;
}


bool Pile::VideP(){
  return Sommet==NULL;
}


void Pile::Empiler(ContCellule A){
  Cellule* ptCellule=new Cellule(A);
  ptCellule->Apres=Sommet;
  Sommet=ptCellule;
  return;
}


ContCellule Pile::Depiler(){
  Cellule* ptCellule=Sommet;
  Sommet=Sommet->Apres;
  return ptCellule->fils;
}

/**********Pile Fin*********/

/************Traversee  prefixe iterative Debut*************/

void TraverseePrefixeIt(Arbo A){
  Pile* P=new Pile;
  Pile* temp_P = new Pile;

  P->Empiler(A);
  
  while ( !P->VideP()){
    
    Arbo temp_A = P->Depiler();
    cout<< *temp_A <<" ";

    for (ListeCellules L=temp_A->ListeSuccesseurs; L!=NULL;L=L->Apres){
      temp_P->Empiler(L->fils);

    }

    while( !temp_P->VideP()){

      P->Empiler(temp_P->Depiler());

    }
  }
}

/************Traversee  prefixe iterative Fin*************/


/**********File Début*********/

File::File(){
  Sortie=NULL; Entree=NULL;
}


bool File::VideP(){
  return Sortie==NULL;
}


void File::Enfiler(ContCellule A){
  Cellule* ptCellule=new Cellule(A);
  if (Entree) Entree->Apres=ptCellule;
  Entree=ptCellule;
  if (! Sortie) Sortie=ptCellule;
  return;
}


ContCellule File::Defiler(){
  Cellule* ptCellule=Sortie;
  Sortie=Sortie->Apres;
  return ptCellule->fils;
}

/**********File Fin*********/

/************Traversee Largeur Debut*************/

void TraverseeLargeur(Arbo A){
  
}

/************Traversee Largeur Fin*************/


int main(){

  /* Arboresence A0 */
  Arbo A0 = new Sommet(0);
  Arbo A1 = new Sommet(1);
  Arbo A2 = new Sommet(2);
  Arbo A3 = new Sommet(3);
  Arbo A4 = new Sommet(4);
  Arbo A5 = new Sommet(5);
  Arbo A6 = new Sommet(6);

  A3->AjouterSuccesseur(A6);
  A1->AjouterSuccesseur(A5);
  A3->AjouterSuccesseur(A4);
  A2->AjouterSuccesseur(A3);
  A0->AjouterSuccesseur(A2);
  A0->AjouterSuccesseur(A1);

    /*
  Représentation de l'arborescence binaire
  
                  A0
		 /  \
		A1  A2
	        |    |
		A5   A3
		    /  \
		   A4  A6 

  */
  
  /* Arborescence A11 */
  
  Arbo A11 = new Sommet(11);
  Arbo A21 = new Sommet(21);
  Arbo A31 = new Sommet(31);
  Arbo A32 = new Sommet(32);
  Arbo A33 = new Sommet(33);
  Arbo A34 = new Sommet(34);
  Arbo A41 = new Sommet(41);
  Arbo A42 = new Sommet(42);

  A32->AjouterSuccesseur(A42);
  A32->AjouterSuccesseur(A41);
  A21->AjouterSuccesseur(A31);
  A21->AjouterSuccesseur(A32);
  A21->AjouterSuccesseur(A33);
  A21->AjouterSuccesseur(A34);
  A11->AjouterSuccesseur(A21);


  cout<<" rec A0  ";
  TraverseePrefixeRec(A0);
  cout<< endl;
  cout<<" iter A0  ";
  TraverseePrefixeIt(A0);
  cout<< endl;
  cout<<" largeur  ";
  TraverseeLargeur(A0);
  cout<< endl;


  A3->RetirerSuccesseur(A4);
  A3->RetirerSuccesseur(A6);

  cout<<"rec A0  apres retrait   ";
  TraverseePrefixeRec(A0);
  cout<< endl;
  cout<<" iter A0  ";
  TraverseePrefixeIt(A0);
  cout<< endl;

  return 1;
}

// compile : g++ -Wall Arbo.cpp -o tp5
// execute : ./tp5