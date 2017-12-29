#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class MyClass> class Matriz
{
public:
	int ** A;
	int ll1;
	int ll2;
	Matriz();
	Matriz(int l1, int l2);
	Matriz(int **A, int l3, int l4);
	Matriz umnozhenie(Matriza obj1, Matriza obj2);
	Matriz slozhenie(Matriza obj1, Matriza obj2);
	Matriz vychitanie(Matriza obj1, Matriza obj2);
	void vyvod(Matriza obj3);

private:
	int l1;
	int l2;

};

template <class MyClass> Matriz::Matriz()
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
template <class MyClass> Matriz::Matriz(int ll1, int ll2)
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
template <class MyClass> Matriz::Matriz(int **A1, int l3, int l4)
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

template <class MyClass> Matriz::~Matriz()
{
}

template <class MyClass> Matriz::umnozhenie(Matriz obj1, Matriz obj2)
{
	int l3 = obj1.l1;
	int l4 = obj1.l2;
	int l5 = obj2.l1;
	int l6 = obj2.l2;


	if ((l3 == l6) && (l4 != 1) && (l6 != 1))
	{
		Matriz otvet(obj1.l1, obj2.l2);
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
template <class MyClass> Matriz::slozhenie(Matriz obj1, Matriz obj2)
{

	int l3 = obj1.l1;
	int l5 = obj2.l1;
	int l4 = obj1.l2;
	int l6 = obj2.l2;

	if ((l3 == l5) && (l4 == l6))
	{
		Matriz otvet(obj1.l1, obj1.l2);
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
template <class MyClass> Matriz::vychitanie(Matriz obj1, Matriz obj2)
{
	Matriz otvet(obj1.l1, obj1.l2);
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
template <class MyClass> Matriz::vyvod(Matriza obj3)
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