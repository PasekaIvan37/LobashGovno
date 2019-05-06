#ifndef __EQUATION_H__
#define __EQUATION_H__

#include <iostream>

class Equation
{
	int size; //���������� ���������
	double** matrix; //������� ������������� ����������
	double* eq; //������ �������������, ������� � ������ �����

	double* result;
public:
	Equation(int s)
	{
		//�������
		size = s;
		//��������� ������ ��� �������
		matrix = new double*[size];
		for (int i = 0; i < size; i++)
			matrix[i] = new double[size];

		eq = new double[size];
		result = new double[size];

		//���������� ������
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matrix[i][j] = 0;
			eq[i] = 0; //��� � ������ ������ �������� ������
		}
	}
	~Equation()
	{
		//�������� ������
		for (int i = 0; i < size; i++)
			delete[] matrix[i];

		delete[] matrix;
		delete[] eq;
		delete[] result;
	}
	void ReadFromConsole();
	void ReadFromArray(const double** arr, const double* e);
	double* Solve();
	void Print();

};

#endif 
