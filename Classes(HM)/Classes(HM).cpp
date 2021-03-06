// Classes(HM).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matriza.h"
#include "Vectr.h"
#include <iostream>

using namespace std;


Matriza operator + (Matriza lhs,  
	Matriza rhs) 
{
	Matriza result (1, 1);
	return result.slozhenie(lhs, rhs);
}

Matriza operator - (Matriza lhs,  
	Matriza rhs) 
{
	Matriza result (1, 1);

	return result.vychitanie(lhs, rhs);

}

Matriza operator * (Matriza lhs,  
	Matriza rhs) 
{
	Matriza result (1, 1);

return result.umnozhenie(lhs, rhs);
}

ostream & operator << (ostream & os, 
	Matriza & rhs) 
{
	rhs.vyvod(rhs);
	return os;
}

int main()
{
	Matriza obj1;
	Matriza obj2;
	
	for (int i = 0; i < obj1.ll1; i++)
	{
		for (int j = 0; j < obj1.ll2; j++)
		{
			obj1.A[i][j] = 2;
		}
	}
	for (int i = 0; i < obj2.ll1; i++)
	{
		for (int j = 0; j < obj2.ll2; j++)
		{
			obj2.A[i][j] = 4;
		}
	}
	cout << "Multiply" << (obj1 * obj2);
	cout << "Sum" << (obj1 + obj2);
	cout << "Diff" << (obj1 - obj2);
	system("pause");

	return 0;
}
