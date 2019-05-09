#pragma once
#include <iostream>
#include "TableElem.h"

template <class T>
class TTable
{
protected:
	TElem<T> notFound;	//������� �� ������
	TElem<T> *mas;			//������ ��������� �������
	int length;					//����� �������
	int count;					//���������� ��������� � �������
public:
	TTable(int _length = 10);						
	TTable(TTable &table);

	void SetCount(int _count);				//������ ���������� ��������� � �������
	void SetLength(int _length);				//������ ����� �������

	int GetLength();									//�������� ����� �������
	int GetCount();										//�������� ���������� ��������� � �������

	void Put(string _key, T _data);		//�������� ������� � �������
	void Del(string _key);						//������� ������� �� �������

	TElem<T>& Search(string _key);		//����� �������� � �������
	T& operator[](string _key);				//������ � �������� �� �����
	
};

// ---------------------------------------------------------------------------
template <class T>
TTable<T>::TTable(int _length)
{
	if (_length < 0)
		throw Exception("Error size!\n");

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
		mas = new TElem<T>[length];
	}
}

// ---------------------------------------------------------------------------
template <class T>
TTable<T>::TTable(TTable &table)
{
	length = table.length;
	count = table.count;
	mas = new TElem<T>[length];
	for (int i = 0; i < length; i++)
		mas[i] = table.mas[i];
}

// ---------------------------------------------------------------------------
template <class T>
void TTable<T>::SetCount(int _count)
{
	count = _count;
}

// ---------------------------------------------------------------------------
template <class T>
void TTable<T>::SetLength(int _size)
{
	length = _size;
}

// ---------------------------------------------------------------------------
template <class T>
int TTable<T>::GetLength()
{
	return length;
}

// ---------------------------------------------------------------------------
template <class T>
int TTable<T>::GetCount()
{
	return count;
}

// ---------------------------------------------------------------------------
template <class T>
void TTable<T>::Put(string _key, T _data)
{
	if (length == count)
		throw Exception("Table already full\n");
	else
	{
		mas[count].SetKey(_key);
		mas[count].SetData(_data);
		count++;
	}
}

// ---------------------------------------------------------------------------
template <class T>
void TTable<T>::Del(string _key)
{
	if (count == 0)
		throw Exception("Table already empty\n");

	else
	{
		TElem<T>& tmp = Search(_key);
		if (!(tmp == notFound))
			tmp = notFound;
	}
}

// ---------------------------------------------------------------------------
template <class T>
TElem<T>& TTable<T>::Search(string _key)
{
	for (int i = 0; i < count; i++)
		if (_key == mas[i].GetKey())
			return mas[i];
	return notFound;
}

// ---------------------------------------------------------------------------
template <class T>
T& TTable<T>::operator[](string _key)
{
	TElem<T>& tmp = Search(_key);
	if (tmp == notFound)
	{
		Put(_key, 0);
		return mas[count - 1].GetDataAddress();
	}
	return tmp.GetDataAddress();
}