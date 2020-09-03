#include "TP4.h"

static int npivot = 0;

enum pivot { FIXE, ALEATOIRE };

int choixPivot(int n, int T[], pivot P) 
{
  npivot++;
  switch (P)
  {
    case FIXE:
      return 0;
      break;
    case ALEATOIRE:
      return rand()%n;
      break;
  }
}

int rang(int k, int n, int T[], pivot P){
  if (n==1) return T[0];
  int p = choixPivot(n, T, P);
  int ninf = 0, neq = 0;
  int r; // résultat renvoyé
  
  for(int i = 0; i < n; i++){
    if( T[i] < T[p] ){
      ninf++;
    }
    if( T[i] == T[p] ) {
      neq++;
    }
  }

  if (ninf >= k) {
    int* Tinf = (int*) malloc(ninf * sizeof(int));
    //Cas 1
    int iinf = 0;

    for(int i = 0; i < n; i++){
      if( T[i] < T[p] ){
        Tinf[iinf] = T[i];
        iinf++;
      }
    }
    r = rang(k, ninf, Tinf, P);
    
    free(Tinf);
    return r;
  }

  else{
    int* Tsup = (int*) malloc((n-ninf-neq) * sizeof(int));
    //Cas 3
    int isup = 0;

    for(int i = 0; i < n; i++){
      if( T[i] > T[p] ){
        Tsup[isup] = T[i];
        isup++;
      }
    }
    r = rang(k-ninf-neq, n-ninf-neq, Tsup, P);
    free(Tsup);
    return r;
  }
}

int main(int argc, char** argv)
{

  srand(time(NULL));
  int n = 0;
  //if (argc > 1) n = atoi(argv[1]);
  int* tab = RemplirTableau(n, argc, argv);  

  cout<<"Tableau de depart:"<<endl;
  AfficherTableau(n,tab);

  int k = 0;
  while(k<1 || k>n)
  {
    cout << "Rang à calculer (entre 1 et " << n << ") : ";
    cin >> k;
  }

  clock_t avant;
  clock_t apres;

  int r;
  
  cout << "Nombre de rang " << k << " :" << endl;
  cout << "  pivot fixe : ";
  npivot = 0; avant = clock(); r = rang(k, n, tab, FIXE); apres = clock();
  cout << r << " (nb pivots: " << npivot << ", temps: " << (double)(apres-avant)/CLOCKS_PER_SEC << "s)" << endl;

  cout << "  pivot aléatoire : ";
  npivot = 0; avant = clock(); r = rang(k, n, tab, ALEATOIRE); apres = clock();
  cout << r << " (nb pivots: " << npivot << ", temps: " << (double)(apres-avant)/CLOCKS_PER_SEC << "s)" << endl;

  free(tab);
}

