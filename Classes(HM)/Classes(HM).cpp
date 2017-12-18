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
	Matriza result;

	result.slozhenie(lhs, rhs, result);

	return result;
}

Matriza operator - (Matriza lhs,  
	Matriza rhs) 
{
	Matriza result;

	result.vychitanie(lhs, rhs, result);

	return result;
}

Matriza operator * (Matriza lhs,  
	Matriza rhs) 
{
	Matriza result;

	result.umnozhenie(lhs, rhs, result);

	return result;
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
	Matriza otvet;
	obj1.slozhenie(obj1, obj2, otvet);
	cout << otvet;
	system("pause");
}
