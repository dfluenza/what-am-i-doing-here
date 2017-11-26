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

void Matrixx::matrix_umnozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A)
{
	if (l1 == l6)
	{
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				A[i][j] = 0;
				for (int k = 0; k < l2; k++)
					A[i][j] = A[i][j] + A1[i][k] * A2[k][j];
			}
		}
	}
	else { cout << "Idi uchi matan; mozhno umnozhat' matrixi tol'ko s odinakovymi strokami-stolbzami" << endl; }
}

void Matrixx::matrix_na_vector(int **& A1, int l1, int l2, int **& B1, int g1, int **& B)
{if (l2 == g1)
	{
		for (int i = 0; i < l2; i++) { B[0][i] = 0; }
		for (int i = 0; i < l2; i++)
		{
			for (int j = 0; j < g1; j++)
			{
				B[0][i] = B[0][i] + A1[i][j] * B1[0][j];
			}
		}
	}
	else { cout << "Idi uchi matan; mozhno umnozhat' matrix na vector tol'ko odinakovoi vysoty" << endl; }
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