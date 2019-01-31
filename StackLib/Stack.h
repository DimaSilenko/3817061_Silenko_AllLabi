#pragma once
#include <iostream>
#include "ExceptionLib.h"

using namespace std;

template <class T>
class TStack
{
protected:
	int length;// Длина стека
	T* elem;// Элементы стека
	int top;// Вершина стека

public:
	TStack(int len = 0);
	TStack(TStack &st);
	virtual ~TStack();

	void Put(T el); // Положить элемент
	T Top();
	T Get();// Взять элемент
	int GetLength();// Получить длину стека

	bool IsFull();// Проверка на полноту
	bool IsEmpty();// Проверка на пустоту

	void PrintStack(); //Вывод стека на экран

	TStack& operator=(const TStack<T>& st); //Присваивание стека
	int operator==(const TStack<T>& st) const; //Проверка на равенство
	int operator!=(const TStack<T>& st) const; // Проверка на неравенство
};

//---------------------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(int len)
{
	if (len < 0)
		throw Exception("Error length");
	else
		if (len == 0) {
			length = 0;
			elem = 0;
			top = 0;
		}
		else {
			elem = new T[len];
			length = len;
			top = 0;
		}
}

//---------------------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(TStack<T> &st)
{
	length = st.length;
	top = st.top;
	if (length == 0)
		elem = 0;
	else {
		elem = new T[length];
		for (int i = 0; i < length; i++)
			elem[i] = st.elem[i];
	}
}

//---------------------------------------------------------------------------------------
template <class T>
TStack<T> :: ~TStack()
{
	if (elem != 0)
		delete[] elem;

	top = 0;
	length = 0;
}

//---------------------------------------------------------------------------------------
template <class T>
void TStack<T>::Put(T el)
{
	if (IsFull())
		throw Exception("Stack already Full");
	else {
		elem[top] = el;
		top++;
	}
}

//---------------------------------------------------------------------------------------
template<class T>
T TStack<T>::Top()
{
	if (IsEmpty())
		throw Exception("Stack already Empty");
	else
	{
		return elem[top - 1];
	}
}

//---------------------------------------------------------------------------------------
template <class T>
T TStack<T>::Get()
{
	if (IsEmpty())
		throw Exception("Stack already Empty");
	else {
		top--;
		return elem[top];
	}
}

//---------------------------------------------------------------------------------------
template <class T>
int TStack<T>::GetLength()
{
	return length;
}

//---------------------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsEmpty()
{
	return (top == 0);
}

//---------------------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsFull()
{
	return (top >= length);
}

//---------------------------------------------------------------------------------------
template <class T>
void TStack<T>::PrintStack()
{
	for (int i = top - 1; i >= 0; i--)
		cout << " " << elem[i];
}

//---------------------------------------------------------------------------------------
template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& st)
{
	if (this != &st)
	{
		delete[] elem;
		top = st.top;
		length = st.length;
		elem = new T[length];
		for (int i = 0; i < length; i++)
			elem[i] = st.elem[i];
	}
	return *this;
}

//---------------------------------------------------------------------------------------
template <class T>
int TStack<T>::operator==(const TStack<T>& st) const
{
	if (top != st.top)
    return 0;
	if (length != st.length)
		return 0;
	for (int i = 0; i < top; i++)
		if (elem[i] != st.elem[i])
			return 0;
	return 1;
}

//---------------------------------------------------------------------------------------
template <class T>
int TStack<T>::operator!=(const TStack<T>& st) const
{
	return !(*this == st);
}