#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
class TQueue : public TStack <T> // Очередь - наследник стека
{
protected:
	int start; // Начало очереди
	int count; // Кол-во элементов
public:
	TQueue(int len = 0);
	TQueue(TQueue <T> &que);

	void Put(T el); //Положить в конец
	T Top();
	T Get(); //Взять первый элемент
	bool IsFull(); //Проверка на полноту
	bool IsEmpty(); //Проверка на пустоту

	void Print();
};

template <class T>
TQueue<T>::TQueue(int len) : TStack<T>(len)
{
	start = 0;
	count = 0;
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &que) : TStack<T>(que)
{
	start = que.start;
	count = que.count;
}

template <class T>
void TQueue<T>::Put(T el)
{
	if (IsFull())
		throw Exception("Queue already Full");
	else
	{
		TStack<T>::Put(el);
		TStack<T>::top = TStack<T>::top % TStack<T>::length;
		count++;
	}
}

template<class T>
inline T TQueue<T>::Top()
{
	return TStack<T>::elem[start];
}

template <class T>
T TQueue<T>::Get()
{
	if (IsEmpty())
		throw Exception("Stack already Empty");
	else
	{
		T tmp = TStack<T>::elem[start];
		start = (start + 1) % TStack<T>::length;
		count--;
		return tmp;
	}
}

template <class T>
bool TQueue<T>::IsFull()
{
	return (count == TStack<T>::length);
}

template <class T>
bool TQueue<T>::IsEmpty()
{
	return (count == 0);
}

template<class T>
void TQueue<T>::Print()
{
	for (int i = start; i < TStack<T>::top; i = (i + 1) % TStack<T>::length) 
		cout << TStack<T>::elem[i];
}

