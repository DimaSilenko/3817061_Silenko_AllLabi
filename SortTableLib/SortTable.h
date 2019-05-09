#pragma once
#include "SortTableElem.h"

template<class T>
class TSortTable
{
protected:
  TSortElem<T> notFound;		//Элемент не найден
  TSortElem<T>* mas;				//Массив элементов таблицы
  int length;									//Длина таблицы
  int count;								//Количество элементов в таблице
public:
	TSortTable(int _length = 10);
  TSortTable(string* _keys, T* _data, int _length);
  TSortTable(TSortTable<T> &stable);

	void SetSize(int _size);					//Задать размер таблицы
	void SetCount(int _count);				//Задать количество элементов в таблице

	int GetLength();										//Получить размер таблицы	
	int GetCount();										//Получить количество элементов в таблице

  int Put(string _key, T _data);		//Положить элемент в таблицу
  void Del(string _key);						//Удалить элемент из таблицы
  TSortElem<T>& Search(string _key);//Найти элемент в таблице
  void Resize(int _size);						//Перепаковка

  T& operator[](string _key);				//Доступ к элементу по ключу
};

// ---------------------------------------------------------------------------
template<class T>
TSortTable<T>::TSortTable(int _length)
{
	if (_length <= 0)
		throw Exception("Error size\n");

	else if (_length == 0)
	{
		length = 0;
		count = 0;
		notFound.SetKey("no_such_elem");
		notFound.SetData(-1);
		mas = NULL;
	}
	else
	{
		length = _length;
		count = 0;
		notFound.SetKey("no_such_elem");
		notFound.SetData(-1);
		mas = new TSortElem<T>[length];
	}
}

// ---------------------------------------------------------------------------
template<class T>
TSortTable<T>::TSortTable(string* _keys, T* _data, int _length)
{
  if (_length <= 0)
    throw Exception("Error size\n");

    length = _length;
    count = 0;
    mas = new TSortElem<T>[length];
    for (int i = 0; i < length; i++)
      Put(_keys[i], _data[i]);
}

// ---------------------------------------------------------------------------
template<class T>
TSortTable<T>::TSortTable(TSortTable<T> &stable)
{
  length = stable.length;
  count = stable.count;
  mas = new TSortElem<T>[length];
  for (int i = 0; i < length; i++)
    mas[i] = stable.mas[i];
}

// ---------------------------------------------------------------------------
template <class T>
void TSortTable<T>::SetSize(int _length)
{
	length = _length;
}

// ---------------------------------------------------------------------------
template <class T>
void TSortTable<T>::SetCount(int _count)
{
	count = _count;
}

// ---------------------------------------------------------------------------
template <class T>
int TSortTable<T>::GetLength()
{
	return length;
}

// ---------------------------------------------------------------------------
template <class T>
int TSortTable<T>::GetCount()
{
	return count;
}

// ---------------------------------------------------------------------------
template<class T>
int TSortTable<T>::Put(string _key, T _data)
{
  if (length <= count)
    Resize(count * 2);
  if (count == 0)
  {
    TSortElem<T> tmp(_key, _data);
    mas[0] = tmp;
    count++;
    return 0;
  }
  int right = count;
  int left = 0;
  int mid = count / 2;
  while (left < right)
  {
    if (mas[mid].GetKey() > _key)
    {
      right = mid-1;
      mid = ((left + right) / 2);
    }
    else if (mas[mid].GetKey() < _key)
    {
      left = mid+1;
      mid = ((left + right) / 2);
    }
    else
    {
      throw Exception("Error key already exists\n");
    }
  }
  for (int i = mid; i < count; i++)
    mas[i + 1] = mas[i];
  TSortElem<T> tmp(_key, _data);
  mas[mid] = tmp;
  count++;
  return mid;
}

// ---------------------------------------------------------------------------
template<class T>
void TSortTable<T>::Del(string _key)
{
  int right = count;
  int left = 0;
  int mid = count / 2;
  while (left < right)
  {
    if (mas[mid].GetKey() > _key)
    {
      right = mid-1;
      mid = ((left + right) / 2);
    }
    else if (mas[mid].GetKey() < _key)
    {
      left = mid+1;
      mid = ((left + right) / 2);
    }
    else
    {
      for (int i = mid; i < count-1; i++)
        mas[i] = mas[i + 1];
      count--;
    }
  }
}

// ---------------------------------------------------------------------------
template<class T>
TSortElem<T>& TSortTable<T>::Search(string _key)
{
  int right = count;
  int left = 0;
  int mid = count / 2;
  while (left<right)
  {
    if (mas[mid].GetKey() > _key)
    {
      right = mid;
      mid = ((left + right) / 2);
    }
    else if (mas[mid].GetKey() < _key)
    {
      left = mid + 1;
      mid = ((left + right) / 2);
    }
    else
      return mas[mid];
  }
  return notFound;
}

// ---------------------------------------------------------------------------
template<class T>
void TSortTable<T>::Resize(int _length)
{
  if (_length < length)
    throw Exception("Error size!\n");

  TSortElem<T>* newMas = new TSortElem<T>[_length];
  for (int i = 0; i < length; i++)
    newMas[i] = mas[i];
  delete[] mas;
  mas = newMas;
  length = _length;
}

// ---------------------------------------------------------------------------
template<class T>
T& TSortTable<T>::operator[](string _key)
{
  TSortElem<T>& tmp = Search(_key);
  if (tmp == notFound)
  {
    Put(_key, 0);
    return mas[count - 1].GetDataAddress();
  }
  return tmp.GetDataAddress();
}
