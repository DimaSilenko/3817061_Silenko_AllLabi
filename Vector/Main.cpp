#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double n;
	TVector<int> ivec1;
	int vec1[3] = { 2, 4, 6 };
	TVector<int> ivec2(vec1, 3);
	cout << "Стандартный целочисленный вектор:\n" << ivec2;
	TVector<int> ivec3(ivec2);
	int vec[3] = { 1, 3, 5 };
	TVector<int> ivec(vec, 3);
	int tmp;
	try
	{
		ivec3 = ivec2 + ivec;
		cout << "Сложение:\n" << ivec3 << "\n";
	}
	catch (int err)
	{
		if (err == 1)
		{
			cout << "Несовпадение длин векторов, выполнить операцию невозможно\n";
		}
	}
	
	ivec3 = ivec2 - ivec;
	cout << "Вычитание:\n" << ivec3 << "\n";

	tmp = ivec2 * ivec;
	cout << "Умножение скалярное:\n" << tmp << "\n";
	cout << "Аналогичный результат с числом 5\n";
	n = 5;
	ivec3 = ivec2 * n;
	cout << "Умножение на число:\n" << ivec3 << "\n";
	ivec3 = ivec2 / n;
	cout << "Деление на число:\n" << ivec3 << "\n";

	float fvec[3] = { 1.1, 2.4, 3.4 };
	TVector<float> fvec1(fvec, 3);
	cout << "Стандартный вещественный вектор:\n" << fvec1;
	float fvect[3] = { 2.1, 2.4, 2.5 };
	TVector<float> fvec2(fvect, 3);

	try
	{
		TVector<float> sum;
		sum = fvec1 + fvec2;
		cout << "Сумма двух вещественных векторов:\n" << sum << "\n";
	}
	catch (int err)
	{
		if (err == 1)
		{
			cout << "Несовпадение длин векторов, выполнить операцию невозможно\n";
		}
	}
	//TVector<float> fvec3;
	//cout << "Введите вещественный вектор\n";
	//cin >> fvec3;
	//cout << "Его длина = " << fvec3.Lenght(fvec3) << "\n";
	//fvec3 = fvec3.Izm();
	//cout << "Теперь это вектор:\n" << fvec3;
	//fvec3.Del();

	return 0;
}