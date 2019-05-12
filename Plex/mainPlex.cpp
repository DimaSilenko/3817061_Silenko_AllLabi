#include "PlexLib.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int p1 = 0, p2 = 0;
	double rad;
	TPoint _p1, _p2, _p3(15, 25), _p4(1, 18), _p5;

	cout << "Введите первую точку:\n";
	cin >> p1 >> p2;

	cout << "Вы ввели точку _p1 с координатами:\n";
	_p1.SetX(p1);
	_p1.SetY(p2);
	_p1.show();

	cout << "Введите вторую точку:\n";
	cin >> p1 >> p2;

	cout << "Вы ввели точку _p2 с координатами:\n";
	_p2.SetX(p1);
	_p2.SetY(p2);
	_p2.show();

	cout << "Получили отрезок:\n";
	TSection AB(_p1, _p2);
	AB.show();
	cout << "\n\n\n";

	cout << "Точка _p4 по умолчанию с координатами:\n";
	_p4.show();

	cout << "Введите радиус круга:\n";
	cin >> rad;
	cout << "Получили круг:\n";
	TCircle cir(_p4, rad);
	cir.Show();

	cout << "\n\n\n";


	TPlex P, P1(&_p1, &_p2);
	TPlex P2(P1);

	cout << "Был создан плекс из точки _p1 и _p2\n";

	cout << "\nВ плекс добавлена точка (15, 25)\n";
	P2.Add(&_p1, &_p3);

	cout << "В плекс добавлена точка (1, 18)\n";
	P2.Add(&_p3, &_p4);

	cout << "В плекс добавлен введенный вами круг\n";
	P2.Add(&_p4, rad, &_p3);

	cout << "Введите точку:\n";
	cin >> p1 >> p2;

	cout << "В плекс добавлена введенная точка\n";
	_p5.SetX(p1);
	_p5.SetY(p2);

	cout << "\n\n\n";

	P2.Add(&_p2, &_p5);
	cout << "Получился плекс: \n";

	P2.Show();
	cout << "\n\n\n";

	return 0;
}
