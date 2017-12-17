#pragma once
class Matriza
{
private:
	int l1;
	int l2;
	int ** A = new int *[l1];

public:
	Matriza();
	Matriza(int **A, int l3, int l4);
	void umnozhenie(Matriza matr1, Matriza matr2, Matriza matr3);
	void slozhenie(Matriza obj1, Matriza obj2, Matriza obj3);
	void vychitanie(Matriza obj1, Matriza obj2, Matriza obj3);
	void vyvod(Matriza obj3);

	~Matriza();
};

