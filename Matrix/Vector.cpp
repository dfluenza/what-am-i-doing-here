#include "stdafx.h"
#include "Vector.h"
#include <iostream>
using namespace std;

void Vector::vyvod_vector(int **B, int g1)
{
	for (int i = 0; i < g1; i++)
	{
		std::cout << B[0][i] << " \t";
	}
	std::cout << std::endl;
}

void Vector::scalyarnoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int & C)
{if (g2 == g1)
	{
		C = 0;
		for (int i = 0; i < 3; i++)
		{
			C = C + B1[0][i] * B2[0][i];
		}
	}
	else { cout << "Idi uchi matan; mozhno umnozhat' vectory tol'ko odinakovoi velichiny" << endl; }
}

void Vector::vectornoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int **& B)
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
Vector::Vector()
{
	cin >> g2;
	for (int i = 0; i < 1; i++)
	{
		B[i] = new int[g2];

	}
	for (int i = 0; i < g2; i++)
	{
		B[0][i] = 0;

	}

}
Vector::Vector(int **B1, int g1)
{
	for (int i = 0; i < 1; i++)
	{
		B[i] = new int[g1];

	}
	for (int i = 0; i < g1; i++)
	{
		B[0][i] = B1[0][i];

	}
}

Vector::~Vector()
{
}