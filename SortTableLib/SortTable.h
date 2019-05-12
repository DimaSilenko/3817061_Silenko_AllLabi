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
  TSortTable(string* _keys, T* _data, int _length, int numOfSort);
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

	void Puzir(string *_key, T* _data, int _length);
	void Vstavka(string* _key, T* _data, int _length);
	void SortQuick(string* _key, T* _data, T first, T last);
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
TSortTable<T>::TSortTable(string* _keys, T* _data, int _length, int numOfSort)
{
  if (_length <= 0)
    throw Exception("Error size\n");

    length = _length;
    count = 0;
    mas = new TSortElem<T>[length];

		switch (numOfSort)
		{
		case 1:
			Puzir(_keys, _data, _length);
			break;
		case 2:
			Vstavka(_keys, _data, _length);
			break;
		case 3:
			SortQuick(_keys, _data, _data[0], _data[_length]);
			break;
		default:
			throw Exception("Error number of sort");
			break;
		}

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

//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
template<class T>
void TSortTable<T>::Puzir(string *_key, T *_data, int _length)
{
	T tmp = 0;
	string temp;
	for (int i = 1; i < _length; i++)
		for (int j = i; j >= 0; j--)
		{
			if (_data[j] < _data[j - 1])
			{
				tmp = _data[j];
				_data[j] = _data[j - 1];
				_data[j - 1] = tmp;

				temp = _key[j];
				_key[j] = _key[j - 1];
				_key[j - 1] = temp;
			}
			else break;
		}
}

//---------------------------------------------------------------------------
template<class T>
void TSortTable<T>::Vstavka(string* _key, T* _data, int _length)
{
	int ind;
	T tmp, min;
	string temp;
	for (int i = 0; i < _length - 1; i++)
	{
		min = _data[i]; ind = i;
		for (int j = i + 1; j < _length; j++)
			if (min > _data[j])
			{
				min = _data[j];
				ind = j;
			}
		tmp = _data[i];
		_data[i] = _data[ind];
		_data[ind] = tmp;

		temp = _key[i];
		_key[i] = _key[ind];
		_key[ind] = temp;
	}
}

//---------------------------------------------------------------------------
template<class T>
void TSortTable<T>::SortQuick(string* _key, T* _data, T first, T last)
{
	if (first < last)
	{
		T l = first, r = last;
		T mid = _data[(l + r) / 2];
		do
		{
			while (_data[l] < mid) l++;
			while (_data[r] > mid) r--;
			if (l <= r)
			{
				T tmp = _data[l];
				_data[l] = _data[r];
				_data[r] = tmp;

				string temp = _key[l];
				_key[l] = _key[r];
				_key[r] = temp;

				l++;
				r--;
			}
		} while (l <= r);
		SortQuick(_key, _data, first, r);
		SortQuick(_key, _data, l, last);
	}
}
