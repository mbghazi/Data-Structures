//Muhammad Ghazi
//Lab 2 Question 1 C
#include <iostream>
#define length 20
using namespace std;
void sort(int A[], int size);

int main()
{
	int n;
	int A[length];
	int mid, left, right;
	left = 0;
	right = length - 1;
	cout << "Enter a number." << endl;
	cin >> n;

	cout << "Array before sorting: " << endl;
	for (int i = 0; i < length; i++)
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl << endl << endl;

	sort(A, length);
	cout << "Array after sorting: " << endl;
	for (int i = 0; i < length; i++)
	{

		cout << A[i] << " ";
	}
	cout << endl;
	cout << "************************" << endl << endl;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == n)
		{
			cout << "The number was found at position " << (mid + 1) << endl;
			break;
		}
		else if (A[mid] > n)
		{

			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		if (left > right)
		{
			cout << "Number wasnt found." << endl;
			break;
		}
	}
	return 0;
}

void sort(int A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (A[i] > A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}
