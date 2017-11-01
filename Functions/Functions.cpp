// Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <cmath>


void matrix_slozhenie(int(&C)[3][3], int A[3][3], int B[3][3]) //сложение двух матриц
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 0;
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void vector_slozhenie(int(&C1)[3][1], int A1[3][1], int B1[3][1]) //сложение двух векторов
{
	for (int i = 0; i < 3; i++)
	{
		C1[0][i] = 0;
		C1[0][i] = A1[0][i] + B1[0][i];
	}
}

void matrix_umnozhenie(int(&C)[3][3], int A[3][3], int B[3][3]) //перемножение двух матриц
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < 3; k++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
		}
	}
}

void matrix_na_vector(int(&C1)[3][1], int A[3][3], int A1[3][1]) //умножение матрицы на вектор
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			C1[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				C1[i][j] = C1[i][j] + A[i][k] * A1[k][j];
			}
		}
	}
}

void scalyarnoe_proizvedenie(int &C2, int A1[3][1], int B1[3][1]) //скалярное произведение двух векторов
{
	C2 = 0;
	for (int i = 0; i < 3; i++)
	{
		C2 = C2 + A1[0][i] * B1[0][i];
	}
}

void vectornoe_proizvedenie(int(&C1)[3][1], int A1[3][1], int B1[3][1]) //векторное произведение двух векторов
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			C1[i][j] = A1[(i + 1) % 3][j] * B1[(i + 2) % 3][j] - A1[(i + 2) % 3][j] * B1[(i + 1) % 3][j];
		}
	}
}

void vyvod_matrix(int C[3][3]) //вывод матрицы-ответа
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << C[i][j] << " \t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void vyvod_vector(int C1[3][1]) //вывод вектора-ответа
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << C1[0][i] << " \t";
	}
	std::cout << std::endl;
}


int main()
{
	int A[3][3] = { { 1, 2, 3 },
					{ 4, 5, 6 },
					{ 7, 8, 9 } };

	int B[3][3] = { { 1, 2, 3 },
					{ 4, 5, 6 },
					{ 7, 8, 9 } };

	int C[3][3] = { 0 };

	int A1[3][1] = { { 1 },
					 { 3 },
					 { 3 } };

	int B1[3][1] = { { 1 },
					 { 3 },
					 { 3 } };

	int C1[3][1] = { 0 };

	int C2 = 0;

	matrix_slozhenie(C, A, B);
	std::cout << "Summa matrix ravna:" << std::endl;
	vyvod_matrix(C);
	vector_slozhenie(C1, A1, B1);
	std::cout << "Summa vectorov ravna:" << std::endl;
	vyvod_vector(C1);
	matrix_umnozhenie(C, A, B);
	std::cout << "Proizvedenie matrix ravno:" << std::endl;
	vyvod_matrix(C);
	matrix_na_vector(C1, A, A1);
	std::cout << "Proizvedenie matrix na vector ravno:" << std::endl;
	vyvod_vector(C1);
	scalyarnoe_proizvedenie(C2, A1, B1);
	std::cout << '\n' << std::endl;
	std::cout << "Skalyarnoe proizvedenie ravno " << C2 << std::endl << std::endl;
	vectornoe_proizvedenie(C1, A1, B1);
	std::cout << "Vectornoe proizvedenie ravno:" << std::endl;
	vyvod_vector(C1);

	getchar();
	return 0;
}



