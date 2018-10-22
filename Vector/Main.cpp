#include "Vector.h"
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	double n;
	TVector<int> ivec1;
	int vec1[3] = { 2, 4, 6 };
	TVector<int> ivec2(vec1, 3);
	cout << "Стандартный целочисленный вектор:\n" << ivec2;
	TVector<int> ivec3(ivec2);
met1:

	cout << "Введите целочисленный вектор и с базовым вектором произойдут некоторые арифметические операции\n";
	cin >> ivec1;
	try
	{
		cout << "Сложение:\n" << ivec3 + ivec1 << "\n";
	}
	catch (int err)
	{
		if (err == 1)
		{
			cout << "Несовпадение длин векторов, выполнить операцию невозможно\n";
			goto met1;
		}
	}
	cout << "Вычитание:\n" << ivec3 - ivec1 << "\n";
	cout << "Умножение скалярное:\n" << ivec3 * ivec1 << "\n";
	cout << "Введите число и посмотрите на аналогичный результат\n";
	cin >> n;
	cout << "Умножение на число:\n" << ivec3 * n << "\n";
	cout << "Деление на число:\n" << ivec3 / n << "\n";

	float fvec[3] = { 1.1, 2.4, 3.4 };
	TVector<float> fvec1(fvec, 3);
	cout << "Стандартный вещественный вектор:\n" << fvec1;
	TVector<float> fvec2;

met2:
	cout << "Введите вещественный вектор\n";
	cin >> fvec2;
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
			goto met2;
		}
	}
	TVector<float> fvec3;
	cout << "Введите вещественный вектор\n";
	cin >> fvec3;
	cout << "Его длина = " << fvec3.Lenght(fvec3) << "\n";
	fvec3 = fvec3.Izm();
	cout << "Теперь это вектор:\n" << fvec3;
	fvec3.Del();

}