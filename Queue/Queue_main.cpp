#include <iostream>
#include"Queue.h"
using namespace std;

int main ()
{  
	setlocale(LC_ALL, "Russian");

	int len;
	cout << "������� ����� �������\n";
	cin >> len;
	try
	{
		TQueue<int> qu(len);
		for (int i = 0; i < len; i++)
		{
			qu.Put(i);
			cout << "� ������� ������� " << i << endl;
		}

		cout << endl;

		while (!qu.IsEmpty())
		{
			len = qu.Get();
			cout << "� ������� ����� " << len << endl;
		}
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	return 0;
}