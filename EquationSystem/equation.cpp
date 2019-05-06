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
	//TODO
	//Реализовать считывание из консоли
}

double* Equation::Solve()
{
	//TODO
	//Решение уравнения методом Гаусса

	//Для matrix и eq

	//Это просто какой-то массив, заполненный цифрами, чисто для того, чтоб собиралось
	//Этот кусок надо будет удалить и положить в result результат решения уравнения и его же вернуть через return
	double* res = new double[size];
	for (int i = 0; i < size; i++)
		res[i] = i;

	result = res;
	return res;
}

void Equation::Print()
{
	std::cout << "Simple text to console" << std::endl;
}