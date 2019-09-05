//Muhammad Ghazi
//Lab 2 Question 1 A
#include <iostream>
#define length 20                    
using namespace std;

void selection_sort(int a[], int size);

int main()
{
	int a[length];

	for (int i = 0; i < length; i++)
	{
		a[i] = rand() % 100;               
	}
	cout << "Array Before: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;                
	selection_sort(a, length);
	cout << "After: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}

void selection_sort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a[i]>a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

