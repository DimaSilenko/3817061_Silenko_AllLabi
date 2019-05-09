#include "Vector.h"
#include <cstdlib>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(static_cast<unsigned int>(time(0)));
	double ra, nd, om;

	cout << "Вектора:\n";
	TVector <int> V1(3), V2(3), Res(3);
	for (int i = 0; i < 3; i++)
	{
    ra = rand();
		nd = ra / RAND_MAX;
		om = nd * 49 + 1;

		V1[i] = om;

		ra = rand();
		nd = ra / RAND_MAX;
		om = nd * 49 + 1;

		V2[i] = om;
	}

	cout << "\nВектор 1: " << V1 << endl;
	cout << "Вектор 2: " << V2 << endl;

	cout << "\n\nРезультаты арифмитеческих операций:\n\n";
	try
	{
		Res = V1 + 5;
		cout << "Вектор 1 + 5: " << Res << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	try
	{
		Res = V1 - 6;
		cout << "Вектор 1 - 6: " << Res << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	try
	{
		Res = V1 * 7;
		cout << "Вектор 1 * 7: " << Res << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	try
	{
		Res = V1 + V2;
		cout << "Вектор 1 + Вектор 2: " << Res << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	try
	{
		Res = V1 - V2;
		cout << "Вектор 1 - Вектор 2: " << Res << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	try
	{
		int k = V1 * V2;
		cout << "Вектор 1 * Вектор 2: " << k << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	cout << "\n\nВведите вектор, размерности 5:\n";
	TVector <int> V(5);
	cin >> V;
	cout << "\nВведенный вами вектор: " << V << endl;
	return 0;
}