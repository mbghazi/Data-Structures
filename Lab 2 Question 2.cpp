//Muhammad Ghazi
//Lab 2, Question 2

#include <iostream>
using namespace std;
int main()
{
	int main[5][5];
	int sum[5];
	int average[5];
	int counter = 0;

	for (int x = 0; x < 5; x++)
		for (int y = 0; y < 5; y++)
		{
			main[x][y] = 10 + rand() % 91;
		}
	for (int a = 0; a < 5; a++)
	{
		int total = 0;

		for (int b = 0; b < 5; b++)
		{
			total += main[b][a];

			if (main[b][a] % 2 == 0)
			{
				counter++;
			}
		}
		sum[a] = total;
		average[a] = total/5;
	}
	cout << "The outputs of the S (sum) array are: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "S[" << i << "] = " << sum[i] << endl;
	}
	cout << "The outputs of the A (average) array are: " << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << "S[" << j << "] = " << average[j] << endl;
	}
	cout << "The total number of even numbers are: " << counter << endl;
	return 0;
}