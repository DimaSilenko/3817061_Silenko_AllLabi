#include "Polynomial.h"
#include <ctime>

int main() 
{
	setlocale(LC_ALL, "Russian");
	try
	{
		cout << "�������� ������, ��������� �� ���� ����������, � �������� ����� �������� � �� �� ������ �������� ��������:\n";

		int deg1[] = { 3, 4, 5 };
		int deg2[] = { 8, 0, 4 };
		int deg3[] = { 1, 1, 1 };
		int deg4[] = { 16, 17, 18 };
		int deg5[] = { 6, 3, 0 };
		int deg6[] = { 3, 4, 5 };

		TMonom mon1(3, deg1, 9);
		TMonom mon2(3, deg2, 7);
		TMonom mon3(3, deg3, 1);
		TMonom mon4(3, deg4, 0);
		TMonom mon5(3, deg5, 4);
		TMonom mon6(3, deg6, 5);

		cout << "1) ������ �����: " << mon1 << endl;
		cout << "2) ������ �����: " << mon2 << endl;
		cout << "3) ������ �����: " << mon3 << endl;
		cout << "4) ��������� �����: " << mon4 << endl;
		cout << "5) ����� �����: " << mon5 << endl;
		cout << "6) ������ �����: " << mon6 << endl;


		TPolynom pol1(3);
		pol1 += mon1;
		pol1 += mon2;
		pol1 += mon3;
		cout << "\nI) ������ �������, ������������ �� 1), 2) � 3) ������� = " << pol1 << endl;

		TPolynom pol2(3);
		pol2 += mon4;
		pol2 += mon5;
		pol2 += mon6;
		cout << "II) ������ �������, ������������ �� 4), 5) � 6) ������� = " << pol2 << endl;

		cout << "\n������ �������� ��������� ����������� �������������� ��������:\n";

		TPolynom respol(3);

		respol = pol1 + pol2;
		cout << "����� ��������� I) � II):\n" << respol << endl;

		respol = pol1 - pol2;
		cout << "\n�������� ��������� I) � II)\n" << respol << endl;

		respol = pol1 * pol2;
		cout << "\n������������ ��������� I) � II)\n" << respol << endl;

		cout << "\n���������� �������, ���������� ��������� ��������� �����������:\n";

		cout << "�� ������� �� " << respol.GetSize() << " �������\n";

		cout << "������ �� �������: " << *respol.GetBegin() << endl;

		cout << "������� ��� � ��������� I): ";
		if (respol == pol1)
			cout << "�������� �����";
		else
			cout << "������� �� �����";

		respol = pol2;
		cout << "\n��������� ���� ������� � II), �� �������: " << respol << endl;
	}

	catch (Exception exp)
	{
		exp.Print();
	}
 return 0;
}
