#include <iostream>
#include <vector>
#include "myvector.h"
#include "print-vector.h"
#include "cellule.h"
#include "triBulle.h"
#include "triRapide.h"
#include "recherche-dicho.h"
#include "triTas.h"
#include <algorithm>
using namespace std;

#define MAX 100

bool compare(int a,int b){return a>b;}

int main(int argc,char ** argv){
	if (argc !=2) {cerr<<"Usage: "<<argv[0]<<" [tab dim]"<<endl; return 1;}
	srand(123);
	std::vector<int> T(atoi(argv[1]));
	for(size_t i=0;i<T.size();++i)
		T.at(i)=rand() % MAX;
	write(cout,T);
	std::sort(T.begin(),T.end()); // tri selon l’ordre croissant (appel à <)
	write(cout,T);
	std::sort(T.begin(),T.end(),compare); // tri selon la fonction compare (ici > )
	write(cout,T);
	return 0;
}