#include <iostream>
#include"Queue.h"
using namespace std;

int main ()
{  
	setlocale(LC_ALL, "Russian");

	int len;
	cout << "Введите длину очереди\n";
	cin >> len;
	try
	{
		TQueue<int> qu(len);
		for (int i = 0; i < len; i++)
		{
			qu.Put(i);
			cout << "В очередь введено " << i << endl;
		}

		cout << endl;

		while (!qu.IsEmpty())
		{
			len = qu.Get();
			cout << "В очереди лежит " << len << endl;
		}
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	return 0;
}