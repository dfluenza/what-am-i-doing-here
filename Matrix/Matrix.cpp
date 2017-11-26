// Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrixx.h"
#include <iostream>

using namespace std;

int main()
{
	int l1;
	int l2;
	int l3;
	int l4;
	int l5;
	int l6;

	int g2;
	int g1;

	int C;

	cout << "Enter first matrix length " << endl;
	cin >> l3;
	l1 = l3;

	cout << "Enter first matrix width " << endl;
	cin >> l4;
	l2 = l4;

	cout << "Enter second matrix length " << endl;
	cin >> l5;

	cout << "Enter second matrix width " << endl;
	cin >> l6;

	cout << "Enter first vector length " << endl;
	cin >> g1;

	cout << "Enter second vector length " << endl;
	cin >> g2;

	int ** A1 = new int *[l1]; //первая матрица
	for (int i = 0; i < l1; i++)
	{
		A1[i] = new int[l2];
	}

	int ** A2 = new int *[l5]; //вторая матрица
	for (int i = 0; i < l5; i++)
	{
		A2[i] = new int[l6];
	}
	int ** A = new int *[l3]; //матрица-ответ
	for (int i = 0; i < l3; i++)
	{
		A[i] = new int[l4];
	}
	int ** B1 = new int *[1]; //первый вектор
	for (int i = 0; i < 1; i++)
	{
		B1[i] = new int[g1];
	}
	int ** B2 = new int *[1]; //второй вектор
	for (int i = 0; i < 1; i++)
	{
		B2[i] = new int[g2];
	}
	int ** B = new int *[1]; //вектор-ответ
	for (int i = 0; i < 1; i++)
	{
		B[i] = new int[g1];
	}

	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			A1[i][j] = 2;
		}
	}
	for (int i = 0; i < l5; i++)
	{
		for (int j = 0; j < l6; j++)
		{
			A2[i][j] = 2;
		}
	}
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < g1; j++)
		{
			B1[i][j] = 2;
		}
	}
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < g2; j++)
		{
			B2[i][j] = 2;
		}
	}
	Matrixx matrix;
	matrix.matrix_slozhenie(A1, l1, l2, A2, l5, l6, A);
	matrix.vector_slozhenie(B1, g1, B2, g2, B);
	matrix.matrix_umnozhenie(A1, l1, l2, A2, l5, l6, A);
	matrix.matrix_na_vector(A1, l1, l2, B1, g1, B);
	matrix.scalyarnoe_proizvedenie(B1, g1, B2, g2, C);
	matrix.vectornoe_proizvedenie(B1, g1, B2, g2, B);
	

    return 0;
}

