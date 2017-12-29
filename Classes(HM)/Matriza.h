#pragma once
class Matriza
{
private:
	int l1;
	int l2;
	

public:
	int ** A;
	int ll1;
	int ll2;
	Matriza();
	Matriza (int l1, int l2);
	Matriza(int **A, int l3, int l4);
	Matriza umnozhenie(Matriza obj1, Matriza obj2);
	Matriza slozhenie(Matriza obj1, Matriza obj2);
	Matriza vychitanie(Matriza obj1, Matriza obj2);
	void vyvod(Matriza obj3);

	~Matriza();
};

