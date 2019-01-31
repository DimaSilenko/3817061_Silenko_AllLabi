# pragma once
#include "NewStack.h"
#include "ExceptionLib.h"

template <class T>
class TMStack
{
protected:
  int length;                                 //длина мультистека
  T* elem;                                   //массив элементов мультистека
  int countst;                               //количество стеков в мультистеке
  TNewStack<T>** stackMas;                   //массив указателей на начало каждого стека в мультистеке
  int CountFree();                          //количество свободных элементов в мультистеке
  void Repack(int _st);                      //перепаковка стека с увеличением свободной памяти в стеке st

public:
  TMStack(int _countst = 1, int _length = 10);
  TMStack(TMStack &mst);

  int GetLength();                         //получить длину мультистека
	T Get(int _st);                         //взять элемент из стека под номером st
  void Set(int _st, T _elem);             //положить в стек st элемент _elem
  bool IsFull(int _st);                  //проверить на полноту стек st
  bool IsEmpty(int _st);                 //проверить на пустоту стек st

  void PrintMStack();                    //вывод мультистека на экран
};

//------------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack(int _countst, int _length)
{
  if (_countst <= 0 || _length <= 0)
    throw Exception("Error leight MultiStack");
  countst = _countst;
  length = _length;

  stackMas = new TNewStack<T>*[countst];
  elem = new T[length];

  int* tmp1 = new int[countst];
  for (int i = 0; i < countst; i++)
    tmp1[i] = length / countst;
  tmp1[0] += length % countst;

  T** tmp2 = new T*[countst];
  tmp2[0] = elem;
  for (int i = 1; i < countst; i++)
    tmp2[i] = tmp2[i - 1] + tmp1[i - 1];

  for (int i = 0; i < countst; i++)
    stackMas[i] = new TNewStack<T>(tmp1[i], tmp2[i]);
}

//------------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack(TMStack &mst)
{
  length = mst.length;
  countst = mst.countst;
  if (length == 0)
  {
    elem = NULL;
    stackMas = NULL;
  }
  else
  {
    elem = new T[length];
    for (int i = 0; i < countst; i++)
      elem[i] = mst.elem[i];

    stackMas = new TNewStack<T>*[countst];

    int* tmp1 = new int[countst];
    for (int i = 0; i < countst; i++)
      tmp1[i] = mst.stackMas[i]->GetLength();

    T** tmp2 = new T*[countst];
    tmp2[0] = elem;
    for (int i = 1; i < countst; i++)
      tmp2[i] = tmp1[i - 1] + tmp2[i - 1];

    for (int i = 0; i < countst; i++)
    {
      stackMas[i] = new TNewStack<T>(*mst.stackMas[i]);
      stackMas[i]->SetMas(tmp1[i], tmp2[i]);
    }
  }
}

//------------------------------------------------------------------------------
template <class T>
int TMStack<T>::GetLength()
{
  return length;
}

//------------------------------------------------------------------------------
template<class T>
T TMStack<T>::Get(int _st)
{
	if (_st < 0 || _st >= countst)
		throw Exception("Error index");
	if (IsEmpty(_st))
		throw Exception("Stack already Empty");
	return stackMas[_st]->Get();
}

//------------------------------------------------------------------------------
template<class T>
void TMStack<T>::Set(int _st, T _elem)
{
	if (_st < 0 || _st >= countst)
		throw Exception("Error index");
	else if (this->CountFree() == 0)
		throw Exception("MultiStack already Full");
	else if (IsFull(_st))
		Repack(_st);
	stackMas[_st]->Push(_elem);
}

//------------------------------------------------------------------------------
template<class T>
bool TMStack<T>::IsFull(int _st)
{
  if (_st < 0 || _st >= countst)
    throw Exception("Error index");
  return (stackMas[_st]->GetFreeCell() == 0);
}

//------------------------------------------------------------------------------
template<class T>
bool TMStack<T>::IsEmpty(int _st)
{
	if (_st < 0 || _st >= countst)
		throw Exception("Error index");
	return (stackMas[_st]->GetFreeCell() == stackMas[_st]->GetLength());
}

//------------------------------------------------------------------------------
template <class T>
int TMStack<T>::CountFree()
{
	int count = 0;
	for (int i = 0; i < countst; i++)
	{
		count += stackMas[i]->GetFreeCell();
	}
	return count;
}

//------------------------------------------------------------------------------
template <class T>
void TMStack<T>::Repack(int _st)
{
	int free = CountFree();
	int add_ev = free / countst;
	int add_full = free % countst;
	int* new_size = new int[countst];
	T** new_start = new T*[countst];
	T** old_start = new T*[countst];

	for (int i = 0; i < countst; i++)
		new_size[i] = add_ev + stackMas[i]->GetTop();
	new_size[_st] += add_full;

	new_start[0] = old_start[0] = elem;
	for (int i = 1; i < countst; i++)
	{
		new_start[i] = new_start[i - 1] + new_size[i - 1];
		old_start[i] = old_start[i - 1] + stackMas[i - 1]->GetLength();
	}

	for (int i = 0; i < countst; i++)
	{
		if (new_start[i] <= old_start[i])
			for (int j = 0; j < stackMas[i]->GetTop(); j++)
				new_start[i][j] = old_start[i][j];
		else
		{
			int s = i + 1;
			for (s; s < countst; s++)
				if (new_start[s] <= old_start[s])
					break;
			for (int j = s - 1; j >= i; j--)
				for (int r = stackMas[j]->GetTop() - 1; r >= 0; r--)
					new_start[j][r] = old_start[j][r];
			i = s - 1;
		}
	}
	for (int i = 0; i < countst; i++)
		stackMas[i]->SetMas(new_size[i], new_start[i]);
	delete[] new_size;
	delete[] new_start;
	delete[] old_start;
}

//------------------------------------------------------------------------------
template<class T>
void TMStack<T>::PrintMStack()
{
  int m = 0;
  cout << "\n\nМультистек:";
  for (int i = 0; i < countst; i++)
  {
    cout << endl << "Стек под номером: " << i + 1 << "\n";
    stackMas[i]->PrintNewStack();
  }
}