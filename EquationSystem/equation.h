#ifndef __EQUATION_H__
#define __EQUATION_H__

#include <iostream>

class Equation
{
	int size; //Количество уравнений
	double** matrix; //Матрица коэффициентов уравненеия
	double* eq; //Вектор коэффициентов, стоящих в правой части

	double* result;
public:
	Equation(int s)
	{
		//размеры
		size = s;
		//выделение памяти под матрицу
		matrix = new double*[size];
		for (int i = 0; i < size; i++)
			matrix[i] = new double[size];

		eq = new double[size];
		result = new double[size];

		//Заполнение нулями
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matrix[i][j] = 0;
			eq[i] = 0; //Еще и заодно вектор заполним нулями
		}
	}
	~Equation()
	{
		//Удаление памяти
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
