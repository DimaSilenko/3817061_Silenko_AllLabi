#pragma once
#include "List.h"
#include "ExceptionLib.h"

template <class T>
class TStackList : public TList<T>
{
protected:
	int length;																	//Максимальная длина стека

public:
	TStackList(int _length = 10);
	TStackList(TStackList &stlst);
	~TStackList();

	T Get();																		//Изъять верхний элемент списка
	int GetMaxLength();														//Получить размер стека
	int GetLength();															//Получить текущее количество элементов в стеке

	void Put(T elem);														//Положить elem в начало списка

	bool IsEmpty();															//Проверка стека на списках на пустоту
	bool IsFull();															//Проверка стека на списках на полноту

	void PrintStLst();																//Вывод стека на списках на экран
};

//------------------------------------------------------------------------------
template <class T>
TStackList<T>::TStackList(int _length) : TList<T>()
{
	if (_length <= 0)
		throw Exception("Error length");

	length = _length;
}

//------------------------------------------------------------------------------
template <class T>
TStackList<T>::TStackList(TStackList<T> &stlst) : TList<T>(stlst)
{
	TList<T>::count = stlst.count;
}

//------------------------------------------------------------------------------
template<class T>
TStackList<T>::~TStackList()
{
}

//------------------------------------------------------------------------------
template <class T>
T TStackList<T>::Get()
{
	if (this->IsEmpty())
		throw Exception("Error StackList already Empty");

	return TList<T>::GetBegin();
}

//------------------------------------------------------------------------------
template <class T>
int TStackList<T>::GetMaxLength()
{
	return length;
}

//------------------------------------------------------------------------------
template<class T>
inline int TStackList<T>::GetLength()
{
	return TList<T>::count;
}

//------------------------------------------------------------------------------
template <class T>
void TStackList<T>::Put(T elem)
{
	if (this->IsFull())
		throw Exception("Error StackList already Full");
	TList<T>::PutBegin(elem);
}

//------------------------------------------------------------------------------
template <class T>
bool TStackList<T>::IsEmpty()
{
	if (TList<T>::count == 0)
		return true;
	else
		return false;
}

//------------------------------------------------------------------------------
template<class T>
bool TStackList<T>::IsFull()
{
	if (TList<T>::count == length)
		return true;
	else
		return false;
}

//------------------------------------------------------------------------------
template<class T>
void TStackList<T>::PrintStLst()
{
	if (this->IsEmpty())
		throw Exception("Error Nothing to Print, StackList already Empty");
	TList<T>::Print();
}



