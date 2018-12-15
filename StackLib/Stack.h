#pragma once
#include <iostream>
#include "ExceptionLib.h"

using namespace std;

template <class T>
class TStack{
protected:
	int length;// Длина стека
	T* elem;// Элементы стека
	int top;// Вершина стека

public:
	TStack(int len = 0);
	TStack(TStack &St);
	~TStack();

	void Put(T el); // Положить элемент
	T Get();// Взять элемент
	bool IsFull();// Проверка на полноту
	bool IsEmpty();// Проверка на пустоту
};

//---------------------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(int len){
	if (len < 0)
		throw Exception("Error length");
	else 
		if (len == 0){
		length = 0;
		elem = 0;
		top = 0;
	}
	else{
		elem = new T[len];
		length = len;
		top = 0;
	}
}

//---------------------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(TStack<T> &St){
	length = St.length;
	top = St.top;
	if (length == 0)
		elem = 0;
	else{
		elem = new T[length];
		for (int i = 0; i < length; i++)
			elem[i] = St.elem[i];
	}
}

//---------------------------------------------------------------------------------------
template <class T>
TStack<T> :: ~TStack(){
	if (elem != 0)
		delete[] elem;

	top = 0;
	length = 0;
}

//---------------------------------------------------------------------------------------
template <class T>
void TStack<T>::Put(T el){
	if (IsFull())
		throw Exception("Stack already Full");
	else{
		elem[top] = el;
		top++;
	}
}

//---------------------------------------------------------------------------------------
template <class T>
T TStack<T>::Get(){
	if (IsEmpty())
		throw Exception("Stack already Empty");
	else{
		top--;
		return elem[top];
	}
}

//---------------------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsEmpty(){
	return (top == 0);
}

//---------------------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsFull(){
	return (top >= length);
}