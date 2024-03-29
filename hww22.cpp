// hww22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
// class polynomial
class polynomial
{
private:
	struct node
	{
		float coeff;
		int exp;
		node *link;
	}*p;
public:
	polynomial();
	void append(float c, int e);
	void display();
	void add(polynomial &l1, polynomial &l2);
	~polynomial();
};
//default constructor
polynomial::polynomial()
{
	p = NULL;
}
// function to add a polunomial
void polynomial::append(float c, int e)
{
	node *temp = p;
	if (temp == NULL)
	{
		temp = new node;
		p = temp;
	}
	else
	{
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = new node;
		temp = temp->link;
	}
	temp->coeff = c;
	temp->exp = e;
	temp->link = NULL;
}
//function to display polynomial
void polynomial::display()
{
	node *temp = p;
	int f = 0;

	cout << endl;
	while (temp != NULL)
	{
		if (f != 0)
		{
			if (temp->coeff > 0)
				cout << " + ";
			else
				cout << " ";
		}
	if (temp->exp != 0)
		cout << temp->coeff << "x^" << temp->exp;
	else
	cout << temp->coeff;
	temp = temp->link;
	f = 1;
	}
}
void polynomial::add(polynomial &l1, polynomial &l2)
{
	node *z = NULL;
	if (l1.p == NULL && l2.p == NULL)
		return;
	node *temp1, *temp2;
	temp1 = l1.p;
	temp2 = l2.p;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (p == NULL)
		{
			p = new node;
	z = p;
		}
		else
		{
			z->link = new node;
			z = z->link;
		}
	if (temp1->exp < temp2->exp)
	{
		z->coeff = temp2->coeff;
	z->exp = temp2->exp;
	temp2 = temp2->link;
	}
	else
	{
		if (temp1->exp > temp2->exp)
		{
			z->coeff = temp1->coeff;
		z->exp = temp1->exp;
		temp1 = temp1->link;
		}
		else
		{
			if (temp1->exp == temp2->exp)
			{
				z->coeff = temp1->coeff + temp2->coeff;
			z->exp = temp1->exp;
			temp1 = temp1->link;
			temp2 = temp2->link;
			}
		}
	}
	}
	while (temp1 != NULL)
	{
		if (p == NULL)
		{
			p = new node;
			z = p;
		}
		else
		{
			z->link = new node;
			z = z->link;
		}
		z->coeff = temp1->coeff;
		z->exp = temp1->exp;
		temp1 = temp1->link;
	}
	while (temp2 != NULL)
	{
		if (p == NULL)
		{
			p = new node;
	z = p;
		}
		else
		{
			z->link = new node;
			z = z->link;
		}
		z->coeff = temp2->coeff;
		z->exp = temp2->exp;
		temp2 = temp2->link;
	}
	z->link = NULL;
}
//destructor
polynomial :: ~polynomial()
{
	node *q;
	while (p != NULL)
	{
		q = p->link;
	delete p;
	p = q;
	}
}
int main()
{
	//enter details for first polynomial
	polynomial p1;
p1.append(14, 5);
p1.append(15, 4);
p1.append(17, 2);
p1.append(18, 1);
p1.append(19, 0);
//display first polynomial
cout << "\nFirst polynomial:";
p1.display();
//enter details for second polynomial
polynomial p2;
p2.append(15, 6);
p2.append(5, 5);
p2.append(-35, 4);
p2.append(45, 3);
p2.append(65, 1);
//display second polynomial
cout << "\nSecond polynomial:";
p2.display();
polynomial p3;
// add two polynomials and display it
p3.add(p1, p2);
cout << "\nResultant polynomial: ";
p3.display();
return 0;
}