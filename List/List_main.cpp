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

		cout << "������� ���������� ���������, ������� �� ������ �� ��������� � ������ ������: ";
		int _begin, _end;
		cin >> _begin;

	
		for (int i = 1; i <= _begin; i++)
			list.PutBegin(i);
		
		cout << "\n������� ���������� ���������, ������� �� ������ �� ��������� � ����� ������: ";
		cin >> _end;

		for (int i = 1; i <= _end; i++)
			list.PutEnd(i);

		cout << "\n��� ������������ ����:\n";
		list.Print();

		cout << "\n\n������ ������� � ������: " << list.GetBegin();
		cout << "\n��������� ������� � ������: " << list.GetEnd();

		cout << "\n\n������ ��� ���� ���������:\n";
		list.Print();

		cout << "\n������� ����� �������, �������� �� ������ � �����, ���� �� ������ ��������� ����� ��������:\n";
		cin >> position;

		cout << "������� ��� �������:\n";
		cin >> data;

		list.Put(position - 1, data);
		cout << "����������� ������:\n";
		list.Print();
	}

	catch (Exception exc)
	{
		exc.Print();
	}

	return 0;
}
