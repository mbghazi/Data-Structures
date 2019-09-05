//Muhammad Ghazi
//HW1 Question 1

#include <iostream>

using namespace std;

//The recursion function is here
int recursion(int a, int b)
{
	if (b < 3)
	{
		cout << "Instance of recursion: " << b << endl << endl;
		b++;
		return recursion(a, b);
	}
	else if (b <= a)
	{
		int c = (b - 1) + (b - 2) + (b - 3);

		cout << "For the " << b << " recursion, the number the function produces is: " << c << endl << endl;

		b++;

		return recursion(a, b);
	}
	else
	{

		return 0;
	}

	
}



int main()
{

	//Iteration function is here
	int iteration;
	cout << "Enter in a number greater than 2" << endl;
	cin >> iteration;



	for (int i = 0; i <= iteration; i++)
	{
		int value = 0;
		//cout << "Instance of iteration: " << i << endl;
		if (i > 2)
		{
			value = (i - 1) + (i - 2) + (i - 3);

			cout << "For the " << i << " iteration, the number the function produces is: " << value << endl << endl;
		}
		else if (iteration < 2)
		{
			cout << "Oops, you entered a number less than 3..." << endl;
			continue;
		}

	}

	cout << "Now we have seen the iteration function, next is the recursion function" << endl;

	int counter = 0;


	recursion(iteration, counter);


	system("pause");





	return 0;
}