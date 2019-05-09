#pragma once

template <class T>
class TElem
{
protected:
	T data;                                   //������ (��������) ������� ������ �������
	TElem <T>* next;                          //��������� �� ��������� �������
public:
	TElem(T _data = 0, TElem <T>* _next = 0); //����������� �� ���������
	TElem(TElem<T> &el);                      //����������� �����������
	virtual ~TElem();                         //����������

	void SetData(T el);                       //�������� �������� ��������
	void SetNext(TElem <T>* _next);           //������� ����� ���������� ��������
	T GetData();                              //�������� �������� ��������
	TElem* GetNext();                         //�������� ����� ���������� ��������
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