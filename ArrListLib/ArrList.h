#pragma once
#include "ExceptionLib.h"
#include "Queue.h"

template <class T>
class TArrList
{
private:
  T* elems;                  //Массив элементов списка
  int *nextInd;              //Массив индексов, указывающих на следующий элемент списка
  int *previousInd;          //Массив индексов, указывающих на предыдущий элемент списка

  int length;                //Длина списка
  int count;                 //Количество элементов в списке
  int start;                 //Индекс первого элемента списка
  int end;                   //Индекс последнего элемента списка

  TQueue <int> freeElem;     //Очередь "пустых" ячеек в массиве  

public:
  TArrList(int _size = 10);  //Конструктор с параметром
  TArrList(TArrList<T> &arrlst);  //Конструктор копирования
  ~TArrList();               //Деструктор

  void Put(int pos, T elem);   //Добавить промежуточный элемент
	void PutStart(T elem);     //Положить в начало списка
	void PutEnd(T elem);       //Положить в конец списка

  T Get(int pos);              //Извлечь промежуточный элемент  
  T GetStart();              //Извлечь из начала списка
  T GetEnd();                //Извлечь из конца списка

  bool IsFull();             //Проверка на полноту
  bool IsEmpty();            //Проверка на пустоту

  void Print();              //Печать списка
};

//---------------------------------------------------------------------
template <class T>
TArrList<T>::TArrList(int _size) : freeElem(_size)
{
  if (_size <= 0)
    throw Exception("Error size list");
  length = _size;
  count = 0;
  start = -1;
  end = -1;
  elems = new T[length];
  nextInd = new int[length];
  previousInd = new int[length];
  for (int i = 0; i < length; i++)
  {
    nextInd[i] = -2;
    previousInd[i] = -2;
    freeElem.Put(i);
  }
}

//---------------------------------------------------------------------
template <class T>
TArrList<T>::TArrList(TArrList<T> &arrlst)
{
  start = arrlst.start;
  end = arrlst.end;
  length = arrlst.length;
  count = arrlst.count;
  elems = new T[length];
  nextInd = new int[length];
  previousInd = new int[length];
  freeElem = arrlst.freeElem;
  for (int i = 0; i < length; i++)
  {
    elems[i] = arrlst.elems[i];
    nextInd[i] = arrlst.nextInd[i];
    previousInd[i] = arrlst.previousInd[i];
  }
}

//---------------------------------------------------------------------
template<class T>
inline TArrList<T>::~TArrList()
{
  delete[] elems;
  delete[] nextInd;
  delete[] previousInd;
}

//---------------------------------------------------------------------
template<class T>
void TArrList<T>::Put(int pos, T elem)
{
  if (IsFull())
    throw Exception("Error list already Full");
  if (pos < 1 || pos > count - 1)
    throw Exception("Error index");

  int tmpfree = freeElem.Get();
  elems[tmpfree] = elem;
  int one = start;
  int two = nextInd[start];
  for (int i = 0; i < pos - 1; i++)
  {
    one = two;
    two = nextInd[two];
  }
  nextInd[tmpfree] = two;
  nextInd[one] = tmpfree;

  previousInd[tmpfree] = one;
  previousInd[two] = tmpfree;
  count++;
}

//---------------------------------------------------------------------
template <class T>
void TArrList<T>::PutStart(T elem)
{
	if (IsFull())
		throw Exception("Error list already Full");

	int tmpfree = freeElem.Get();
	elems[tmpfree] = elem;
	nextInd[tmpfree] = start;
	if (start != -1)
		previousInd[start] = tmpfree;
	else
		end = tmpfree;
	start = tmpfree;
	count++;
}

//---------------------------------------------------------------------
template <class T>
void TArrList<T>::PutEnd(T elem)
{
	if (IsFull())
		throw Exception("Error list already Full");

	int tmpfree = freeElem.Get();
	elems[tmpfree] = elem;
	if (end != -1)
		nextInd[end] = tmpfree;
	else
	{
		start = tmpfree;
		previousInd[tmpfree] = -1;
	}
	previousInd[tmpfree] = end;
	end = tmpfree;
	count++;
}

//---------------------------------------------------------------------
template<class T>
T TArrList<T>::Get(int pos)
{
  if (IsEmpty())
    throw Exception("Error list already Empty");
  if (pos < 1 || pos > count - 1)
    throw Exception("Error index");
  int ind = start;
  for (int i = 0; i < pos; i++)
    ind = nextInd[ind];
  nextInd[previousInd[ind]] = nextInd[ind];
  previousInd[nextInd[ind]] = previousInd[ind];
  T temp = elems[ind];
  freeElem.Put(ind);
  count--;
  return temp;
}

//---------------------------------------------------------------------
template <class T>
T TArrList<T>::GetStart()
{
  if (IsEmpty())
    throw Exception("Error list already Empty");

  T elem = elems[start];
  freeElem.Put(start);
  int newstart = nextInd[start];
  nextInd[start] = previousInd[start] = -2;
  if (newstart != -1)
    previousInd[newstart] = -1;
  count--;
  start = newstart;
  return elem;
}

//---------------------------------------------------------------------
template <class T>
T TArrList<T>::GetEnd()
{
  if (IsEmpty())
    throw Exception("Error list already Empty");

  T elem = elems[end];
  int newFinish = previousInd[end];
  previousInd[end] = nextInd[end] = -2;
  freeElem.Put(end);
  end = newFinish;
  if (newFinish != -1)
    nextInd[newFinish] = -1;
  else
    start = -1;
  count--;
  return elem;
}

//---------------------------------------------------------------------
template <class T>
bool TArrList<T>::IsFull()
{
  if (count == length)
    return true;
  return false;
}

//---------------------------------------------------------------------
template <class T>
bool TArrList<T>::IsEmpty()
{
  if (count == 0)
    return true;
  return false;
}

//---------------------------------------------------------------------
template<class T>
inline void TArrList<T>::Print()
{
  int tmp = start;
  for (int i = 0; i < count; i++)
  {
    cout << elems[tmp] << " ";
    tmp = nextInd[tmp];
  }
}