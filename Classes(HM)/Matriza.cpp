#include "stdafx.h"
#include "Matriza.h"
#include <iostream>

using namespace std;


Matriza Matriza::umnozhenie(Matriza obj1, Matriza obj2)
{
	int l3 = obj1.l1;
	int l4 = obj1.l2;
	int l5 = obj2.l1;
	int l6 = obj2.l2;


	if ((l3 == l6) && (l4 != 1) && (l6 != 1))
	{
		Matriza otvet(obj1.l1, obj2.l2);
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l1; j++)
			{
				otvet.A[i][j] = 0;
				for (int k = 0; k < l4; k++)
					otvet.A[i][j] = otvet.A[i][j] + obj1.A[i][k] * obj2.A[k][j];
			}
		}
		return otvet;
	}
	else { cout << "Idi uchi matan" << endl; }
}
Matriza Matriza::slozhenie(Matriza obj1, Matriza obj2)
{

	int l3 = obj1.l1;
	int l5 = obj2.l1;
	int l4 = obj1.l2;
	int l6 = obj2.l2;

	if ((l3 == l5) && (l4 == l6))
	{
		Matriza otvet(obj1.l1, obj1.l2);
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				otvet.A[i][j] = 0;

				otvet.A[i][j] = obj1.A[i][j] + obj2.A[i][j];
			}
		}
		return otvet;
	}
	else { cout << "Idi uchi matan"; }
		
	}
Matriza Matriza::vychitanie(Matriza obj1, Matriza obj2)
{
	Matriza otvet(obj1.l1, obj1.l2);
	int l3 = obj1.l1;
	int l5 = obj2.l1;
	int l4 = obj1.l2;
	int l6 = obj2.l2;

	if ((l3 == l5) && (l4 == l6))
	{
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				otvet.A[i][j] = 0;

				otvet.A[i][j] = obj1.A[i][j] - obj2.A[i][j];
			}
		}
		return otvet;
	}
	else { cout << "Idi uchi matan; mozhno vychitat' matrixi tol'ko odinakovogo razmera"; }

}
void Matriza::vyvod(Matriza obj3)
{
	cout << endl;
	cout << endl;
	int l1 = obj3.l1;
	int l2 = obj3.l2;
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			cout << obj3.A[i][j] << " \t";
		}
		cout << std::endl;
	}
	cout << std::endl;
}



Matriza::Matriza()
{
	cout << "enter matrix length ";
	cin >> l1;
	ll1 = l1;
	cout << "enter matrix height ";
	cin >> l2;
	ll2 = l2;
	A = new int *[l1];
	for (int i = 0; i < l1; i++)
	{
		A[i] = new int[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			A[i][j] = 2;
		}
	}
}

Matriza::Matriza(int ll1, int ll2)
{
	l1 = ll1;
	l2 = ll2;
	A = new int *[l1];
	for (int i = 0; i < l1; i++)
	{
		A[i] = new int[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			A[i][j] = 2;
		}
	}
}

Matriza::Matriza(int **A1, int l3, int l4)
{
	l3 = l1;
	ll1 = l1;
	l4 = l2;
	ll2 = l2;
	A = new int *[l1];
	for (int i = 0; i <l1; i++)
	{
		A[i] = new int[l2];

	}

	for (int i = 0; i<l1; i++)
	{
		for (int j = 0; j < l2; j++) {
			A[i][j] = A1[i][j];
		}
	}
}


Matriza::~Matriza()
{	/*for (int i = 0; i < l1; i++)
	{
	delete A[i];
	}
	delete[] A;*/
}
