#include "stdafx.h"
#include "Matriza.h"
#include <iostream>

using namespace std;


void Matriza::umnozhenie(Matriza obj1, Matriza obj2, Matriza & obj3)
{
	int l3 = obj1.l1;
	int l4 = obj1.l2;
	int l5 = obj2.l1;
	int l6 = obj2.l2;


	if ((l3 == l6) && (l4 != 1) && (l6 != 1))
	{
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				obj3.A[i][j] = 0;
				for (int k = 0; k < l4; k++)
					obj3.A[i][j] = obj3.A[i][j] + obj1.A[i][k] * obj2.A[k][j];
			}
		}
	vyvod(obj3);
}
	
	if ((l4 == 1) && (l6 == 1)) {
		int g1 = l4;
		int g2 = l6;
		int otvet;
		if (g1 == g2) {
			for (int i = 0; i < g1; i++) {
				otvet = 0;
				otvet = otvet + obj1.A[0][i] + obj2.A[0][i];
			}
		} cout << otvet << endl;
	}
	else { cout << "Idi uchi matan" << endl; }
}
void Matriza::slozhenie(Matriza obj1, Matriza obj2, Matriza & obj3)
{

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
				obj3.A[i][j] = 0;

				obj3.A[i][j] = obj1.A[i][j] + obj2.A[i][j];
			}
		}
	}
	else { cout << "Idi uchi matan; mozhno skladyvat' matrixi tol'ko odinakovogo razmera"; }
		
	}
void Matriza::vychitanie(Matriza obj1, Matriza obj2, Matriza & obj3)
{

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
				obj3.A[i][j] = 0;

				obj3.A[i][j] = obj1.A[i][j] - obj2.A[i][j];
			}
		}
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
	cout << "BASE CLASS CONSTRUCTOR STARTED" << endl;
	cout << "enter matrix length ";
	cin >> l1;
	cout << "enter matrix height ";
	cin >> l2;
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
	l4 = l2;
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
