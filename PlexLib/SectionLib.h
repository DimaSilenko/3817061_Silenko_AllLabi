#pragma once
#include <iostream>

using namespace std;


class TSection
{
protected:
	TPoint point1, point2;									//Точки на концах отрезка

public:
	TSection(TPoint _point1, TPoint _point2);
	TSection(TSection &sect);

	void SetPoint1(TPoint _point1);			//Задать первую точку
	void SetPoint2(TPoint _point2);			//Задать вторую точку

	TPoint GetPoint1();									//Получить первую точку
	TPoint GetPoint2();									//Получить вторую точку

	virtual void show();								//Вывести отрезок на экран

};

//-------------------------------------------------------------------------------------------------
TSection::TSection(TPoint _point1, TPoint _point2)
{
	point1 = _point1;
	point2 = _point2;
}

//-------------------------------------------------------------------------------------------------
TSection::TSection(TSection &sect)
{
	point1 = sect.point1;
	point2 = sect.point2;
}


//-------------------------------------------------------------------------------------------------
void TSection::SetPoint1(TPoint _point1)
{
	point1 = _point1;
}

//-------------------------------------------------------------------------------------------------
void TSection::SetPoint2(TPoint _point2)
{
	point2 = _point2;
}

//-------------------------------------------------------------------------------------------------
TPoint TSection::GetPoint1()
{
	return point1;
}

//-------------------------------------------------------------------------------------------------
TPoint TSection::GetPoint2()
{
	return point2;
}

//-------------------------------------------------------------------------------------------------
void TSection::show()
{
	cout << "(" << point1.GetX() << "," << point1.GetY() << ")\n" << "(" << point2.GetX() << "," << point2.GetY() << ")\n";
}
