// Massive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

void vyvod_matrix(int ** matrixdyn, int l1, int l2)
{for (int i = 0; i < l1; i++) 
	{for (int j = 0; j < l2; j++)
		{
			std::cout << matrixdyn[i][j] << " \t";
		}
	 std::cout << std::endl;
	}
 std::cout << std::endl;
}

void vyvod_vector(int** vectordyn, int g1)
{for (int i = 0; i < 3; i++) 
	{
		std::cout << vectordyn[0][i] << " \t";
	}
 std::cout << std::endl;
}

void matrix_slozhenie(int**& matrixdyn, int** matrixdyn1, int l3, int l4, int** matrixdyn2, int l5, int l6)
{if (l3 == l5 | l4 == l6) 
	{int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++) 
		{for (int j = 0; j < l2; j++) 
			{matrixdyn[i][j] = 0;
			 matrixdyn[i][j] = matrixdyn1[i][j] + matrixdyn2[i][j];
			}
		}
		vyvod_matrix(matrixdyn, l1, l2);
	}
	else {cout << "sum can't be calc"; }
}





void vect_slozhenie(int**& vectsumdyn, int **vector1, int g1, int ** vector2, int g2)
{if (g1 == g2) 
	{for (int i = 0; i < g1; i++) 
		{vectsumdyn[0][i] = 0;
		 vectsumdyn[0][i] = vector1[0][i] + vector2[0][i];
		}
		vyvod_vector(vectsumdyn, g1);
	}
}






void matrix_umnozhenie(int**& matrixdyn, int** matrixdyn1, int l3, int l4, int** matrixdyn2, int l5, int l6)
{if (l3 == l6 | l4 == l5) 
	{int l1 = l3;
	 int l2 = l4;
	 for (int i = 0; i < l1; i++) 
		{for (int j = 0; j < l2; j++) 
			{matrixdyn[i][j] = 0;
			 for (int k = 0; k < l2; k++)
				matrixdyn[i][j] = matrixdyn[i][j] + matrixdyn1[i][k] * matrixdyn2[k][j];

			}
		}
		vyvod_matrix(matrixdyn, l1, l2);
	}
	else { cout << "uncountable pair of matrix" << endl; }
}

void matrix_na_vector(int**& matrixdyn, int** matrixdyn1, int l3, int l4, int **vector1, int g1)
{if (l4 == g1) 
	{for (int i = 0; i < l3; i++) 
		{for (int j = 0; j < l4; j++) 
			{
				matrixdyn[0][1] = matrixdyn[0][1] + matrixdyn1[i][j] * vector1[0][j];
			}
		}
		vyvod_vector(matrixdyn, g1);
	}
	else { cout << "uncountable" << endl; }
}

void skalyar(int &otvet, int **vector1, int g1, int ** vector2, int g2)
{if (g1 == g2) 
	{otvet = 0;
	 for (int i = 0; i < 3; i++) 
	 {
		otvet = otvet + vector1[0][i] * vector2[0][i];
	 }
	 cout << otvet << endl;
	}
	else { cout << "uncountable" << endl; }
}
void vectornoe(int **& matrixvectdyn, int **vector1, int g1, int ** vector2, int g2, int**& vectsumdyn)
{for (int i = 0; i < 3; i++) 
	{if (i == 0) 
		{for (int j = 0; j < 3; j++) 
			{
				matrixvectdyn[i][j] = 1;
			}

		}
		else 
		{if (i == 1)
			{
				for (int j = 0; j < 3; j++) {

					matrixvectdyn[i][j] = vector1[0][j];

				}
			}
			else {
				for (int j = 0; j < 3; j++) {

					matrixvectdyn[i][j] = vector2[0][j];

				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		vectsumdyn[0][i] = 0;
	}
	for (int i = g1 - 1; i > -1; i--) { //ПРИДУМАТЬ РЕШЕНИЕ ДЛЯ МАТРИЦ НЕ 3х3
		(i == 0) ?
			(vectsumdyn[0][i] = matrixvectdyn[1][(i + 1) / 3] * matrixvectdyn[2][i + 1] - matrixvectdyn[1][i + 1] * matrixvectdyn[2][(i + 1) / 3])
			:
			(vectsumdyn[0][i] = matrixvectdyn[1][(i + 1) / 3] * matrixvectdyn[2][2] - matrixvectdyn[1][2] * matrixvectdyn[2][(i + 1) / 3]);
	}
	vyvod_vector(vectsumdyn, g1);
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

	cout << "enter first matrix length " << endl;

	cin >> l3;
	l1 = l3;
	cout << "enter first matrix width " << endl;

	cin >> l4;
	l2 = l4;
	cout << "enter second matrix length " << endl;

	cin >> l5;

	cout << "enter second matrix width " << endl;

	cin >> l6;

	cout << "enter first vector length " << endl;

	cin >> g1;

	cout << "enter second vector length " << endl;

	cin >> g2;
	int ** matrixvectdyn = new int *[l3];
	for (int i = 0; i < l1; i++)
	{
		matrixvectdyn[i] = new int[l2];
	}

	int ** matrixdyn = new int *[l1];

	int ** matrixdyn1 = new int *[l3];

	int ** matrixdyn2 = new int *[l5];

	for (int i = 0; i < l1; i++)
	{
		matrixdyn[i] = new int[l2];
	}
	for (int i = 0; i < l1; i++)
	{
		matrixdyn1[i] = new int[l4];
	}
	for (int i = 0; i < l1; i++)
	{
		matrixdyn2[i] = new int[l6];
	}


	int ** vectdyn = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vectdyn[i] = new int[g1];
	}

	int ** vectdyn1 = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vectdyn1[i] = new int[g1];
	}

	int ** vectdyn2 = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vectdyn2[i] = new int[g2];
	}


	for (int i = 0; i < g1; i++) 
	{
		vectdyn1[0][i] = rand() % 5;
	}
	for (int i = 0; i < g2; i++) {
		vectdyn2[0][i] = rand() % 5;
	}

	for (int i = 0; i < l3; i++) 
	{for (int j = 0; j < l4; j++)
		{
			matrixdyn1[i][j] = rand() % 5;
		}
	}
	for (int i = 0; i < l5; i++) 
	{for (int j = 0; j < l6; j++)
		{
			matrixdyn2[i][j] = rand() % 5;
		}
	}
	int matrix_vector[3][3];

	int otvet = 0;

	int matrix1[3][3] = { { 1, 2, 3 },
						  { 4, 5, 6 },
						  { 7, 8, 9 } };

	int matrix2[3][3] = { { 10, 11, 12 },
						  { 13, 14, 15 },
						  { 16, 17, 18 } };

	int matrix_sum[3][3] = { { 0,0,0 },
							 { 0,0,0 },
							 { 0,0,0 } };

	int vector1[1][3] = { 1, 2, 3 };

	int vector2[1][3] = { 1, 2, 3 };

	int vector_sum[1][3] = { 0,0,0 };

	cout << endl << endl;
	cout << "matrix sum" << endl;
	matrix_slozhenie(matrixdyn, matrixdyn1, l3, l4, matrixdyn2, l5, l6);

	cout << endl << endl;
	cout << "vect sum" << endl;

	vect_slozhenie(vectdyn, vectdyn1, g1, vectdyn2, g2);

	cout << endl << endl;
	cout << "matrix proizvedenie" << endl;
	matrix_umnozhenie(matrixdyn, matrixdyn1, l3, l4, matrixdyn2, l5, l6);

	cout << endl << endl;
	cout << "matrix_na_vector" << endl;
	matrix_na_vector(vectdyn, matrixdyn1, l3, l4, vectdyn1, g1);

	cout << endl << endl;
	cout << "skalyar" << endl;

	skalyar(otvet, vectdyn1, g1, vectdyn2, g2);

	cout << endl << endl;
	cout << "vectornoe" << endl;

	vectornoe(matrixvectdyn, vectdyn1, g1, vectdyn2, g2, vectdyn);

	cin >> l4;
	return 0;

}