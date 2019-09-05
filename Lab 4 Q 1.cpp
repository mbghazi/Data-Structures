//Liam Salazar, P21439665 (Navigator)
//Muhammad Ghazi, P(ID) (Driver)
//April 4, 2017
/*Program uses struct. Main program will generate
ID's and a score for 20 students. A function will be called
to determine the letter grade with the score. Lastly, it
will count each grade.*/

#include <iostream>
#define length 20
using namespace std;

char letter(double &score);

struct Student
{
	int id;
	double score;
	char grade;
};

int countA = 0;
int countB = 0;
int countC = 0;
int countD = 0;
int countF = 0;

int main()
{
	Student P[length];

	//This for loop will generate the students and give them ID #'s, scores, and a letter grade.
	for (int i = 0; i < length; i++)
	{
		P[i].id = 1 + i;				//Originally P[i].id= 1 + rand() % 20, changed because other group notified me of the correct way
		P[i].score = 10 + rand() % 90;

		cout << "P" << P[i].id << endl;
		cout << "Score: " << P[i].score << endl;

		cout << "Grade: " << letter(P[i].score) << endl;

		cout << endl;
	}

	cout << "(A) Execellent grades: " << countA << endl;		//Counts A's
	cout << "(B) Above average: " << countB << endl;		//Counts B's
	cout << "(C) Average: " << countC << endl;		//Counts C's
	cout << "(D) Below Average: " << countD << endl;		//Counts D's
	cout << "(F) Failing: " << countF << endl << endl;

	return 0;
}

char letter(double &score)
{
	if (score >= 90)
	{
		countA++; return 'A';
	}
	else if (score >= 80)
	{
		countB++; return 'B';
	}
	else if (score >= 70)
	{
		countC++; return 'C';
	}
	else if (score >= 60)
	{
		countD++; return 'D';
	}
	else
	{
		countF++; return 'F';
	}
}