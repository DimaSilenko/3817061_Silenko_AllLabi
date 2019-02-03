#pragma once
#include <iostream>
#include "ExceptionLib.h"

using namespace std;

template <class T>
class TVector
{
protected:
	T* vector;
	int length;
public:
	TVector(int len = 0);
	TVector(const TVector<T> &V);
	virtual  ~TVector();

	int GetLength() const; // Размер вектора
	virtual T& operator[](int pos); // Доступ по индексу


	TVector<T> operator +(const TVector<T> &vec); // сложение векторов
	TVector<T> operator -(const TVector<T> &vec); // Вычитание векторов
	T operator *(TVector<T> &vec); // Умножение векторов

	TVector<T> operator+(const T &vol);   // сложение с числом
	TVector<T> operator-(const T &vol);   // вычитание числа
	TVector<T> operator*(const T &vol);   // умножение на число

	bool operator==(const TVector &vec) const;  // сравнение на равенство
	bool operator!=(const TVector &vec) const;  // сравнение на неравенство
	virtual TVector& operator=(const TVector &vec); // присваивание

	template <class Type1>
	friend istream& operator >> (istream &in, TVector<Type1> &vec);

	template <class Type1>
	friend ostream& operator << (ostream &out, const TVector<Type1> &vec);

};

template <class T>
TVector<T>::TVector(int len)
{
	if (len < 0)
		throw Exception("Error length");
	else
		if (len == 0)
		{
			length = len;
			vector = NULL;
		}
		else
		{
			length = len;
			vector = new T[length];
			for (int i = 0; i < length; i++)
				vector[i] = 0;
		}
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(const TVector<T> &V)
{
	length = V.length;
	if (length != 0)
	{
		vector = new T[length];
		for (int i = 0; i < length; i++)
		{
			vector[i] = V.vector[i];
		}
	}
	else
		vector = 0;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T>:: ~TVector()
{
	if (vector != 0)
		delete[]vector;
	vector = 0;
}

//---------------------------------------------------------------------------------------
template <class T>
int TVector<T> ::GetLength() const
{
	return length;
}

//---------------------------------------------------------------------------------------
template <class T>
T& TVector<T> ::operator[] (int pos)
{
	if (pos >= 0 && pos < length)
		return vector[pos];
	throw Exception("Error index");
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T> :: operator +(const TVector<T> &vec)
{
	if (length == vec.length)
	{
		TVector<T> res(*this);
		for (int i = 0; i < length; i++)
			res[i] = (*this)[i] + vec.vector[i];
		return res;
	}
	else
		throw Exception("Error length operand");

}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T> :: operator -(const TVector<T> &vec)
{
	if (length == vec.length)
	{
		TVector<T> res(*this);
		for (int i = 0; i < length; i++)
			res[i] = (*this)[i] - vec.vector[i];
		return res;
	}
	else
		throw Exception("Error length operand");
}

//---------------------------------------------------------------------------------------
template <class T>
T TVector<T> :: operator *(TVector<T> &vec)
{
	if (length == vec.length)
	{
		int tmp = 0;
		for (int i = 0; i < length; i++)
			tmp += vector[i] * vec.vector[i];
		return tmp;
	}
	else
		throw Exception("Error length operand");
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator+(const T &vol)
{
	TVector<T> res(*this);
	for (int i = 0; i < length; i++)
		res.vector[i] = res.vector[i] + vol;
	return res;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator-(const T &vol)
{
	TVector<T> res(*this);
	for (int i = 0; i < length; i++)
		res.vector[i] = res.vector[i] - vol;
	return res;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator*(const T &vol)
{
	TVector<T> res(*this);
	for (int i = 0; i < length; i++)
		res.vector[i] = res.vector[i] * vol;
	return res;
}

//---------------------------------------------------------------------------------------
template <class T>
bool TVector<T>::operator==(const TVector &vec) const
{
	if (length != vec.length)
		return 0;
	else
		for (int i = 0; i < length; i++)
			if (vector[i] != vec.vector[i])
			{
				return 0;
			}
	return 1;
}

//---------------------------------------------------------------------------------------
template <class T>
bool TVector<T>::operator!=(const TVector &v) const
{
	return !(*this == v);
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator=(const TVector &vec)
{
	if (this != &vec)
	{
		delete[] vector;
		length = vec.length;
		vector = new T[length];
		for (int i = 0; i < length; i++)
			vector[i] = vec.vector[i];
	}
	return *this;
}


//---------------------------------------------------------------------------------------
template <class Type1>
istream& operator>>(istream &in, TVector<Type1> &vec)
{
	for (int i = 0; i < vec.length; i++)
		in >> vec.vector[i];
	return in;
}//-------------------------------------------------------------------------

template <class Type1>
ostream& operator<<(ostream &out, const TVector<Type1> &vec)
{
	for (int i = 0; i < vec.length; i++)
		out << vec.vector[i] << '\t';
	return out;
}


