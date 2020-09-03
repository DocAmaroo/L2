//============================================================================
// Name        : TP2.cpp
// Author      : Canta Thomas
// Version     : /
// Copyright   : Your copyright notice
// Description : cpp file
//============================================================================

#include <iostream>
#include <cmath>
#include <stdlib.h>     /* atoi */

#include "fonctionsMysterieuses.h"

int apuissanceb(int a, int b) {
// renvoie a puissance b
  if (b==0) return 1;
  if (b % 2 == 0) return apuissanceb(a * a, b / 2);
  return a * apuissanceb(a,b-1);}

//Question 2
int Incrementer(int n,bool T[]){
  int cpt=0;
  for(int i=n-1;i>=0;i--){
    cpt++;
    if(T[i]){
      T[i]=0;
    }
    else{
      T[i]=1;
    break;
    }
  }
  return cpt;
}

int Compte(int n){
	int T[n];
	for(int i=0; i<n; i++){
		T[i] = pow(2,i)-1;
		std::cout<<T[i]<<'-';
	}
	std::cout<<std::endl;
}

int main(int argv, char** argc){
 	int numeroFonction = atoi(argc[1]), n =  atoi(argc[2]), v;
	
	switch (numeroFonction) {
    	case 1 : v=f1(n); break;//  sqrt(n) * 3 , racine(n)*3
    	case 2 : v=f2(n); break;// n^(5)* 1/10
    	case 3 : v=f3(n); break;// n^(2) * 1/2
    	case 4 : v=f4(n); break;// log(n)* 2
    	case 5 : v=f5(n); break;// 2^(n) * 10
    	case 6 : v=f6(n); break;// 3^(n) * 20
  	}
  	std::cout<<"f"<<numeroFonction<<"("<<n<<") renvoie "<<v<<"\n";

  	//Question 2
  	bool T[4]={false,true,true,true};
  	std::cout<<"Nombre d'incrémentation = "<<Incrementer(4,T)<<std::endl;
  	for(int i=0;i<4;i++){
    	std::cout<<T[i];
	}
	std::cout<<std::endl;
  
	Compte(5);
  	return 0;
}

/*
ordre de compilation :  g++ SolutionsFonctionMysterieuses.cpp fonctionsMysterieuses.o -o test
Ordre d'exécution :  ./test 1 2
*/