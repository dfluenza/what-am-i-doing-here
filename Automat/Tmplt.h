#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class T> class Matriz
{
public:
	int ** A;
	int ll1;
	int ll2;
	~Matriz();
	Matriz();
	Matriz(T l1, T l2);
	Matriz(T **A, T l3, T l4);
	void umnozhenie(Matriz <T> obj1, Matriz <T> obj2);
	void slozhenie(Matriz <T> obj1, Matriz <T> obj2);
	void vychitanie(Matriz <T> obj1, Matriz <T> obj2);
	void vyvod(Matriz <T> obj3);
	friend ostream &operator<< (ostream &os, const Matriz<T> &rhs);
private:
	int l1;
	int l2;

};

template <typename T>
Matriz<T>::Matriz()
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
template <typename T>
Matriz<T>::Matriz(T ll1, T ll2)
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
template <typename T> 
Matriz<T>::Matriz(T **A1, T l3, T l4)
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

template <typename T> 
Matriz<T>::~Matriz()
{
}

template <typename T>
void Matriz<T>::umnozhenie(Matriz <T> obj1, Matriz <T> obj2)
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
template <typename T> 
void Matriz<T>::slozhenie(Matriz <T> obj1, Matriz <T> obj2)
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
template <typename T> 
void Matriz<T>::vychitanie(Matriz<T>  obj1, Matriz <T> obj2)
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
template <typename T> 
void Matriz<T>::vyvod(Matriz <T> obj3)
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

template <typename T> 
Matriz <T> operator + (Matriz <T> lhs,
	Matriz <T> rhs)
{
	Matriz <T> result(1, 1);
	return result.slozhenie(lhs, rhs );
}

template <typename T>
Matriz <T> operator - (Matriz <T> lhs,
	Matriz <T> rhs)
{
	Matriz <T> result(1, 1);

	return result.vychitanie(lhs, rhs);

}
template <typename T>
Matriz <T> operator * (Matriz <T> lhs,
	Matriz <T> rhs)
{
	Matriz <T> result(1, 1);

	return result.umnozhenie (lhs, rhs);
}
template <typename T>
ostream &operator<<(ostream &os, const Matriz<T>& rhs)
{
	rhs.vyvod;
	return os;
}

//template <typename T>
//friend ostream& operator << (ostream & os,
//	Matriz <T> & rhs)
//{
//	rhs.vyvod(rhs);
//	return os;
//}
