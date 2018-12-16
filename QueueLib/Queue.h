#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
class TQueue : public TStack <T> { // Очередь - наследник стека
protected:
	int start; // Начало очереди
	int count; // Кол-во элементов
public:
	TQueue(int len = 0); 
	TQueue(TQueue <T> &Que);

	void Put(T el); //Положить в конец
	T Get(); //Взять первый элемент
	bool IsFull(); //Проверка на полноту
	bool IsEmpty(); //Проверка на пустоту
};

template <class T>
TQueue<T>::TQueue(int len) : TStack<T>(len) {
	if (len < 0)
		throw Exception("Error length");
	else
		if (len == 0)
		{
			start = 0;
			this->length = 0;
			this->elem = 0;
			this->top = 0;
			count = 0;
		}
		else
		{
			this->length = len;
			this->elem = new T[len];
			this->top = 0;
			start = 0;
			count = 0;
		}
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &Que) : TStack<T>(Que) {
	start = Que.start; 
	count = Que.count;
}

template <class T>
void TQueue<T>::Put(T el){
	if (IsFull())
		throw "Queue is full";
	else {
		TStack<T>::elem[start] = el;
		start = (start + 1) % TStack<T>::length;
		count++;
	}
}

template <class T>
T TQueue<T>::Get() {
	if (IsEmpty())
		throw "Queue is empty";
	else {
		T tmp = TStack<T>::elem[TStack<T>::top];
		TStack<T>::top = (TStack<T>::top + 1) % TStack<T>::length;
		count--;
		
		return tmp;
	}
}

template <class T>
bool TQueue<T>::IsFull() {
	return (count == TStack<T>::length);
}

template <class T>
bool TQueue<T>::IsEmpty() {
	return (count == 0);
}