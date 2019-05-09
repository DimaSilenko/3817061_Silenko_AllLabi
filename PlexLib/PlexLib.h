#pragma once
#include "PointLib.h"
#include "SectionLib.h"
#include "ExceptionLib.h"
#include <iostream>
#include <locale>

using namespace std;


class TPlex: public TPoint
{
protected:
  TPoint *l, *r;										//Указатели на левую и правую точки плекса

public:
	TPlex();
	TPlex(TPoint *_l, TPoint *_r);
	TPlex(TPlex& plex);

  void SetL (TPoint *_l);						//Задать левую точку плекса
  void SetR (TPoint *_r);						//Задать правую точку плекса
  TPoint* GetL();										//Получить левую точку плекса
  TPoint* GetR();										//Прлучить правую точку плекса

	virtual void show();							//Вывести плекс на экран

  void Add (TPoint *_point1, TPoint *_point2);	//Добавить точку в плекс
	TPoint* Search(TPoint *point);					//Найти точку в плексе

};

//-------------------------------------------------------------------------------------------------
TPlex::TPlex()
{
	l = NULL;
	r = NULL;
}

//-------------------------------------------------------------------------------------------------
TPlex::TPlex(TPoint *_l, TPoint *_r)
{
	l = _l;
	r = _r;
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
void TPlex::Add(TPoint* point1, TPoint* point2)
{
	TPlex *pl, *pr;
	TPoint* res;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	try
	{
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
	catch (...)
	{
		cout << "Точка не найдена\n";
	}

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
	if ((pr == NULL)&&(pl == NULL))
		return NULL;
}

//-------------------------------------------------------------------------------------------------
void TPlex::show()
{
	TPlex *pl, *pr;
	cout<<"Отрезок\n";
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (pl != 0)
	{
		cout<<"Слева ";
		pl->show();
	}
	else if (pl == 0)
	{
		cout<<"Слева Tочка:\n";
		l->show();
	}
	if (pr != 0)
	{
		cout<<"Справа ";
		pr->show();
	}
	else if (pr == 0)
	{
		cout<<"Справа Tочка:\n";
		r->show();
	}
}