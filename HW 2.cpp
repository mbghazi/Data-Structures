//muhammad ghazi

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
//#include <conio.h>


using namespace std;

struct poly 
{
	int coefficient;
	int power;
	poly *next;
};

class add2poly
{
	poly *polynomial1, *polynomial2, *polynomial3;
public:
	add2poly()
	{
		polynomial1 = polynomial2 = polynomial3 = NULL;
	}
	void add();
	void dply();
};

void add2poly::add() 
{
	int i, a;
	poly *newl = NULL, *end = NULL;
	cout << "Enter highest power for polynomial expression\n";
	cin >> a;

	cout << "\n1st Polynomial expression\n";
	for (i = a; i >= 0; i--)
	{
		newl = new poly;
		newl->power = a;
		cout << "Enter Co-efficient number" << i << ":: ";
		cin >> newl->coefficient;
		newl->next = NULL;
		if (polynomial1 == NULL)
			polynomial1 = newl;
		else
			end->next = newl;
		end = newl;
	}


	cout << "\n\n2nd Polynomial expression\n";
	end = NULL;
	for (i = a; i >= 0; i--)
	{
		newl = new poly;
		newl->power = a;
		cout << "Enter Co-efficient number" << i << ":: ";
		cin >> newl->coefficient;
		newl->next = NULL;
		if (polynomial2 == NULL)
			polynomial2 = newl;
		else
			end->next = newl;
		end = newl;
	}


	poly *p1 = polynomial1, *p2 = polynomial2;
	end = NULL;
	while (p1 != NULL && p2 != NULL) {
		if (p1->power == p2->power) {
			newl = new poly;
			newl->power = a--;
			newl->coefficient = p1->coefficient + p2->coefficient;
			newl->next = NULL;
			if (polynomial3 == NULL)
				polynomial3 = newl;
			else
				end->next = newl;
			end = newl;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
}

void add2poly::dply() {
	poly *t = polynomial3;
	cout << "\n\nAnswer is : ";
	while (t != NULL) {
		cout.setf(ios::showpos);
		cout << t->coefficient;
		cout.unsetf(ios::showpos);
		cout << "X" << t->power;
		t = t->next;
	}
}


void main() 
{
	ifstream file1;
	file1.open("q.txt");
	add2poly obj;
	obj.add();
	obj.dply();
	ofstream file2;
	file2.open("ans.txt");
	file2 << "test";
	file2.close();

	system("pause");
}