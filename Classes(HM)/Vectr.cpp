#include "stdafx.h"
#include "Vectr.h"
#include <iostream>

using namespace std;

void Vectr::vectornoe_proizvedenie(Vectr obj1, Vectr obj2, Vectr obj3) //векторное произведение двух векторов
{	
	int g1 = obj1.l2;
	int g2 = obj2.l2;
	if (g1 != 3 || g2 != 3) { cout << "Idi uchi matan; mozhno umnozhat' tol'ko trehmernye vectory" << endl; }
	else {
		if (g1 == g2)
		{
			for (int i = 0; i < g1; i++)
			{
				obj3.B1[0][i] = obj1.B1[0][(i + 1) % 3] * obj2.B1[0][(i + 2) % 3] - obj1.B1[0][(i + 2) % 3] * obj2.B1[0][(i + 2) % 3];

			}
		}
		else { cout << "Idi uchi matan; mozhno umnozhat' tol'ko ravnye vectory" << endl; }
	}
}

Vectr::Vectr()
{
}


Vectr::~Vectr()
{
}
