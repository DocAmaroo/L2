#include <iostream>
#include "JDV.h"
using namespace std;

int main(int argc, char const *argv[])
{	
	int n = 8;
	JeuDeLaVie JDV;
	if (argc != 2) {cerr << "usage " << argv[0] << " config_file" << endl; return 1;}

	JDV.init(argv[1]);
	JDV.run(n);

	cout<< "Fin après " << n << " étapes" <<endl;
	return 0;
}