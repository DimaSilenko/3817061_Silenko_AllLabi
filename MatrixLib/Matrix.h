#pragma once
#include "Vector.h"
#include <iomanip>

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
	TMatrix<T> operator*(const TMatrix<T> &matr);  // умножение
	TMatrix<T> operator/(const TMatrix<T> &matr);    //деление

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
TMatrix<T>::TMatrix(const TVector<TVector<T> > &matr) : TVector<TVector<T> >(matr)
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
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &matr)
{
	if (this->length != matr.length)
		throw Exception("Error length operand");
	TMatrix <T> res(this->length);
	for (int i = 0; i < this->length; i++)
		for (int j = i; j < this->length; j++) {
			for (int k = i; k <= j; k++)
				res.vector[i][j - i] += this->vector[i][k - i] * matr.vector[k][j - k];
		}
	return res;
}

//-------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T> &matr)
{
	if (this->length != matr.length)
		throw Exception("Error length operand");
	TMatrix <T> copy(*this);
	TMatrix <T> rez(this->length);
	TMatrix <T> copyMt(matr);

	for (int i = 0; i < this->length; i++)
		rez[i][0] = 1 / copyMt[i][0];

	for (int i = 0; i < this->length - 1; i++)
		for (int j = 1; j < this->length - i; j++)
		{
			if (copyMt[i][j] != 0)
			{
				T temp = copyMt[i][j];
				rez[i][j] = (-1) * copyMt[i][j] * rez[i + j][0];
				for (int k = j, l = 0; k < this->length - i; k++)
					copyMt[i][k] = copyMt[i][k] - copyMt[j][l++] * temp;
			}
		}
	rez = copy * rez;
	return rez;
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
	{
		for (int k = 0; k < i; k++)
			out << "  \t";
		out << setprecision(5) << matr.vector[i] << endl;
	}
	return out;
}
