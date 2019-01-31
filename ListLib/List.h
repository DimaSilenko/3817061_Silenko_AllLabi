#pragma once 
#include "Elem.h"
#include "ExceptionLib.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
  TElem<T>* begin;            //указатель на элемент в начале списка
  int count;                  //количество элементов в списке 

public:
  TList();                    //конструктор по умолчанию
  TList(TList<T> &lst);       //конструктор копирования
  virtual ~TList();           //деструктор

  int GetSize();              //получить количество элементов в листе

  void Put(int pos, T elem);   //положить элемент на позицию n в списке
	void PutBegin(T el);        //положить в начало 
	void PutEnd(T el);          //положить в конец 
  T Get(int pos);              //получить элемент из списка
  T GetBegin();               //получить элемент в начале списка 
  T GetEnd();                 //получить элемент в конце списка

  bool IsFull();              //проверка на полноту 
  bool IsEmpty();             //проверка на пустоту 

  void Print();               //вывод листа на экран
};

//-------------------------------------------------------------------------------
template <class T>
TList<T>::TList()
{
  begin = 0;
  count = 0;
}

//-------------------------------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &lst)
{
  count = lst.count;
  TElem<T>* tmpElem1 = lst.begin;
  TElem<T>* tmpElem2;
  if (lst.begin == 0)
    begin = 0;
  else
  {
    begin = new TElem<T>(*lst.begin);
    tmpElem2 = begin;
    while (tmpElem1->GetNext() != 0)
    {
      tmpElem2->SetNext(new TElem<T>(*(tmpElem1->GetNext())));
      tmpElem1 = tmpElem1->GetNext();
      tmpElem2 = tmpElem2->GetNext();
    }
  }
}

//-------------------------------------------------------------------------------
template <class T>
TList<T>::~TList()
{
  while (begin != 0)
  {
    TElem<T>* temp = begin;
    begin = begin->GetNext();
    delete temp;
  }
}

//-------------------------------------------------------------------------------
template<class T>
int TList<T>::GetSize()
{
  return count;
}

//-------------------------------------------------------------------------------
template<class T>
void TList<T>::Put(int pos, T elem)
{
  if (this->IsFull())
    throw Exception("List already Full");
  if (pos < 1 || pos > count - 1)
    throw Exception("Error index");
  else
  {
    int i = 0;
    TElem<T>* tmpElem = begin;
    while (i != pos - 1)
    {
      tmpElem = tmpElem->GetNext();
      i++;
    }
    TElem<T>* temp = new TElem<T>(elem, tmpElem->GetNext());
    tmpElem->SetNext(temp);
    count++;
  }
}

//-------------------------------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T el)
{
  if (this->IsFull())
    throw Exception("List already Full");
  if (begin == 0)
  {
    TElem<T>* temp = new TElem<T>(el, 0);
    begin = temp;
  }
  else
  {
    TElem<T>* temp = new TElem <T>(el, begin);
    begin = temp;
  }
  count++;
}

//-------------------------------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T el)
{
  if (this->IsFull())
    throw Exception("List already Full");
  if (begin != 0)
  {
    TElem<T>* temp = begin;
    while (temp->GetNext() != 0)
      temp = temp->GetNext();
    temp->SetNext(new TElem <T>(el, 0));
  }
  else
    begin = new TElem<T>(el, 0);
  count++;
}

//-------------------------------------------------------------------------------
template<class T>
T TList<T>::Get(int pos)
{
	if (this->IsEmpty())
		throw Exception("List already Empty");
	if (pos < 1 || pos > count - 1)
		throw Exception("Error index");
	else
	{
		int i = 0;
		count--;
		TElem<T>* temp1 = begin;
		TElem<T>* temp2 = begin->GetNext();
		while (i != pos - 1)
		{
			temp1 = temp2;
			temp2 = temp2->GetNext();
			i++;
		}
		T temp = temp2->GetData();
		temp1->SetNext(temp2->GetNext());
		delete temp2;
		return temp;
	}
}

//-------------------------------------------------------------------------------
template <class T>
T TList<T>::GetBegin()
{
  if (IsEmpty())
    throw Exception("List already Empty");
  else
  {
    TElem<T>* tempElem = begin;
    T temp = begin->TElem<T>::GetData();
    begin = begin->TElem<T>::GetNext();
    delete tempElem;
    count--;
    return temp;
  }
}

//-------------------------------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{
  if (IsEmpty())
    throw Exception("List already Empty");
  else
  {
    count--;
    TElem<T>* tempElem1 = begin;
    TElem<T>* tempElem2 = begin->GetNext();
    if (tempElem2 == 0)
    {
      T temp = tempElem1->TElem<T>::GetData();
      delete tempElem1;
      begin = 0;
      return temp;
    }
    else
    {
      while (tempElem2->GetNext() != 0)
      {
        tempElem1 = tempElem2;
        tempElem2 = tempElem2->GetNext();
      }
      T temp = tempElem2->GetData();
      delete tempElem2;
      tempElem1->SetNext(0);
      return temp;
    }
  }
}

//-------------------------------------------------------------------------------
template <class T>
bool TList<T>::IsFull()
{
  try
  {
    TElem<T>* temp = new TElem<T>();
    if (temp == NULL)
      return 1;
    else
    {
      delete temp;
      return 0;
    }
  }
  catch (...)
  {
    return 0;
  }
  return  1;
}

//-------------------------------------------------------------------------------
template <class T>
bool TList<T>::IsEmpty()
{
  if (begin == 0)
    return 1;
  return 0;
}

//-------------------------------------------------------------------------------
template<class T>
inline void TList<T>::Print()
{
	if (begin == 0)
		throw Exception("List already Empty");
	else
	{
		TElem<T>* tempElem = begin;
		while (tempElem->GetNext() != 0)
		{
			cout << tempElem->GetData() << " ";
			tempElem = tempElem->GetNext();
		}
		cout << tempElem->GetData() << " ";
	}
}