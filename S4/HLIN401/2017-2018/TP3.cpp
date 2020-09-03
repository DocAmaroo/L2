//============================================================================
// Name        : TP3.cpp
// Author      : Canta Thomas
// Version     : /
// Copyright   : Your copyright notice
// Description : cpp file
//============================================================================

#include <iostream>
#include <cstdlib>


/************************
Generaux
****************************/
int max(int a, int b) {if (a > b) return a; return b;}

int min(int a, int b) {if (a < b) return a; return b;}

int moitieSuperieure(int n){
  if (n % 2 == 0) return n / 2; return (n+1) / 2;}

void imprimer(int n, int T[]){
  for (int i=0; i<n; i++) std::cout<<T[i]<<" ";std::cout<<std::endl;}

void genererInverse(int n, int T[]){
  for  (int i=0; i<n; i++) T[i]=n-i;
}


void genererRandom(int n, int Max, int T[]){//rempli le tableau T de n nombres aléatoires, tous entre 0 et Max
  for  (int i=0; i<n; i++) T[i]=rand() % (Max + 1);
}


void echanger(int T[], int i, int j){
  int temp=T[i]; T[i]=T[j]; T[j]=temp;
}

//tri panier
void triPanier(int T[], int n){
  int Min=T[0];
  int Max=T[0];
  for(int i=1;i<n;i++){
    Max=max(Max,T[i]);
    Min=min(Min,T[i]);
  }
  int *Tbis= new int[Max-Min+1];
  for(int i=0;i<Max-Min+1;i++)
    Tbis[i]=0;
  for(int i=0;i<n;i++)
    Tbis[T[i]-Min]+=1;
  int k=0;
  for(int i=0;i<Max-Min+1;i++){
    for(int j=0;j<Tbis[i];j++){
      T[k]=Min+i;
      k++;}}}

//tri rapide
int partition(int tableau[], int deb, int fin)
{
  int compt=deb;
  int pivot=tableau[deb];
  int i;

  for(i=deb+1;i<=fin;i++)
    {
      if(tableau[i]<pivot)
	{
	  compt++;
	  echanger(tableau,compt,i);
	}
    }
  echanger(tableau,compt,deb);
    return(compt);
}

  
void triRapide(int tableau[],int debut,int fin)
    {
    if(debut<fin)
        {
        int pivot=partition(tableau,debut,fin);
        triRapide(tableau,debut,pivot-1);
        triRapide(tableau,pivot+1,fin);
        }
    }

//tri fusion
void fusion(int deb, int fin, int T[]){
  bool x;
  int mid=(deb+fin)/2;
  int j=0;
  int i=mid+1;
  while(i<=fin){
    j=0;
    x=true;
    while(j<i && x){
      if(T[i-j-1]>T[i-j])
	echanger(T,i-j-1,i-j);
      else
	x=false;
      j++;}
    i++;}}

void triFusion(int deb, int fin, int T[]){
  if(deb<fin){
    int mil=(deb+fin)/2;
    if(mil>deb)
      triFusion(deb,mil,T);
    if(mil+1<fin)
      triFusion(mil+1,fin,T);
    fusion(deb,fin,T);}}

//tri bulle
void triBulle(int n,int T[]){
  for(int i=0;i<n;i++){
    for(int j=n-1;j>i;j--){
      if(T[j]<T[j-1])
	echanger(T,j,j-1);}}}


int main(){
  
  int T[15];
  genererRandom(15,20,T);
  imprimer(15,T);
  //triBulle(15,T);
  //triRapide(T,0,14);
  //triPanier(T,15);
  //triFusion(0,14,T);
  imprimer(15,T);

  return 0;
}

//compile : g++ -Wall TrisOutilsSimples.cpp -o tp3
//execute : ./tp3