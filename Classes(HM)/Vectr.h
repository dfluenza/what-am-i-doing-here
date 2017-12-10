#pragma once
#include "Matriza.h"

class Vectr : public Matriza
{
private:

	int l1 = 1;
	int l2;
	int ** B1;

public:

	//Vectr(int **B1, int g1);

	//Vector();

	void vectornoe_proizvedenie(Vectr B1, Vectr B2, Vectr B);

	~Vectr();
};

