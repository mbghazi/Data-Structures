#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{

	Vector<int> v1;
	int i;	//used for iterating throughout the index

	for (i = 0; i < 5; i++)
	{

		v1.append(i);
		cout << v1.operator[](2) << endl;;
		int temp = 0;
		//v1.insertAt();

	}
	v1.remove(2);

	// Tests for append function by inserting random numbers
	for (i = 0; i < 5; i++)
	{
		v1.append(i);
		cout << v1.operator[](2) << endl;;

	}

	v1.clear();


	cout << v1.operator[](2) << endl;;


	system("pause");
	return 0;
}