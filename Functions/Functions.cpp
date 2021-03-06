// Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <cmath>


void matrix_slozhenie(int(&A)[3][3], int A1[3][3], int A2[3][3]) //сложение двух матриц
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			A[i][j] = 0;
			A[i][j] = A1[i][j] + A2[i][j];
		}
	}
}

void vector_slozhenie(int(&B)[3][1], int B1[3][1], int B2[3][1]) //сложение двух векторов
{
	for (int i = 0; i < 3; i++)
	{
		B[0][i] = 0;
		B[0][i] = B1[0][i] + B2[0][i];
	}
}

void matrix_umnozhenie(int(&A)[3][3], int A1[3][3], int A2[3][3]) //перемножение двух матриц
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			A[i][j] = 0;
			for (int k = 0; k < 3; k++)
				A[i][j] = A[i][j] + A1[i][k] * A2[k][j];
		}
	}
}

void matrix_na_vector(int(&B)[3][1], int A1[3][3], int B1[3][1]) //умножение матрицы на вектор
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			B[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				B[i][j] = B[i][j] + A1[i][k] * B1[k][j];
			}
		}
	}
}

void scalyarnoe_proizvedenie(int &C, int B1[3][1], int B2[3][1]) //скалярное произведение двух векторов
{
	C = 0;
	for (int i = 0; i < 3; i++)
	{
		C = C + B1[0][i] * B2[0][i];
	}
}

void vectornoe_proizvedenie(int(&B)[3][1], int B1[3][1], int B2[3][1]) //векторное произведение двух векторов
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			B[i][j] = B1[(i + 1) % 3][j] * B2[(i + 2) % 3][j] - B1[(i + 2) % 3][j] * B2[(i + 1) % 3][j];
		}
	}
}

void vyvod_matrix(int A[3][3]) //вывод матрицы-ответа
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << A[i][j] << " \t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void vyvod_vector(int B[3][1]) //вывод вектора-ответа
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << B[0][i] << " \t";
	}
	std::cout << std::endl;
}


int main()
{
	int A1[3][3] = { { 1, 2, 3 },
					{ 4, 5, 6 },
					{ 7, 8, 9 } };

	int A2[3][3] = { { 1, 2, 3 },
					{ 4, 5, 6 },
					{ 7, 8, 9 } };

	int A[3][3] = { 0 };

	int B1[3][1] = { { 1 },
					 { 3 },
					 { 3 } };

	int B2[3][1] = { { 1 },
					 { 3 },
					 { 3 } };

	int B[3][1] = { 0 };

	int C = 0;

	matrix_slozhenie(A, A1, A2);
	std::cout << "Summa matrix ravna:" << std::endl;
	vyvod_matrix(A);
	vector_slozhenie(B, B1, B2);
	std::cout << "Summa vectorov ravna:" << std::endl;
	vyvod_vector(B);
	matrix_umnozhenie(A, A1, A2);
	std::cout << "Proizvedenie matrix ravno:" << std::endl;
	vyvod_matrix(A);
	matrix_na_vector(B, A1, B1);
	std::cout << "Proizvedenie matrix na vector ravno:" << std::endl;
	vyvod_vector(B);
	scalyarnoe_proizvedenie(C, B1, B2);
	std::cout << '\n' << std::endl;
	std::cout << "Skalyarnoe proizvedenie ravno " << C << std::endl << std::endl;
	vectornoe_proizvedenie(B, B1, B2);
	std::cout << "Vectornoe proizvedenie ravno:" << std::endl;
	vyvod_vector(B);

	getchar();
	return 0;
}



