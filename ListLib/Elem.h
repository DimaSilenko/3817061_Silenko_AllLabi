#pragma once

template <class T>
class TElem
{
protected:
	T data;                                   //данные (значение) которые хранит элемент
	TElem <T>* next;                          //указатель на следующий элемент
public:
	TElem(T _data = 0, TElem <T>* _next = 0); //конструктор по умолчанию
	TElem(TElem<T> &el);                      //конструктор копирования
	virtual ~TElem();                         //деструктор

	void SetData(T el);                       //положить значение элемента
	void SetNext(TElem <T>* _next);           //указать адрес следующего элемента
	T GetData();                              //получить значение элемента
	TElem* GetNext();                         //получить адрес следующего элемента
};

//-------------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(T _data, TElem<T>* _next)
{
	data = _data;
	next = _next;
}

//-------------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(TElem<T> &el)
{
	data = el.data;
	next = el.next;
}

//-------------------------------------------------------------------------------
template <class T>
TElem<T>::~TElem() {}

//-------------------------------------------------------------------------------
template <class T>
void TElem<T>::SetData(T el)
{
	data = el;
}

//-------------------------------------------------------------------------------
template <class T>
void TElem<T>::SetNext(TElem<T>* _next)
{
	next = _next;
}

//-------------------------------------------------------------------------------
template <class T>
T TElem<T>::GetData()
{
	return data;
}

//-------------------------------------------------------------------------------
template <class T>
TElem<T>* TElem<T>::GetNext()
{
	return next;
}