#pragma once
#include <iostream>
#include "ExceptionLib.h"

template <class T>
class TSortElem
{
protected:
  string key;					//Ключ для доступа к элементам таблицы
  T data;							//Данные элемента таблицы
public:
  TSortElem(string _key = "", T _data = 0);
  TSortElem(TSortElem<T> &selem);

	void SetKey(string _key);		//задать ключ
	void SetData(T _data);			//Задать данные

	string GetKey();						//Получить ключ
	T GetData();								//Получить данные
	T& GetDataAddress();				//Получить адрес данных

  TSortElem<T>& operator=(TSortElem<T> &selem);
  bool operator==(TSortElem<T> &selem);
  bool operator>(TSortElem<T> &selem);
  bool operator<(TSortElem<T> &selem);
};

// ---------------------------------------------------------------------------
template <class T>
TSortElem<T>::TSortElem(string _key, T _data)
{
  key = _key;
  data = _data;
}

// ---------------------------------------------------------------------------
template <class T>
TSortElem<T>::TSortElem(TSortElem<T> &selem)
{
  key = selem.key;
  data = selem.data;
}

// ---------------------------------------------------------------------------
template <class T>
void TSortElem<T>::SetKey(string _key)
{
	key = _key;
}

// ---------------------------------------------------------------------------
template <class T>
void TSortElem<T>::SetData(T _data)
{
	data = _data;
}

// ---------------------------------------------------------------------------
template <class T>
string TSortElem<T>::GetKey()
{
	return key;
}

// ---------------------------------------------------------------------------
template <class T>
T TSortElem<T>::GetData()
{
	return data;
}

// ---------------------------------------------------------------------------
template <class T>
T& TSortElem<T>::GetDataAddress()
{
	return data;
}

// ---------------------------------------------------------------------------
template <class T>
TSortElem<T>& TSortElem<T>::operator=(TSortElem<T> &selem)
{
  if (this != &selem)
  {
    key = selem.key;
    data = selem.data;
  }
  return *this;
}

// ---------------------------------------------------------------------------
template <class T>
bool TSortElem<T>::operator==(TSortElem &selem)
{
  if (key != selem.key)
    return 0;
  if (data != selem.data)
    return 0;
  return 1;
}

// ---------------------------------------------------------------------------
template <class T>
bool TSortElem<T>::operator<(TSortElem &selem)
{
  if (key.compare(selem.key)<0)
    return 1;
  return 0;
}

// ---------------------------------------------------------------------------
template <class T>
bool TSortElem<T>::operator>(TSortElem &selem)
{
  if (key.compare(selem.key) > 0)
    return 1;
  return 0;
}