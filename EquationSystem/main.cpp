#include "equation.h"

//������ main'�
int main()
{
	int dim;
	std::cout << "Enter equations count:\n";
	std::cin >> dim;

	Equation eq(dim);
	//����
	eq.ReadFromConsole();
	double* res = eq.Solve();

	std::cout << "Equation system solvation:\n";
	for (int i = 0; i < dim; i++)
	{
		
		std::cout << "x" << i << ": " << res[i] << "\n";
	}

	system("pause");

	return 0;
}