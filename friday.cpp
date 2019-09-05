//Muhammad Ghazi
//02-20-2015
//Chapter 3
//Program reads in a decimal number and takes the square root and raises number to power of 12 and prints

//Library Files
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double number, solution1, solution2;

	//Initial prompt
	cout << "Enter in any number" << endl;
	cin >> number;

	//Do calcualtions
	solution1 = sqrt(number);
	solution2 = pow(number, 12.0);

	//Print Results
	cout << fixed << showpoint << setprecision(3);
	cout << "Square Root = " << solution1 << endl;
	cout << "Number to Power of 12 = " << solution2 << endl;

	return 0;

}
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int b = 7;
	int a = 2;
	int y = 4;
	float z = 4.4;



	cout << a / float(y) << endl;


	cout << pow(10, 6) << endl;

	cout << y + b%a*a << endl;

	cout << y + b % (a*a) << endl;

	cout << int(z + 1.5) << endl;

	cout << float(a*y - a) << endl;
