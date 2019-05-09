#include "List.h"
#include <cstdlib>
#include <iomanip>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		TList<int> list;
		int position, data;

		cout << "Введите количество элементов, которые вы хотели бы поместить в начало списка: ";
		int _begin, _end;
		cin >> _begin;

	
		for (int i = 1; i <= _begin; i++)
			list.PutBegin(i);
		
		cout << "\nВведите количество элементов, которые вы хотели бы поместить в конец списка: ";
		cin >> _end;

		for (int i = 1; i <= _end; i++)
			list.PutEnd(i);

		cout << "\nВот получившийся лист:\n";
		list.Print();

		cout << "\n\nПервый элемент в списке: " << list.GetBegin();
		cout << "\nПоследний элемент в списке: " << list.GetEnd();

		cout << "\n\nСписок без этих элементов:\n";
		list.Print();

		cout << "\nВведите номер позиции, отличный от начала и конца, куда вы хотите поместить новый эелемент:\n";
		cin >> position;

		cout << "Введите сам элемент:\n";
		cin >> data;

		list.Put(position - 1, data);
		cout << "Обновленный список:\n";
		list.Print();
	}

	catch (Exception exc)
	{
		exc.Print();
	}

	return 0;
}
