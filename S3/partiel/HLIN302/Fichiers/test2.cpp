#include <iostream>
using namespace std;

class Truc
{
public:
	Truc() {}
};

template <typename T> 
T bidon(const T& a){ cout << "bidon 1 = "; return a; }

template <>
double bidon<double> (const double &a) { cout << "bidon 2 = "; return a; }

int main(int argc, char const *argv[])
{
	int x=3; double y = 3;
	cout << bidon(x) << endl;
	cout << bidon(y) << endl;
	cout << bidon(3.) << endl;
	//cout << bidon(Truc()) << endl;
	bidon(Truc()); cout << endl;
	return 0;
}