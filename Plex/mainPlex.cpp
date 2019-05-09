
#include "PlexLib.h"
#include <iostream>
#include <locale>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	int p1 = 0, p2 = 0;
	TPoint _p1, _p2, _p3(15, 25), _p4(1, 18), _p5;

	cout << "������� ������ �����:\n";
	cin >> p1 >> p2;

	cout << "�� ����� ����� _p1 � ������������:\n";
	_p1.SetX(p1);
	_p1.SetY(p2);
	_p1.show();

	cout << "������� ������ �����:\n";
	cin >> p1 >> p2;

	cout << "�� ����� ����� _p2 � ������������:\n";
	_p2.SetX(p1);
	_p2.SetY(p2);
	_p2.show();

	cout << "�������� �������:\n";
	TSection AB(_p1, _p2);
	AB.show();
	cout << "\n\n\n";

	cout << "����� _p3 �� ��������� � ������������:\n";
	_p3.show();
	cout << "\n\n\n";


	TPlex P, P1(&_p1, &_p2);
	TPlex P2(P1);

	cout << "��� ������ ����� �� ����� _p1 � _p2\n";

	cout << "\n� ����� ��������� ����� (15, 25)\n";
	P2.Add(&_p1, &_p3);

	cout << "� ����� ��������� ����� (1, 18)\n";
	P2.Add(&_p3, &_p4);

	cout << "������� �����:\n";
	cin >> p1 >> p2;

	cout << "� ����� ��������� ��������� �����\n";
	_p5.SetX(p1);
	_p5.SetY(p2);

	P2.Add(&_p2, &_p5);
	cout << "��������� �����: \n";

	P2.show();
	cout << "\n\n\n";
}
