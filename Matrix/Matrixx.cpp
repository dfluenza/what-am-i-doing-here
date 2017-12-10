#include "stdafx.h"
#include "Matrixx.h"
#include <iostream>

using namespace std;

void Matrixx::vyvod_matrix(int ** A, int l3, int l4)
{
	for (int i = 0; i < l3; i++) {
		for (int j = 0; j < l4; j++)
		{
			cout << A[i][j] << " \t";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

void Matrixx::matrix_slozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A)
{
	if (l1 == l5 && l2 == l6)
	{
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				A[i][j] = 0;
				A[i][j] = A1[i][j] + A2[i][j];
			}
		}
	}
	else { cout << "Idi uchi matan; mozhno skladyvat' matrixi tol'ko odinakovogo razmera" << endl; }
}

void Matrixx::matrix_umnozhenie(int **& A, int **& A1, int l3, int l4, int **& A2, int l5, int l6)
{
	if ((l3 == l6)&&(l4 != 1)&&(l6 != 1))
	{
		for (int i = 0; i < l3; i++)
		{
			for (int j = 0; j < l4; j++)
			{
				A[i][j] = 0;
				for (int k = 0; k < l4; k++)
					A[i][j] = A[i][j] + A1[i][k] * A2[k][j];
			}
		}
	}
	else { cout << "Idi uchi matan; mozhno umnozhat' matrixi tol'ko s odinakovymi strokami-stolbzami" << endl; }
}



Matrixx::Matrixx()
{
	cin >> l3;
	cin >> l4;

	for (int i = 0; i < l3; i++)
	{
		A[i] = new int[l4];

	}

	for (int i = 0; i < l3; i++) {
		for (int j = 0; j < l4; j++)
		{
			A[i][j] = 0;
		}
	}
}

Matrixx::Matrixx(int **A1, int l1, int l2)
{
	l1 = l3;
	l2 = l4;
	for (int i = 0; i <l3; i++)
	{
		A[i] = new int[l4];

	}

	for (int i = 0; i<l3; i++)
	{
		for (int j = 0; j < l4; j++) {
			A[i][j] = A1[i][j];
		}
	}
}

Matrixx::~Matrixx()
{
	/*for (int i = 0; i < l3; i++)
	{
	delete A[i];
	}
	delete[] A;*/
}