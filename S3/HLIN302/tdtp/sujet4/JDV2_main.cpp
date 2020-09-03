#include <iostream>
#include "JDV2.h"
using namespace std;

int main(int argc, char *argv[])
{	
	int n = 100;
	JeuDeLaVie JDV;
	if (JDV.parseOptions(argc,argv) ){
		JDV.run(n);
		cout<< "Fin du programme après " << n << " étapes" <<endl;
	}

	return 0;
}