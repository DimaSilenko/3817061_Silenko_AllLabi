#pragma once
#include <iostream>
#include "PointLib.h"

using namespace std;

class TCircle
{
protected:
	TPoint mid;							//����� �����
	double r;								//������ �����

public:
	TCircle(TPoint _mid, double _r);
	TCircle(TCircle &circle);

	void SetMid(TPoint _mid);						//������ ����� �����
	void SetRadius(double _r);					//������ ������ �����

	TPoint GetMid();										//�������� ����� �����
	double GetRadius();									//�������� ������ �����

	virtual void Show();								//������� ���� �� �����

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
	cout << "�����: (" << mid.GetX() << "," << mid.GetY() << ")\n" << "������: " << GetRadius() << "\n";
}