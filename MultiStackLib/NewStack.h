#pragma once
#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
class TNewStack : public TStack<T>
{
public:
  TNewStack(int _length, T* _elem);
  TNewStack(TNewStack<T>& newst);

  int GetFreeCell();                      //получить количество свободных ячеек в стеке
  T Get();                               //забрать элемент из стека
  int GetLength();                       //получить длину стека
  int GetTop();                          //получить позицию вершины стека
	void Push(T _elem);                    //положить элемент в стек
  void SetMas(int _length, T* _elem);    //преобразовать массив elem размера length в стек

  void PrintNewStack();                  //вывод стека на экран
};

//------------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack(int _length, T* _elem)
{
  if (_length <= 0)
    throw Exception("Error size");
  TStack<T>::top = 0;
  TStack<T>::length = _length;
  TStack<T>::elem = _elem;
}

//------------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack(TNewStack<T>& newst)
{
  TStack<T>::top = newst.top;
  TStack<T>::length = newst.length;
  TStack<T>::elem = newst.elem;
}

//------------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetFreeCell()
{
	return TStack<T>::length - TStack<T>::top;
}

//------------------------------------------------------------------------------
template <class T>
T TNewStack<T>::Get()
{
	TStack<T>::top--;
	return TStack<T>::elem[TStack<T>::top];
}

//------------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetLength()
{
	return TStack<T>::length;
}

//------------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetTop()
{
  return TStack<T>::top;
}

//------------------------------------------------------------------------------
template <class T>
void TNewStack<T>::Push(T _elem)
{
	if (TStack<T>::top != TStack<T>::length)
	{
		TStack<T>::elem[TStack<T>::top] = _elem;
		TStack<T>::top++;
	}
	else
		throw Exception( "NewStack already Full");
}

//------------------------------------------------------------------------------
template <class T>
void TNewStack<T>::SetMas(int _length, T* _elem)
{
	if (_length <= 0)
		throw Exception("Error size");
	TStack<T>::length = _length;
	TStack<T>::elem = _elem;
}

//------------------------------------------------------------------------------
template <class T>
void TNewStack<T>::PrintNewStack()
{
  for (int i =  0; i < TStack<T>::top; i++)
    cout << " " << TStack<T>::elem[i];
}
