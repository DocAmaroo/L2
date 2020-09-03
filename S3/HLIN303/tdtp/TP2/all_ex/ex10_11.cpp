#include <iostream>

using namespace std;

void string_to_integer()
{
	string numero = "";
	float numero_2 = 0;
	cout << "\nDonner un chiffre quelconque (float autorisé) : ";
	cin >> numero;
	cout << "\nNous venons de la transformer en temps qu'entier..." << endl;
	cout << "Du coup faisons une addition\n" << endl;
	cout << "\nAvec quoi voulez vous l'additionner ? ";
	cin >> numero_2;
	cout << "(" <<stof(numero) << " + " << numero_2 << ")" << " = " << stof(numero) + numero_2 << "\n" << endl;
}

void integer_to_string()
{
	int numero = 0;
	string numero_2 = "";
	cout << "\nDonner une chaine de charactère quelconque : ";
	cin >> numero;
	cout << "\nNous venons de la transformer en temps qu'entier" << endl;
	cout << "Du coup faisons une concaténation\n";
	cout << "\nAvec quoi voulez vous le concaténer ? ";
	cin >> numero_2;
	cout << "(" <<to_string(numero) << " + " << numero_2 << ")" << " = " << to_string(numero) + numero_2 << "\n" << endl;
}

int main(int argc, char const *argv[])
{
	int mode = 0;

	do{
		cout << "\nmode 1 => string to integer" << endl;
		cout << "mode 2 => integer to string\n" << endl;
		cout << "What do you want to do my brudda ? ";
		cin >> mode;

		if (mode == 1)
		{
			string_to_integer();
		}
		else
			if (mode == 2)
			{
				integer_to_string();
			}
		else
		{
			cout <<"error : choice different of 1 or 2" << endl;
		}
	}while(!(mode == 1 || mode == 2));

	return 0;
}