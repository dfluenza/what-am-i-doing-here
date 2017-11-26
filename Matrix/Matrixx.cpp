#include "stdafx.h"
#include "Matrixx.h"
#include <iostream>

using namespace std;

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
void Matrixx::vector_slozhenie(int **& B1, int g1, int **& B2, int g2, int **& B) //сложение двух векторов
{
	if (g1 == g2)
	{
		for (int i = 0; i < g1; i++)
		{
			B[0][i] = 0;
			B[0][i] = B1[0][i] + B2[0][i];
		}
	}
	else { cout << "Idi uchi matan; mozhno skladyvat' vektory tol'ko odinakovogo razmera" << endl; }
}
void Matrixx::matrix_umnozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A) //перемножение двух матриц
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
void Matrixx::matrix_na_vector(int **& A1, int l1, int l2, int **& B1, int g1, int **& B) //умножение матрицы на вектор
{
	if (l2 == g1)
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
void Matrixx::scalyarnoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int & C) //скалярное произведение двух векторов
{
	if (g2 == g1)
	{
		C = 0;
		for (int i = 0; i < 3; i++)
		{
			C = C + B1[0][i] * B2[0][i];
		}
	}
	else { cout << "Idi uchi matan; mozhno umnozhat' vectory tol'ko odinakovoi velichiny" << endl; }
}
void Matrixx::vectornoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int **& B) //векторное произведение двух векторов
{
	if (g1 != 3 || g2 != 3) { cout << "Idi uchi matan; mozhno umnozhat' tol'ko trehmernye vectory" << endl; }
	else {
		if (g1 == g2)
		{
			for (int i = 0; i < g1; i++)
			{
				B[0][i] = B1[0][(i + 1) % 3] * B2[0][(i + 2) % 3] - B1[0][(i + 2) % 3] * B2[0][(i + 2) % 3];

			}
		}
		else { cout << "Idi uchi matan; mozhno umnozhat' tol'ko ravnye vectory" << endl; }
	}
}
void Matrixx::vyvod_matrix(int **A, int l1, int l2) //вывод матрицы-ответа
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
void Matrixx::vyvod_vector(int **B, int g1) //вывод вектора-ответа
{
	for (int i = 0; i < g1; i++)
	{
		std::cout << B[0][i] << " \t";
	}
	std::cout << std::endl;
}




Matrixx::Matrixx()
{
	cin >> l1;
	cin >> l2;
	for (int i = 0; i < l1; i++) {
		A[i] = new int[l2];
	}
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			A[i][j] = 0;
		}
	}
}


Matrixx::~Matrixx()
{
}
