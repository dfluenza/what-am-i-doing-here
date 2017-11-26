#pragma once
class Vector
{
	int g2;
	int ** B = new int *[1];

public:
	Vector();
	Vector(int **B1, int g1);

	void vyvod_vector(int **B, int g1);
	void scalyarnoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int & C);
	void vectornoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int **& B);

	~Vector();
};