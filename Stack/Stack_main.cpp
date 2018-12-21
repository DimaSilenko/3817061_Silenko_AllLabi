#include <iostream>
#include <locale.h>
#include "Stack.h"
#include "ExceptionLib.h"

using namespace std;

int  main ()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите размер стека: ";
	int len;
	cin >> len;

	try
	{
		TStack<int> st(len);
		for (int i = 0; i < len; i++)
		{
			st.Put(i);
		}
	
		if (st.IsFull())
		{
			cout << "\nСтек выбранной вами длинны: \n";
			st.PrintStack();
		}

		TStack<int> CopySt(st);
		cout << "\n\nСкопированный стек: \n";
		CopySt.PrintStack();

		if (CopySt == st)
			cout << "\n\nСкопированный и введенный изначально стеки равны";

		cout << "\n\nВозьмем элемент из стека: " << st.Get();

		cout << "\n\nТеперь у нас есть стек: \n";
		st.PrintStack();

		if (CopySt != st)
			cout << "\n\nИ теперь стек изначальный и скопированный различны";
	}

	catch (Exception exp)
	{
		exp.Print();
	}
	return 0;
}