#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int A[8] = {1,2};
	int *B = new int[8];
	int a=8;

	int temp;
	cout << "(1/2) : ";
	cin >> temp;
	switch(temp){
		case 1:
			B=A;
			for (int i = 0; i < 8; i++){
				cout << "B[i] = " << B[i] << endl;
			}
		case 2:
			B[0] = 1;
			B[1] = 2;
			a=*B;
			cout << "a = " << a << " | adresse = " << &a << endl;
			cout << "B = " << *B << endl;
	}

	return 0;
}