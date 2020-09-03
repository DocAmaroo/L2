//============================================================================
// Name        : TP1.cpp
// Author      : Canta Thomas
// Version     : /
// Copyright   : Your copyright notice
// Description : cpp file
//============================================================================

#include <iostream>

using namespace std;

//f1
void f1(int n){
  int cpt=0;
  //on effectue une boucle dans O(n) qui consiste à afficher i
  for (int i=0;i<n;i++){cpt++;}
  cout<<cpt<<" opérations ont été effectuées dans l'algo f1"<<endl;
}


//f3
void f3(int n){
  //on effectue une boucle dans O(n³) qui consiste à afficher toutes les boucles de i,j,k
  int cpt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        cpt++;
      }
    }
  }
  cout<<cpt<<" opérations ont été effectuées dans l'algo f1"<<endl;
}


//g2
void g2(int n){
  //on effectue une boucle dans O(2^n)
  if(n>0){
    g2(n-1);
    g2(n-1);
  }
}


//g3
void g3(int n){
  //on effectue une boucle dans O(3^n)
  if(n>0){
    g3(n-1);
    g3(n-1);
    g3(n-1);
  }
}

//main
int main(){
  cout<<"On ressent une différence entre l'éxécution de f1(n) et f3(n) à partir de n=500"<<endl;
  cout<<"On exécute f1(500)"<<endl;
  f1(500);
  cout<<"On exécute f3(500)"<<endl;
  f3(500);

  cout<<"On ressent une différence entre l'éxécution de f3(n) et g2(n) à partir de n=28"<<endl;
  cout<<"On exécute f3(28)"<<endl;
  f3(28);
  cout<<"On exécute g2(28)"<<endl;
  g2(28);

  cout<<"On ressent une différence entre l'éxécution de g2(n) et g3(n) à partir de n=18"<<endl;
  cout<<"On exécute g2(18)"<<endl;
  g2(18);
  cout<<"On exécute g3(18)"<<endl;
  g3(18);


  cout<<"On ne ressent pas une différence entre l'éxécution de f3(n) et l'exécution succesive de f1(n) f3(n), car l'exécution de f1 par rapport a f3 est trop rapide pour marquer une différence suffisante"<<endl;
  cout<<"Exemple avec n=1000"<<endl;
  cout<<"On exécute f3(1000)"<<endl;
  f3(1000);
  cout<<"On exécute succesivement f1(1000) et f3(1000)"<<endl;
  f1(1000);
  f3(1000);

  cout<<"On ne ressent pas une différence entre l'éxécution de g2(n) et l'exécution succesive de f3(n) g2(n), car l'exécution de f3 par rapport a g2 est trop rapide pour marquer une différence suffisante"<<endl;
  cout<<"Exemple avec n=30"<<endl;
  cout<<"On exécute g2(30)"<<endl;
  g2(30);
  cout<<"On exécute succesivement f3(30) et g2(30)"<<endl;
  f3(30);
  g2(30);

  cout<<"On ne ressent pas une différence entre l'éxécution de g3(n) et l'exécution succesive de g2(n) g3(n), car l'exécution de g2 par rapport a g3 est trop rapide pour marquer une différence suffisante"<<endl;
  cout<<"Exemple avec n=20"<<endl;
  cout<<"On exécute g3(20)"<<endl;
  g3(20);
  cout<<"On exécute succesivement g2(20) et g3(20)"<<endl;
  g3(20);
  g2(20);

  return 0;
}
// g++ Q1.cpp -o R1