#include <iostream>
#include <locale.h>
#include "Stack.h"
#include "ExceptionLib.h"

using namespace std;

int  main ()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ������ �����: ";
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
			cout << "\n���� ��������� ���� ������: \n";
			st.PrintStack();
		}

		TStack<int> CopySt(st);
		cout << "\n\n������������� ����: \n";
		CopySt.PrintStack();

		if (CopySt == st)
			cout << "\n\n������������� � ��������� ���������� ����� �����";

		cout << "\n\n������� ������� �� �����: " << st.Get();

		cout << "\n\n������ � ��� ���� ����: \n";
		st.PrintStack();

		if (CopySt != st)
			cout << "\n\n� ������ ���� ����������� � ������������� ��������";
	}

	catch (Exception exp)
	{
		exp.Print();
	}
	return 0;
}