// Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrixx.h"
#include "Vector.h"

int main()
{	int l3 = 3;
	int l4 = 3;
	
	int ** A = new int *[l3]; 
	for (int i = 0; i < l3; i++)
	{
		A[i] = new int[l4];
	}
	Matrixx Matrix1(A, l3, l4);
	Matrixx Matrix2();

	system("pause");
	return 0;
}

