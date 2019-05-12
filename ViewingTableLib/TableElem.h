#pragma once
#include <iostream>
#include "ExceptionLib.h"

template <class T> 
class TElem
{
protected:
	string key;				//Строка-ключ для доступа к элементам таблицы
	T data;						//Сами данные
public:
	TElem(string _key = "", T _data = 0);
	TElem(TElem &elem);

	void SetData(T _data);				//Вставить данные в таблицу
	void SetKey(string _key);			//Установить ключ

	string GetKey();							//Получить ключ
	T GetData();								  //Получить данные
	T& GetDataAddress();					//Получить адрес данных

	TElem<T>& operator=(TElem &elem);	
	bool operator==(TElem &elem);		//проверка на равенство
};

// ---------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(string _key, T _data)
{
	key = _key;
	data = _data;
}

// ---------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(TElem &elem)
{
	key = elem.key;
	data = elem.data;
}

// ---------------------------------------------------------------------------
template <class T>
void TElem<T>::SetKey(string _key)
{
	key = _key;
}

// ---------------------------------------------------------------------------
template <class T>
void TElem<T>::SetData(T _data)
{
	data = _data;
}

// ---------------------------------------------------------------------------
template <class T>
string TElem<T>::GetKey()
{
	return key;
}

// ---------------------------------------------------------------------------
template <class T>
T TElem<T>::GetData()
{
	return data;
}

// ---------------------------------------------------------------------------
template <class T>
T& TElem<T>::GetDataAddress()
{
	return data;
}

// ---------------------------------------------------------------------------
template <class T>
TElem<T>& TElem<T>::operator=(TElem &elem)
{
	if (this != &elem)
	{
		key = elem.key;
		data = elem.data;
	}
	return *this;
}

// ---------------------------------------------------------------------------
template <class T>
bool TElem<T>::operator==(TElem &elem)
{
	if (key != elem.key)
		return 0;
	if (data != elem.data)
		return 0;
	return 1;
}

