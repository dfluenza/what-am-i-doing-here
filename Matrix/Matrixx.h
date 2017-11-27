#pragma once

#include <iostream>
using namespace std;

class Matrixx
{
private:

	int l3;
	int l4;
	int ** A = new int *[l3];

public:
	Matrixx();
	Matrixx(int **A, int l3, int l4);

	void matrix_slozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A);
	void matrix_umnozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A);
	void vyvod_matrix(int **A, int l3, int l4);
	~Matrixx();

};
