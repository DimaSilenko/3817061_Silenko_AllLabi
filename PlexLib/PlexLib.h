#pragma once
#include "PointLib.h"
#include "SectionLib.h"
#include "CircleLib.h"
#include "ExceptionLib.h"
#include <iostream>
#include <locale>

using namespace std;


class TPlex : public TPoint
{
protected:
	TPoint *l, *r;										//��������� �� ����� � ������ ����� ������
	double rad;

public:
	TPlex();
	TPlex(TPoint *_l, TPoint *_r);
	TPlex(TPlex& plex);

	void SetL(TPoint *_l);						//������ ����� ����� ������
	void SetR(TPoint *_r);						//������ ������ ����� ������
	void SetRad(double _rad);
	TPoint* GetL();										//�������� ����� ����� ������
	TPoint* GetR();										//�������� ������ ����� ������
	double GetRad();

	virtual void Show();							//������� ����� �� �����

	void Add(TPoint *_point1, TPoint *_point2);	//�������� ����� � �����
	void Add(TPoint *mid, double rad, TPoint *point);
	TPoint* Search(TPoint *point);					//����� ����� � ������

};

//-------------------------------------------------------------------------------------------------
TPlex::TPlex()
{
	l = NULL;
	r = NULL;
	rad = 0;
}

//-------------------------------------------------------------------------------------------------
TPlex::TPlex(TPoint *_l, TPoint *_r)
{
	l = _l;
	r = _r;
	rad = 0;
}

//-------------------------------------------------------------------------------------------------
TPlex::TPlex(TPlex& plex)
{
	TPlex *pl, *pr;
	pl = dynamic_cast <TPlex*> (plex.l);
	pr = dynamic_cast <TPlex*> (plex.r);
	if (pl != 0)
		l = new TPlex(*pl);
	else
		l = new TPoint(*(plex.GetL()));
	if (pr != 0)
		r = new TPlex(*pr);
	else
		r = new TPoint(*(plex.GetR()));
}

//------------------------------------------------------------------------------------------------
void TPlex::SetL(TPoint* _l)
{
	l = _l;
}

//-------------------------------------------------------------------------------------------------
void TPlex::SetR(TPoint* _r)
{
	r = _r;
}

//-------------------------------------------------------------------------------------------------
void TPlex::SetRad(double _rad)
{
	rad = _rad;
}

//-------------------------------------------------------------------------------------------------
TPoint* TPlex::GetL()
{
	return l;
}

//-------------------------------------------------------------------------------------------------
TPoint* TPlex::GetR()
{
	return r;
}

//-------------------------------------------------------------------------------------------------
double TPlex::GetRad()
{
	return rad;
}

//-------------------------------------------------------------------------------------------------
void TPlex::Add(TPoint* point1, TPoint* point2)
{
	TPlex *pl, *pr;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);

	if ((pl == 0) && ((*l == *point1) || (*l == *point2)))
	{
		l = new TPlex(point1, point2);
	}
	else if ((pr == 0) && ((*r == *point1) || (*r == *point2)))
	{
		r = new TPlex(point1, point2);
	}
	else if (pl != 0)
	{
		pl->Add(point1, point2);
	}
	else if (pr != 0)
	{
		pr->Add(point1, point2);
	}
	else
		throw Exception("Error not found");
}

//-------------------------------------------------------------------------------------------------
void TPlex::Add(TPoint *mid, double _rad, TPoint *point)
{
	TPlex *pl, *pr;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);

	if ((pl == 0) && ((*l == *mid) || (*l == *point)))
	{
		l = new TPlex(mid, point);
		SetRad(_rad);
	}
	else if ((pr == 0) && ((*r == *mid) || (*r == *point)))
	{
		r = new TPlex(mid, point);
		SetRad(_rad);
	}
	else if (pl != 0)
	{
		pl->Add(mid, _rad, point);
	}
	else if (pr != 0)
	{
		pr->Add(mid, _rad, point);
	}
	else
		throw Exception("Error not found");
}

//-------------------------------------------------------------------------------------------------
TPoint* TPlex::Search(TPoint *point)
{
	TPlex *pl, *pr;
	TPoint* res;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (*l == *point)
		return l;
	else if (pl != NULL)
	{
		res = pl->Search(point);
		if (res != NULL)
			return res;
	}
	if (*r == *point)
		return r;
	else if (pr != NULL)
	{
		pr->Search(point);
		if (res != NULL)
			return res;
	}
	if ((pr == NULL) && (pl == NULL))
		return NULL;
}

//-------------------------------------------------------------------------------------------------
void TPlex::Show()
{
	TPlex *pl, *pr;
	cout << "�������\n";
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (pl != 0)
	{
		cout << "����� ";
		pl->Show();
	}
	else if (pl == 0)
	{
		if (GetRad() == 0)
		{
			cout << "����� T����:\n";
			l->show();
		}
		else
		{
			cout << "����� ����:\n";
			TCircle c(*l, GetRad());
			c.Show();
		}
	}
	if (pr != 0)
	{
		cout << "������ ";
		pr->Show();
	}
	else if (pr == 0)
	{
		if (GetRad() == 0)
		{
			cout << "������ T����:\n";
			r->show();
		}
		else
		{
			cout << "������ ����:\n";
			TCircle c(*r, GetRad());
			c.Show();
		}
	}
}