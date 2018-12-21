#include <iostream>
#include "ExceptionLib.h"

class TMonom
{
protected:
	unsigned* deg;//Степени
	int size;//Кол-во переменных
	double koef;// Коэффициент
  TMonom* next;//Указатель на следующий

public:
	TMonom() :size(0) { next = 0; deg = 0; koef = 0; }
  TMonom(int _size, unsigned* _deg, double koef);
	TMonom(TMonom& Monom);
  virtual ~TMonom();

	void SetNext(TMonom* _next);//Задать указатель на следующий
	void SetDeg(unsigned* _deg);//Задать степени
	void SetKoef(double _koef);//Задать коэффициент

  TMonom* GetNext();//Получить указатель на следующий
  unsigned* GetDeg();//Получить степени
  double GetKoef();//Получить коэффициент
  const int GetSize();//Получить кол-во переменных

  TMonom& operator =(TMonom& Monom);
  TMonom operator +(TMonom& Monom);
  TMonom operator *(TMonom& Monom);
  TMonom operator -(TMonom& Monom);
  bool operator ==(TMonom& Monom);
  bool operator >(TMonom& Monom);
  bool operator <(TMonom& Monom);

  friend std::istream& operator >> (std::istream& _s, TMonom& Tm);
  friend std::ostream& operator << (std::ostream& _s, TMonom& Tm);

};

TMonom::TMonom(int _size, unsigned* _deg, double _koef) :size(_size)
{
	if (_size <= 0)
		throw Exception("Error length");
	deg = new unsigned[_size];
	if (_deg != 0) {
		for (int i = 0; i < _size; i++)
			deg[i] = _deg[i];
	}
	else {
		for (int i = 0; i < _size; i++)
			deg[i] = 0;
	}
	koef = _koef;
	next = 0;
}

TMonom::TMonom(TMonom& Monom) : size(Monom.size)
{
	koef = Monom.koef;
	next = Monom.next;
	deg = new unsigned[size];
	for (int i = 0; i < size; i++)
	{
		deg[i] = Monom.deg[i];
	}
}

TMonom::~TMonom()
{
  delete[]deg;
  koef = 0;
  next = 0;
}

void TMonom::SetNext(TMonom* _next)
{
	next = _next;
}

void TMonom::SetDeg(unsigned* _deg)
{
	for (int i = 0; i < size; i++) {
		if (_deg[i] >= 0)
		{
			deg[i] = _deg[i];
		}
		else
		{
			throw Exception("Error Deg");
		}
	}
}


void TMonom::SetKoef(double _koef)
{
	koef = _koef;
}


TMonom* TMonom::GetNext()
{
  return next;
}

unsigned* TMonom::GetDeg()
{
  return deg;
}

double TMonom::GetKoef()
{
  return koef;
}
const int TMonom::GetSize()
{
  return size;
}


TMonom& TMonom::operator =(TMonom& Monom)
{
  if (this != &Monom)
  {
    koef = Monom.koef;
    /*if (size != Monom.size)
      throw Exception("Can't equate, Error Size");*/
		delete[] deg;
		size = Monom.size;
		deg = new unsigned[size];
    for (int i = 0; i < size; i++)
      deg[i] = Monom.deg[i];
    next = Monom.next;
  }
  }

TMonom TMonom::operator +(TMonom& Monom)
{
	TMonom temp(*this);
	if (size != Monom.size)
		throw Exception("Error different size opperand");
	else
		for (int i = 0; i < size; i++)
		{
			if (deg[i] != Monom.deg[i])
				throw Exception("Error different deg opperand");
			temp.koef = koef + Monom.koef;
		}
}

TMonom TMonom::operator *(TMonom& Monom)
{	

	if (size <= Monom.size) 
	{
		TMonom temp(Monom);
		temp.koef = koef * Monom.koef;
		for (int i = 0; i < Monom.size; i++)
			temp.deg[i] = Monom.deg[i] + deg[i];

		return temp;
	}
	else
	{
		TMonom temp(*this);
		temp.koef = koef * Monom.koef;
		for (int i = 0; i < size; i++)
			temp.deg[i] = Monom.deg[i] + deg[i];

		return temp;
	}
}


TMonom TMonom::operator -(TMonom& Monom)
{
	TMonom temp(*this);
	if (size != Monom.size)
		throw Exception("Error different size opperand");
	else
		for (int i = 0; i < size; i++)
		{
			if (deg[i] != Monom.deg[i])
				throw Exception("Error different deg opperand");
			temp.koef = koef - Monom.koef;
		}
}

bool TMonom::operator ==(TMonom& Monom)
{
	if (size == Monom.size)
	{
		for (int i = 0; i < size; i++)
			if (deg[i] != Monom.deg[i])
				return false;
		if (koef != Monom.koef)
			return false;
		return true;
	}
	else
		return false;
}

bool TMonom::operator >(TMonom& Monom)
{
  if (size != Monom.size)
		throw Exception("Error different size opperand");

  for (int i = 0; i < size; i++)
	{
    if (deg[i] < Monom.deg[i])
      return false;
  }
  return true;

}
bool TMonom::operator <(TMonom& Monom)
{
	if (size != Monom.size)
		throw Exception("Error different size opperand");

  for (int i = 0; i < size; i++) {
    if (deg[i] > Monom.deg[i])
      return false;
  }
  return true;

}

std::istream& operator >> (std::istream& _s, TMonom& Tmon)
{
  std::cout << "Input koefficient:\n" << std::endl;
  _s >> Tmon.koef;
  std::cout << "Input deg: \n" << std::endl;
  for (int i = 0; i < Tmon.size; i++)
    _s >> Tmon.deg[i];

  return _s;
}

std::ostream& operator << (std::ostream& _s, TMonom& Tmon)
{
  _s << Tmon.koef;
  if (Tmon.koef != 0)
  {
    for (int i = 0; i < Tmon.size; i++)
      if (Tmon.deg[i] != 0)
      {
        _s << "x" << i;
        if (Tmon.deg[i] != 1)
          _s << "^" << Tmon.deg[i] << " ";
      }
  }
  return _s;
}

