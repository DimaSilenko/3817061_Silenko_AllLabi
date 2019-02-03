#pragma once
#include "ExceptionLib.h"

class TMonom
{
protected:
  TMonom* next;																	//указатель на следующий моном
  int *deg;																		  //массив степеней
  double koef;																	//коэффицтент
  int count;																		//количество переменных в мономе

public:
  TMonom();
  TMonom(int _count, int* _deg, double _koef);
  TMonom(TMonom& mon);
  virtual ~TMonom();

	void SetNext(TMonom* _next);                  //задать адрес следующего монома
	void SetDeg(int* _deg);											//задать массив степеней монома
	void SetKoef(double _koef);									//задать коэффициент при мономе
	void SetCount(int _count);									//задать количество переменных в мономе

  TMonom* GetNext();														//получить адрес следующего монома
  int* GetDeg();															//получить массив степеней монома
  double GetKoef();														//получить коэффициент при мономе
  int GetCount();															//получить количество переменных в мономе

  TMonom operator+(TMonom& mon);
  TMonom operator+=(TMonom& mon);

	TMonom operator-(TMonom& mon);
	TMonom operator-=(TMonom& mon);

  TMonom operator*(TMonom& mon);
  TMonom operator*=(TMonom& mon);

	TMonom& operator=(TMonom& mon);
  bool operator==(TMonom& mon);
  bool operator>(TMonom& mon);
  bool operator<(TMonom& mon);

  friend istream& operator>>(istream& istr, TMonom& mon);
  friend ostream& operator<<(ostream& ostr, TMonom& mon);
};
