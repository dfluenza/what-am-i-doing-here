// Classes(HM).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matriza.h"
#include "Vectr.h"
#include <iostream>

using namespace std;

int main()
{


	int l3 = 3;
	int l4 = 3;
	int ** A = new int *[l3];
	for (int i = 0; i < l3; i++)
	{
		A[i] = new int[l4];

	}
	for (int i = 0; i < l3; i++) {
		for (int j = 0; j < l4; j++)
		{
			A[i][j] = 1;
		}
	}

	int g1 = 5;

	int ** B = new int *[1];

	for (int i = 0; i < 1; i++)
	{
		B[i] = new int[g1];

	}

	int ** B1 = new int *[1];

	for (int i = 0; i < 1; i++)
	{
		B1[i] = new int[g1];

	}


	///*Matrix Matr1;
	//Matrix Otvet;
	//Matrix Matr2;
	//Matr1.vyvod_mat(Matr1);
	//Matr2.vyvod_mat(Matr2);
	//Matr1.matrix_umnozh(Matr1, Matr2, Otvet);
	//Matr1.matrix_slozh(Matr1, Matr2, Otvet);*/

	////Vector Vect1(vect1Dyn, g1);
	//Vectr obj2;
	//Vectr otvet;
	////Vect1.vyvod_mat(Vect1);

	//obj3.vyvod(obj3);
	//cout << "Slozh: ";
	////Vect1.matrix_slozh(Vect1, Vect2, Otvet1);
	//cout << "Umnozh: ";
	////Vect2.vect_vect(Vect1, Vect2, Otvet1);

	//system("pause");

	//return 0;
}

//
//#include "stdafx.h"
//#include "Matrix.h"
//#include "Vector.h"
//
//Matrix operator + (Matrix lhs,  //left hand side
//	Matrix rhs) //right hand side
//{
//	Matrix result;
//
//	result.matrix_slozh(lhs, rhs, result);
//
//	return result;
//}
//
//Matrix operator - (Matrix lhs,  //left hand side
//	Matrix rhs) //right hand side
//{
//	Matrix result;
//
//	result.matrix_vych(lhs, rhs, result);
//
//	return result;
//}
//
//Matrix operator * (Matrix lhs,  //left hand side
//	Matrix rhs) //right hand side
//{
//	Matrix result;
//
//	result.matrix_umnozh(lhs, rhs, result);
//
//	return result;
//}
//
//ostream & operator << (ostream & os, //левосторонний оператор, cout
//	Matrix & rhs) //правосторонний оператор, собственно то, что выводится
//{
//	rhs.vyvod_mat(rhs);
//	return os;
//}