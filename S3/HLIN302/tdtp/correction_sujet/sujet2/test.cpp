#include <iostream>
#include <string>
using namespace std;

std::string setVivante(bool etat) {
	string couleur;
	int age = 0;
	if (etat) {
		couleur = age++ ? "VERT" : "BLEU";
	} 
	else {
		age = 0;
		couleur = "NOIR";
	}
	return couleur;
}

int main(int argc, char const *argv[])
{
	cout << "couleur = " << setVivante(1) << endl;
	return 0;
}

// compile : g++ -Wall test.cpp -o test