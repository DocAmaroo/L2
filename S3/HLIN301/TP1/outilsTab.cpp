#include <iostream>
#include <fstream>

#include <stdlib.h>  // pour rand
#include <assert.h>
#include "outilsTab.h"
using namespace std;

int* genTab(int n){
    int* t; int i;
    t=new int[n];
    for (i=0;i<n;i++) t[i]=-100+rand()%200;
        return t;
}

int* genTabNotes(int n){
    int* t; int i;
    t=new int[n];
    for (i=0;i<n;i++) t[i]=rand()%21;
        return t;
}

void afficheTab(int* T, int taille){
    int i;
    cout << "\n[ ";
    for (i=0;i<taille;i++) cout << T[i] << " ";
        cout << "]\n";
}

void fichierTemps(const char* nomFic, int tMaxTab, int pas, int (*f)(int*, int)){
    int taille;
    int* Tab;
    clock_t t1, t2;    
    ofstream fichier(nomFic,ios::out);

    if (fichier)
    {
        for (taille=pas; taille<=tMaxTab; taille=taille+pas){
            Tab=genTab(taille);
            t1=clock();
            (*f)(Tab,taille);
            t2=clock();
            fichier << taille <<" "<< (double)(t2-t1)/ CLOCKS_PER_SEC << endl;
        }
        fichier.close();
    }
    else cerr << " Problème ouverture fichier"<< endl;

    return ;
}

int ssTabSomMax1(int* T, int taille){ /* O(n^3) */
int somMax, som, i, j, k;
somMax=0;
for (i=0;i<taille;i++){
    for (j=i; j<taille; j++){
        som=0;
        for (k=i; k<=j; k++) {
            som = som + T[k];
        }
        if (som > somMax) somMax = som;
    }
}
return somMax;
}

int ssTabSomMax2(int* T, int taille){ /* O(n^2) */
int somMax, som, i, j;
somMax=0;
for (i=0;i<taille;i++){
    som=0;
    for (j=i; j<taille; j++){
        som = som + T[j];
        if (som > somMax) somMax = som;
    }
}
return somMax;
}

int sTSM3(int* T,int g,int d){ /* O(nlog(n)) */
int m, som, i, smgd, smdg, smm, smg, smd;
assert(g<=d);
if (g==d){
    if (T[g]>0) return T[g]; else return 0;
}
else {
    m = (d+g)/2;
    smg=sTSM3(T,g,m);
    smd=sTSM3(T,m+1,d);
    smgd=0; som=0;
    for (i=m;i>=g;i--){
        som=som+T[i];
        if (som > smgd) smgd=som;
    }
    smdg=0; som=0;
    for(i=m+1;i<=d;i++){
        som=som+T[i];
        if (som>smdg) smdg=som;
    }
    smm=smgd+smdg;
    if ((smg>=smd) && (smg>=smm)) return smg;
    else {
        if (smd>=smm) return smd;
        else return smm;
    }
}
}

int ssTabSomMax3(int* T, int taille){
    return sTSM3(T,0,taille-1);
}


int ssTabSomMax4(int* T, int taille){ /* O(n) */
    /* A COMPLETER */
int sm, smd;
sm=0; smd=-1;
for (int i=0; i<taille; i++){
    smd=max(smd+T[i],T[i]);
    sm=max(smd,sm);
}
return sm;
}

/* b A COMPLETER
   Quel est le temps approximatif (à 0.1 sec près) d'exécution de ssTabSomMax4
   pour un tableau de 10 millions d'éléments ?
   Réponse : ~0.1s (=0.0825)
 */

struct triplet indSsTabSomMax(int* T, int taille){
/* A COMPLETER */
    struct triplet res;
    res.somMax=0; res.deb=0; res.fin=0;

    int deb=0;
    int fin=taille;
    int som=0;
    int j=fin;

    for(int i=deb; i < j; i++){ //calcule la somme du tableau entre deb et fin
        som = T[i]; // on initialise la som a T[i]
        if( deb == fin){ // si deb == fin;
            res.somMax = som; 
            res.deb = deb;
            res.fin = deb;
        }
        while( j > i){ // tant que j > i;
            som += T[j]; // on addition chaque élement du tableau
            j--;
        }
        printf("som %d\n",som );
        if (som > res.somMax){
            res.somMax = som;
            res.deb = deb;
            res.fin = fin;
            deb++;
            fin--;
            printf("fin du if : res.somMax = %d | res.deb = %d & res.fin = %d\n",res.somMax,res.deb,res.fin );
        }
        printf("deb = %d\n fin=%d\n",deb,fin );
        deb++;
        fin--;
    }

    return res;
}


void rangerNotes(int* T,int taille){
/* A COMPLETER */
 return;

}
