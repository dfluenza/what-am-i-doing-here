#pragma once
class Matrix
{
public:
	Matrix();

	//��� �������������� ������� ���������� �������� ������

private:
	int ** m_array; //���� ������� ��� ������
public:
	int m; //����������� �������/�������
	int n; //������� �������/�������
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

