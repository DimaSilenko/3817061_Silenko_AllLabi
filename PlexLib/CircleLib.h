#pragma once
#include <iostream>
#include "PointLib.h"

using namespace std;

class TCircle
{
protected:
	TPoint mid;							//Центр круга
	double r;								//Радиус круга

public:
	TCircle(TPoint _mid, double _r);
	TCircle(TCircle &circle);

	void SetMid(TPoint _mid);						//Задать центр круга
	void SetRadius(double _r);					//Задать радиус круга

	TPoint GetMid();										//Получить центр круга
	double GetRadius();									//Получить радиус круга

	virtual void Show();								//Вывести круг на экран

};

//-------------------------------------------------------------------------------------------------
TCircle::TCircle(TPoint _mid, double _r)
{
	mid = _mid;
	r = _r;
}

//-------------------------------------------------------------------------------------------------
TCircle::TCircle(TCircle &circle)
{
	mid = circle.mid;
	r = circle.r;
}


//-------------------------------------------------------------------------------------------------
void TCircle::SetMid(TPoint _mid)
{
	mid = _mid;
}

//-------------------------------------------------------------------------------------------------
void TCircle::SetRadius(double _r)
{
	r = _r;
}

//-------------------------------------------------------------------------------------------------
TPoint TCircle::GetMid()
{
	return mid;
}

//-------------------------------------------------------------------------------------------------
double TCircle::GetRadius()
{
	return r;
}

//-------------------------------------------------------------------------------------------------
void TCircle::Show()
{
	cout << "Центр: (" << mid.GetX() << "," << mid.GetY() << ")\n" << "Радиус: " << GetRadius() << "\n";
}