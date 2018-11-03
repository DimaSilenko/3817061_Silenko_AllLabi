#pragma once
#include <iostream>

using namespace std;

template <class T>
class TVector
{
protected:
	T* vector;
	int dlina;
public:
	TVector();
	TVector(TVector &A);
	TVector(T* s, int len);
	~TVector();

	int Lenght(TVector<T> &A);
	TVector<T> Izm();
	void  Del();

	TVector<T> operator +(TVector<T> &A);
	TVector<T> operator -(TVector<T> &A);
	T operator *(TVector<T> &A);
	TVector<T> operator *(double um);
	TVector<T> operator /(double del);
	TVector<T>& operator =(TVector<T> &A);
	T& operator[] (int I);

	template <class T1>
	friend std::istream& operator >> (std::istream &A, TVector<T1> &B);

	template <class T1>
	friend std::ostream& operator << (std::ostream &A, TVector<T1> &B);

};

//---------------------------------------------------------------------------------------
template <class T>
TVector<T>::TVector()
{
	vector = 0;
	dlina = 0;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(TVector &A)
{
	dlina = A.dlina;
	if (dlina != 0)
	{
		vector = new T[dlina];
		for (int i = 0; i < dlina; i++)
		{
			vector[i] = A.vector[i];
		}
	}
	else
		vector = 0;

}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(T* s, int len)
{
	dlina = len;
	vector = new T[dlina];
	for (int i = 0; i < dlina; i++)
	{
		vector[i] = s[i];
	}
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
int TVector<T> ::Lenght(TVector<T> &A)
{
	return A.dlina;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::Izm()
{
	int l, n, g;
	TVector<T> S;
	cout << "1. Если хотите увеличить длину; 2. Если хотите уменьшить длинну\n";
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "Введите число, на которое вы хотите извенить длину вектора (>0)\n";
		cin >> l;
		g = dlina + l;
		S.dlina = g;
		S.vector = new T[g];
		for (int i = 0; i < dlina; i++)
		{
			S.vector[i] = vector[i];
		}
		for (int i = dlina; i < g; i++)
		{
			S.vector[i] = 0;
		}
		break;
	case 2:
		cout << "Введите число, на которое вы хотите извенить длину вектора (>0)\n";
		cin >> l;
		S.dlina = dlina - l;
		S.vector = new T[dlina - l];
		g = dlina - l;
		for (int i = 0; i < g; i++)
		{
			S.vector[i] = vector[i];
		}
		break;
	default: cout << "Неверный ввод\n";
	}

	delete[]vector;
	dlina = S.dlina;
	vector = new T[dlina];
	for (int i = 0; i < dlina; i++)
	{
		vector[i] = S.vector[i];
	}

	return S;
}

//---------------------------------------------------------------------------------------
template <class T>
void TVector<T>::Del()
{
	vector = 0;
	dlina = 0;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T> :: operator +(TVector<T> &A)
{
	TVector<T> S;
	if (dlina == A.dlina)
	{
		if (dlina == 0)
			S.vector = 0;
		else
		{
			S.dlina = dlina;
			S.vector = new T[dlina];
			for (int i = 0; i < dlina; i++)
				S.vector[i] = vector[i] + A.vector[i];
		}
	}
	else
		throw 1;
	return S;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T> :: operator -(TVector<T> &A)
{
	TVector<T> S;
	if (dlina == A.dlina)
	{
		if (dlina == 0)
			S.vector = 0;
		else
		{
			S.dlina = dlina;
			S.vector = new T[dlina];
			for (int i = 0; i < dlina; i++)
				S.vector[i] = vector[i] - A.vector[i];
		}
	}
	else
		throw 1;
	return S;
}

//---------------------------------------------------------------------------------------
template <class T>
T TVector<T> :: operator *(TVector<T> &A)
{
	T S = 0;
	if (dlina == A.dlina)
	{
		if (dlina == 0)
		{
			S = 0;
		}
		else
		{
			for (int i = 0; i < dlina; i++)
				S = S + vector[i] * A.vector[i];
		}
	}
	else
		throw 1;
	return S;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T> :: operator *(double um)
{
	TVector<T> S;
	if (dlina == 0)
	{
		S.vector = 0;
	}
	else
	{
		S.dlina = dlina;
		S.vector = new T[dlina];
		for (int i = 0; i < dlina; i++)
			S.vector[i] = vector[i] * um;
	}
	return S;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T> :: operator /(double del)
{
	TVector<T> S;
	if (dlina == 0)
	{
		S.vector = 0;
	}
	else
	{
		S.dlina = dlina;
		S.vector = new T[dlina];
		for (int i = 0; i < dlina; i++)
			S.vector[i] = vector[i] / del;
	}
	return S;
}

//---------------------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T> :: operator =(TVector<T> &A)
{
	if (this != &A)
	{
		dlina = A.dlina;
		if (dlina != 0)
		{
			if (vector != 0)
				delete[]vector;
			vector = new T[A.dlina];
			for (int i = 0; i < A.dlina; i++)
			{
				vector[i] = A.vector[i];
			}
		}
		else
		{
			if (vector != 0)
				delete[]vector;
			vector = 0;
		}
	}
	return *this;
}

//---------------------------------------------------------------------------------------
template <class T>
T& TVector<T> ::operator[] (int I)
{
	if (I >= 0 && I < dlina)
		return vector[I];
	throw 1;
}

//---------------------------------------------------------------------------------------
template <class T1>
std::istream& operator >> (std::istream &A, TVector<T1> &B)
{
	cout << "Введите длину\n";
	A >> B.dlina;
	B.vector = new T1[B.dlina];
	cout << "Введите сам вектор\n";
	for (int i = 0; i < B.dlina; i++)
	{
		A >> B.vector[i];
	}
	return A;
}

//---------------------------------------------------------------------------------------
template <class T1>
std::ostream& operator << (std::ostream &A, TVector<T1> &B)
{
	cout << "Длина вектора: ";
	A << B.dlina << "\n";
	cout << "Сам вектор:\n";
	for (int i = 0; i < B.dlina; i++)
	{
		A << B.vector[i] << "\n";
	}
	return A;
}
