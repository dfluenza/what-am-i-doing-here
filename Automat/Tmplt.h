#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class T> class Matriz
{
public:
	T * * A;
	int ll1;
	int ll2;
	~Matriz();
	Matriz();
	Matriz(int r1, int r2);
	Matriz(T **A, int l3, int l4);
	void umnozhenie(Matriz <T> obj1, Matriz <T> obj2, Matriz<T> obj3);
	void slozhenie(Matriz <T> obj1, Matriz <T> obj2, Matriz<T> obj3);
	void vychitanie(Matriz <T> obj1, Matriz <T> obj2, Matriz <T> obj3);
	void vyvod(Matriz <T> obj3);
	template <typename T>friend ostream &operator<< (ostream &os, const Matriz<T> &rhs);


	T* operator[](int elem)
	{
		return A[elem];
	}

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
	A = new T *[l1];
	for (int i = 0; i < l1; i++)
	{
		A[i] = new T[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			A[i][j] = 0;
		}
	}
}
template <typename T>
Matriz<T>::Matriz(int n1, int n2)
{
	l1 = n1;
	ll1 = l1;
	l2 = n2;
	ll2 = l2;
	A = new T *[l1];
	for (int i = 0; i < l1; i++)
	{
		A[i] = new T[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			A[i][j] = 0;
		}
	}
}

template <typename T> 
Matriz<T>::Matriz(T **A, int l3, int l4)
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
void Matriz<T>::umnozhenie(Matriz <T> obj1, Matriz <T> obj2, Matriz <T> obj3)
{
	int l3 = obj1.l1;
	int l4 = obj1.l2;
	int l5 = obj2.l1;
	int l6 = obj2.l2;


	int l1 = l3;
	int l2 = l4;
	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l1; j++)
		{
			obj3.A[i][j] = 0;
			for (int k = 0; k < l4; k++)
				obj3.A[i][j] = obj3.A[i][j] + obj1.A[i][k] * obj2.A[k][j];
		}
	}

}

template <typename T> 
void Matriz<T>::slozhenie(Matriz <T> obj1, Matriz <T> obj2, Matriz <T> obj3)
{

	int l3 = obj1.l1;
	int l5 = obj2.l1;
	int l4 = obj1.l2;
	int l6 = obj2.l2;
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

template <typename T> 
void Matriz<T>::vychitanie(Matriz<T>  obj1, Matriz <T> obj2, Matriz <T> obj3)
{
	int l3 = obj1.l1;
	int l5 = obj2.l1;
	int l4 = obj1.l2;
	int l6 = obj2.l2;
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
	
template <typename T> 
void Matriz<T>::vyvod(Matriz <T> obj3)
{
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
	if ((lhs.ll1 == rhs.ll1) && (lhs.ll2 == rhs.ll2))
	{
		Matriz <T> result(lhs.ll1, rhs.ll2);
		result.slozhenie(lhs, rhs, result);
		return result;
	}
	else {
		Matriz <T> result(1, 1);
		return result;
	}
}

template <typename T>
Matriz <T> operator - (Matriz <T> lhs,
	Matriz <T> rhs)

	{
	if ((lhs.ll1 == rhs.ll1) && (lhs.ll2 == rhs.ll2))
	{
		Matriz <T> result(lhs.ll1, rhs.ll2);
		result.vychitanie(lhs, rhs, result);
		return result;
	}
		else {
			Matriz <T> result(1, 1);
			return result;
		}
		}

	template <typename T>
	Matriz <T> operator * (Matriz <T> lhs,
		Matriz <T> rhs)
	{
		if (lhs.ll1 == rhs.ll2)
		{
			Matriz <T> result(lhs.ll1, rhs.ll2);
			result.umnozhenie(lhs, rhs, result);
			return result;
		}
		else {
			Matriz <T> result(1, 1);
			return result;
		}
	}

template <typename T>
ostream &operator<<(ostream &os, Matriz<T>& rhs)
{
	rhs.vyvod (rhs);
	return os;
}

template <class T> class Vector : public Matriz <T>
{
private:
	int l1 = 1;
	int l2;


public:
	T * * Vect;
	void vectornoe(Vector<T> obj1, Vector<T> obj2, Vector<T> result);
	Vector(T **obj1, int g1);
	Vector(int n2);
	Vector();
	~Vector();
};

template <typename T>
Vector<T>::~Vector()
{
}

template <typename T>
Vector<T>::Vector()
{
	cout << "enter vector length ";
	cin >> l2;
	Vect = new T *[1];
	for (int i = 0; i <1; i++)
	{
		Vect[i] = new T[l2];

	}

	for (int i = 0; i<1; i++)
	{
		for (int j = 0; j < l2; j++) {
			Vect[i][j] = 0;
		}
	}
}

template <typename T>
Vector<T>::Vector(T **obj1, int g1)
{
	l2 = g1;
	Vect = new T *[l1];
	for (int i = 0; i <1; i++)
	{
		Vect[i] = new T[l2];

	}

	for (int i = 0; i<1; i++)
	{
		for (int j = 0; j < g1; j++) {
			Vect[i][j] = Vect[i][j];
		}
	}
}

template <typename T>
Vector<T>::Vector(int n2)
{
	l1 = 1;
	l2 = n2;
	Vect = new T *[1];
	for (int i = 0; i < l1; i++)
	{
		Vect[i] = new T[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			Vect[i][j] = 0;
		}
	}
}
template <typename T>
void Vector<T>::vectornoe(Vector<T> obj1, Vector<T> obj2, Vector<T> result)
{

	int g1 = obj1.l2;
	int g2 = obj2.l2;
	if (g1 != 3 || g2 != 3) {}
	else
	{
		if (g1 == g2)
		{
			for (int i = 0; i < g1; i++)
			{
				result.Vect[0][i] = obj1.Vect[0][(i + 1) % 3] * obj2.Vect[0][(i + 2) % 3] - obj1.Vect[0][(i + 2) % 3] * obj2.Vect[0][(i + 2) % 3];

			}
		}

	}

}
