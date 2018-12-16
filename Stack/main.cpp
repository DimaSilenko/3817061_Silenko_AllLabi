#include <iostream>
#include <locale.h>
#include "Stack.h"

using namespace std;

int  main (){
	TStack<int> St(2);
	if (St.IsEmpty())
	{
		St.Put(8);
		St.Put(9);
	}
	if (St.IsFull())
	{
		cout << "2:" << St.Get() << endl;
		cout << "1:" << St.Get() << endl;
	}

	return 0;
}