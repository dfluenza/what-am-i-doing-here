#pragma once
class Matrixx
{
public:

	Matrixx();
	Matrixx(int l1, int l2);

	~Matrixx();
	void matrix_slozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A);
	void vector_slozhenie(int **& B1, int g1, int **& B2, int g2, int **& B);
	void matrix_umnozhenie(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A);
	void matrix_na_vector(int **& A1, int l1, int l2, int **& B1, int g1, int **& B);
	void scalyarnoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int & C);
	void vectornoe_proizvedenie(int **& B1, int g1, int **& B2, int g2, int **& B);
	void vyvod_matrix(int **A, int l1, int l2);
	void vyvod_vector(int **B, int g1);

private:
	int l1;
	int l2;
	int ** A = new int *[l1];

	
};

