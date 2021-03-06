//Lab4.cpp: определяет точку входа для консольного приложения.
//1. Сложение матриц
//2. Сложение векторов
//3. Умножение матриц
//4. Умножение матрицы на вектор
//5. Скалярное умножение векторов
//6. Векторное умножение векторов


#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <cmath>


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

	//1. Сложение матриц:
	std::cout << "Slozhenie matriz: A[3][3] + B[3][3] = " << std::endl;
	for (int j = 0; j<3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			C[i][j] = 0;
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << C[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << '\n' << std::endl;

	//2. Сложение векторов:
	std::cout << "Slozhenie vektorov: A1[3][1] + B1[3][1] = " << std::endl;
	for (int j = 0; j<1; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			C1[i][j] = 0;
			C1[i][j] = A1[i][j] + B1[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			std::cout << C1[i][j] << std::endl;
		}
	}

	std::cout << '\n' << std::endl;

	//3. Умножение матриц:
	std::cout << "Umnozhenie matriz: A[3][3] * B[3][3] = " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << C[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << '\n' << std::endl;

	//4. Умножение матрицы на вектор:
	std::cout << "Umnozhenie matrizy na vektor: A[3][3] * A1[3][1] = " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * A1[k][j];
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			std::cout << C[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << '\n' << std::endl;

	//5. Скалярное произведение векторов:
	std::cout << "Skalyarnoe proizvedenie: A1[3][1] * B1[3][1] = (";
	C2 = 0;
	for (int i = 0; i < 3; i++)
	{
		C2 = C2 + A1[0][i] * B1[0][i];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			std::cout << C1[i][j] << ' ';
		}
	}

	std::cout << ")";
	std::cout << '\n' << std::endl;

	//6. Векторное произведение векторов:
	std::cout << "Vektornoe proizvedenie: A1[3][1] x B1[3][1] = (";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			C1[i][j] = A1[(i + 1) % 3][j] * B1[(i + 2) % 3][j] - A1[(i + 2) % 3][j] * B1[(i + 1) % 3][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			std::cout << C1[i][j] << ' ';
		}
	}

	std::cout << ")";
	std::cout << '\n' << std::endl;

	getchar();
	return 0;
}

