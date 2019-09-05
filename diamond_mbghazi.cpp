//Muhammad Ghazi
//February 6, 2017
/*Inputs a value and prints stars.*/

#include <iostream>
using namespace std;

int main()
{
	int s, j, n, x;
	cout << "Enter a real number value: ";		//Prompt
	cin >> n;

	for (int i = 0; i < n; i++)							//Top half of diamond
	{
		for (int s = 0; s < n - 1 - i; s++)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	x = 1;



	for (int i = 1; i <= (n - 1); i++)				//Bottom half of diamond
	{
		for (s = 1; s <= x; s++)
			cout << " ";
		x++;
		for (j = 1; j <= (n - i); j++)
			cout << "*" << " ";
		cout << endl;
	}

	return 0;
}
	