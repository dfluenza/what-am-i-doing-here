// Massive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

void matrix_slozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A) //сложение двух матриц
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

void vector_slozhenie(int **& B1, int g1, int **& B2, int g2, int **& B) //сложение двух векторов
{ if(g1==g2)
	{ 
		for (int i = 0; i < g1; i++)
		{
			B[0][i] = 0;
			B[0][i] = B1[0][i] + B2[0][i];
		}
	} else { cout << "Idi uchi matan; mozhno skladyvat' vektory tol'ko odinakovogo razmera" << endl; }
}

void matrix_umnozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A) //перемножение двух матриц
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
	} else { cout << "Idi uchi matan; mozhno umnozhat' matrixi tol'ko s odinakovymi strokami-stolbzami" << endl; }
}

void matrix_na_vector(int **& A1, int l1, int l2, int **& B1, int g1, int **& B) //умножение матрицы на вектор
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
		} else { cout << "Idi uchi matan; mozhno umnozhat' matrix na vector tol'ko odinakovoi vysoty" << endl; }
}

void scalyarnoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int & C) //скалярное произведение двух векторов
{
	if (g2 == g1)
	{
		C = 0;
		for (int i = 0; i < 3; i++)
		{
			C = C + B1[0][i] * B2[0][i];
		}
	} else { cout << "Idi uchi matan; mozhno umnozhat' vectory tol'ko odinakovoi velichiny" << endl; }
}

void vectornoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int **& B) //векторное произведение двух векторов
{
	if (g1 != 3 || g2 != 3) { cout << "Idi uchi matan; mozhno umnozhat' tol'ko trehmernye vectory" << endl; }
	else {
		if (g1 == g2)
		{
			for (int i = 0; i < g1; i++)
			{
				B[0][i] = B1[0][(i + 1) % 3] * B2[0][(i + 2) % 3] - B1[0][(i + 2) % 3] * B2[0][(i + 2) % 3];

			}
		} else { cout << "Idi uchi matan; mozhno umnozhat' tol'ko ravnye vectory" << endl; }
	}
}

void vyvod_matrix(int **A, int l1, int l2) //вывод матрицы-ответа
{
	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			std::cout << A[i][j] << " \t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void vyvod_vector(int **B, int g1) //вывод вектора-ответа
{
	for (int i = 0; i < g1; i++)
	{
		std::cout << B[0][i] << " \t";
	}
	std::cout << std::endl;
}


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

	matrix_slozhenie(A1, l1, l2, A2, l5, l6, A);
	if (l1 == l5 && l2 == l6)
	{
		cout << "Summa matrix ravna:" << std::endl;
		vyvod_matrix(A, l1, l2);
	}

	vector_slozhenie(B1, g1, B2, g2, B);
	if (g1 == g2)
	{
		std::cout << "Summa vectorov ravna:" << std::endl;
		vyvod_vector(B, g1);
	}

	matrix_umnozhenie(A1, l1, l2, A2, l5, l6, A);
	if (l1 == l5 && l2 == l6)
	{
		std::cout << "Proizvedenie matrix ravno:" << std::endl;
		vyvod_matrix(A, l1, l2);
	}

	matrix_na_vector(A1, l1, l2, B1, g1, B);
	if (l2 == g1)
	{
		std::cout << "Proizvedenie matrix na vector ravno:" << std::endl;
		vyvod_vector(B, g1);
	}

	scalyarnoe_proizvedenie(B1, g1, B2, g2, C);
	if (g1 == g2)
	{
		std::cout << '\n' << std::endl;
		std::cout << "Skalyarnoe proizvedenie ravno " << C << std::endl << std::endl;
	}

	vectornoe_proizvedenie(B1, g1, B2, g2, B);
	if (g1 == 3 && g2 == 3)
	{
		std::cout << "Vectornoe proizvedenie ravno:" << std::endl;
		vyvod_vector(B, g1);
	}

		for (int i = 0; i < l1; i++)
		{
			delete A[i];
		}
		delete[] A;
		for (int i = 0; i < l1; i++)
		{
			delete A1[i];
		}
		delete[] A1;
		for (int i = 0; i < l5; i++)
		{
			delete A2[i];
		}
		delete[] A2;
		for (int i = 0; i < g1; i++)
		{
			delete B[i];
		}
		delete[] B;
		for (int i = 0; i < g1; i++)
		{
			delete B1[i];
		}
		delete[] B1;
		for (int i = 0; i < g2; i++)
		{
			delete B2[i];
		}
		delete[] B2;


	system("pause");
	return 0;
}
