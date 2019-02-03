#include "Polynomial.h"
#include <ctime>

int main() 
{
	setlocale(LC_ALL, "Russian");
	try
	{
		cout << "Создадим мономы, состоящие из трех переменных, с которыми будем работать и на их основе составим полиномы:\n";

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

		cout << "1) Первый моном: " << mon1 << endl;
		cout << "2) Второй моном: " << mon2 << endl;
		cout << "3) Третий моном: " << mon3 << endl;
		cout << "4) Четвертый моном: " << mon4 << endl;
		cout << "5) Пятый моном: " << mon5 << endl;
		cout << "6) Шестой моном: " << mon6 << endl;


		TPolynom pol1(3);
		pol1 += mon1;
		pol1 += mon2;
		pol1 += mon3;
		cout << "\nI) Первый полином, составленный из 1), 2) и 3) мономов = " << pol1 << endl;

		TPolynom pol2(3);
		pol2 += mon4;
		pol2 += mon5;
		pol2 += mon6;
		cout << "II) Второй полином, составленный из 4), 5) и 6) мономов = " << pol2 << endl;

		cout << "\nТеперь проведем несколько стандартных арифметических операций:\n";

		TPolynom respol(3);

		respol = pol1 + pol2;
		cout << "Сумма полиномов I) и II):\n" << respol << endl;

		respol = pol1 - pol2;
		cout << "\nРазность полиномов I) и II)\n" << respol << endl;

		respol = pol1 * pol2;
		cout << "\nПроизведение полиномов I) и II)\n" << respol << endl;

		cout << "\nРассмотрим полином, полученный операцией умножения поподробнее:\n";

		cout << "Он состоит из " << respol.GetSize() << " мономов\n";

		cout << "Первый из которых: " << *respol.GetBegin() << endl;

		cout << "Сравним его с полиномом I): ";
		if (respol == pol1)
			cout << "Полиномы равны";
		else
			cout << "Полинмы не равны";

		respol = pol2;
		cout << "\nПриравняв этот полином к II), мы получим: " << respol << endl;
	}

	catch (Exception exp)
	{
		exp.Print();
	}
 return 0;
}
