#include "ArrList.h"

int main()
{
	try
	{
		setlocale(LC_ALL, "Russian");
		int position, data;

		cout << "������� ������ �����: ";
		int size;
		cin >> size;
		cout << endl;
		TArrList<int> arrlst(size);
		int i;
		for (i = 1; i <= size / 2; i++)
		{
			cout << "������ � ������: " << i << endl;
			arrlst.PutStart(i);
		}
		for (i; i <= size; i++)
		{
			cout << "������ � �����: " << i << endl;
			arrlst.PutEnd(i);
		}

		cout << "\n\n������� ����:" << endl;
		arrlst.Print();
		cout << endl;


		cout << "������ �������: " << arrlst.GetStart();

		cout << "\n��������� �������: " << arrlst.GetEnd();

		cout << "\n������ ��� ������� � ����������:\n";
		arrlst.Print();

		cout << "\n������� ����� ��������, ������� �� ������� � ����� ������, �������� �� ������ � �����: ";
		cin >> position;

		cout << "\n� ������ ������� � ���� �������� ����� ��������:";
		cin >> data;

		arrlst.Put(position - 1, data);

		cout << "\n����������� ������:\n";
		arrlst.Print();

		cout << "\n������ ������� ����� ��������, ������ �� ������ ������ �� ������, �������� �� ������ � �����: ";
		cin >> position;

		cout << "\n���� �������: " << arrlst.Get(position - 1) << endl;
	}

	catch (Exception exc)
	{
		exc.Print();
	}


  return 0;
}
