// Automat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tmplt.h"
#include <iostream>



int main()
{
	Matriz <int> a;
	Matriz <int> b;
	Matriz <int> c (1, 1);

	c = a + b;
	cout << "Result of sum: " << c;

	c = a * b;
	cout << "Result of multiplication: " << c;

	c = a - b;
	cout << "Result of subtraction: " << c;


	system("pause");
	return 0;
}