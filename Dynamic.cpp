#include "Obj.h"
#include <iostream>
using namespace std;

int main()
{
	int n;

	//Prompt for value n
	cout << "Input value for n variable:" << endl;
	cin >> n;

	cout << endl;

	alpha Theta(n);	//Theta is under class alpha

	//Output
	cout << endl << "Prime Numbers in the array: " << endl;
	cout << Theta.prime_count(n) << endl;



	return 0;
}