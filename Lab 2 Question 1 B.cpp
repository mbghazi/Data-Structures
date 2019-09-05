//Muhammad Ghazi
//Lab 2 Question 1 B

#include <iostream>
#define length 20
using namespace std;

void bubble(int a[], int size);

int main()
{
	int a[length];
	for (int i = 0; i < length; i++)
	{
		a[i] = rand() % 100;
	}
	cout << "The array before sorting is : " << endl;
	for (int x = 0; x < length; x++)
	{
		cout << a[x] << endl;
	}
	cout << endl << endl;

	bubble(a, length);

	cout << "The array after sorting is : " << endl;
	for (int x = 0; x < length; x++)
	{
		cout << a[x] << endl;
	}

	return 0;
}
void bubble(int a[], int size)
{
	for (int i = 0; i < length; i++)
	{
		if (a[i] > a[i + 1])
		{
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
}