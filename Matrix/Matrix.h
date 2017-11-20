#pragma once
class Matrix
{
public:
	Matrix();

	//все математические функции становятся методами класса

private:
	int ** m_array; //сама матрица или вектор
public:
	int m; //размерность матрицы/вектора
	int n; //размеры метрицы/вектора
private:
	~Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] m_array[i];
		}
		delete[] m_array;
	};
};

