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
	cout << "����������� ������������� ������:\n" << ivec2;
	TVector<int> ivec3(ivec2);
met1:

	cout << "������� ������������� ������ � � ������� �������� ���������� ��������� �������������� ��������\n";
	cin >> ivec1;
	try
	{
		cout << "��������:\n" << ivec3 + ivec1 << "\n";
	}
	catch (int err)
	{
		if (err == 1)
		{
			cout << "������������ ���� ��������, ��������� �������� ����������\n";
			goto met1;
		}
	}
	cout << "���������:\n" << ivec3 - ivec1 << "\n";
	cout << "��������� ���������:\n" << ivec3 * ivec1 << "\n";
	cout << "������� ����� � ���������� �� ����������� ���������\n";
	cin >> n;
	cout << "��������� �� �����:\n" << ivec3 * n << "\n";
	cout << "������� �� �����:\n" << ivec3 / n << "\n";

	float fvec[3] = { 1.1, 2.4, 3.4 };
	TVector<float> fvec1(fvec, 3);
	cout << "����������� ������������ ������:\n" << fvec1;
	TVector<float> fvec2;

met2:
	cout << "������� ������������ ������\n";
	cin >> fvec2;
	try
	{
		TVector<float> sum;
		sum = fvec1 + fvec2;
		cout << "����� ���� ������������ ��������:\n" << sum << "\n";
	}
	catch (int err)
	{
		if (err == 1)
		{
			cout << "������������ ���� ��������, ��������� �������� ����������\n";
			goto met2;
		}
	}
	TVector<float> fvec3;
	cout << "������� ������������ ������\n";
	cin >> fvec3;
	cout << "��� ����� = " << fvec3.Lenght(fvec3) << "\n";
	fvec3 = fvec3.Izm();
	cout << "������ ��� ������:\n" << fvec3;
	fvec3.Del();

}