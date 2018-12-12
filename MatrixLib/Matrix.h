#pragma once
#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int len = 10);
  TMatrix(const TMatrix &matr);
  TMatrix(const TVector<TVector<T> > &matr);
  virtual ~TMatrix();

	TMatrix operator+(const TMatrix &matr);         // сложение
	TMatrix operator-(const TMatrix &matr);         // вычитание
	TMatrix<T> operator*(const TMatrix<T> &Matr);    // умножение

  bool operator==(const TMatrix &matr) const;      // сравнение на равенство
  bool operator!=(const TMatrix &matr) const;      // сравнение на неравенство
	TMatrix& operator=(const TMatrix &matr);        // присваивание
  

  template <class Type2>
  friend istream& operator>>(istream &in, TMatrix<Type2> &matr);
  template <class Type2>
  friend ostream & operator<<(ostream &out, const TMatrix<Type2> &matr);
};

//-------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int len) :TVector<TVector<T> >(len)
{
	if (len <= 0 || len > 1000)
		throw Exception("Error length");
  for (int i = 0; i < len; i++)
    this->vector[i] = TVector<T>(len - i);
} 

//-------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &matr) :TVector<TVector<T> >(matr)
{}

//-------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &matr) :TVector<TVector<T> >(matr)
{}

//-------------------------------------------------------------------------
template <class T>
TMatrix<T>::~TMatrix() 
{}//?????

//-------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &matr)
{
	if (this->length == matr.length)
		return TVector<TVector<T> >::operator+(matr);
	else
		throw Exception("Error length operand");
} 

//-------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &matr)
{
	if (this->length == matr.length)
		return TVector<TVector<T> >::operator-(matr);
	else
		throw Exception("Error length operand");
} 

//-------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &Matr)
{
	if (this->length != Matr.length)
		throw Exception("Error length operand");
	TMatrix <T> res(this->length);
	for (int i = 0; i < this->length; i++)
		for (int j = i; j < this->length; j++) {
			for (int k = i; k <= j; k++)
				res.vector[i][j - i] += this->vector[i][k - i] * Matr.vector[k][j - k];
		}
	return res;
}

//-------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &matr) const
{
  return TVector<TVector<T> >::operator==(matr);
} 

//-------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &matr) const
{
  return TVector<TVector<T> >::operator!=(matr);
} 

//-------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &matr)
{
  TVector<TVector<T> >::operator=(matr);
  return *this;
}

//-------------------------------------------------------------------------
template <class Type2>
istream& operator>>(istream &in, TMatrix<Type2> &matr)
{
  for (int i = 0; i < matr.length; i++)
    in >> matr.vector[i];
  return in;
}

//-------------------------------------------------------------------------
template <class Type2>
ostream & operator<<(ostream &out, const TMatrix<Type2> &matr)
{
  for (int i = 0; i < matr.length; i++)
    out << matr.vector[i] << endl;
  return out;
}