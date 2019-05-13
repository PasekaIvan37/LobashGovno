#include "equation.h"

void Equation::ReadFromArray(const double** arr, const double* e)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			matrix[i][j] = arr[i][j];

		eq[i] = e[i];
	}
}

void Equation::ReadFromConsole()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << "a[" << i << "][" << j << "]= ";
			std::cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << "y[" << i << "]= ";
		std::cin >> eq[i];
	}
}

double* Equation::Solve()
{
	double *x, max;
	int k, index;
	const double eps = 0.00001;  // точность
	x = new double[size];
	k = 0;
	while (k < size)
	{
		// Поиск строки с максимальным a[i][k]
		max = abs(matrix[k][k]);
		index = k;
		for (int i = k + 1; i < size; i++)
		{
			if (abs(matrix[i][k]) > max)
			{
				max = abs(matrix[i][k]);
				index = i;
			}
		}

		if (max < eps)
		{
			std::cout << "Решение получить невозможно из-за нулевого столбца ";
			std::cout << index << " матрицы коэффициентов" << std::endl;
			return 0;
		}
		for (int j = 0; j < size; j++)
		{
			double temp = matrix[k][j];
			matrix[k][j] = matrix[index][j];
			matrix[index][j] = temp;
		}
		double temp = eq[k];
		eq[k] = eq[index];
		eq[index] = temp;
		// Нормализация уравнений
		for (int i = k; i < size; i++)
		{
			double temp = matrix[i][k];
			if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
			for (int j = 0; j < size; j++)
				matrix[i][j] = matrix[i][j] / temp;
			eq[i] = eq[i] / temp;
			if (i == k)  continue; // уравнение не вычитать само из себя
			for (int j = 0; j < size; j++)
				matrix[i][j] = matrix[i][j] - matrix[k][j];
			eq[i] = eq[i] - eq[k];
		}
		k++;
	}
	// обратная подстановка
	for (k = size - 1; k >= 0; k--)
	{
		x[k] = eq[k];
		for (int i = 0; i < k; i++)
			eq[i] = eq[i] - matrix[i][k] * x[k];
	}
	return x;
}

void Equation::Print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << "*x" << j;
			if (j < size - 1)
				std::cout << " + ";
		}
		std::cout << " = " << eq[i] << std::endl;
	}
}