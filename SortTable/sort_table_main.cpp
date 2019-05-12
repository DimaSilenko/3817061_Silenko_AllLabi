#include "SortTable.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

  TSortTable<int> table(6);
  TSortElem<int> elem;

	table.Put("k1", 1);
	table.Put("k2", 5);
	table.Put("k3", 10);
	table.Put("k4", 15);
	table.Put("k5", 20);
	table.Put("k6", 25);

	cout << "�������� ������� �� 6 ���������\n\n";

	cout << "���� �� ����� k1:\n";
	elem = table.Search("k1");
	cout << "�� �����: " << elem.GetKey() << " �������: " << elem.GetData() << "\n\n";

	cout << "���� �� ����� k2:\n";
	elem = table.Search("k2");
	cout << "�� �����: " << elem.GetKey() << " �������: " << elem.GetData() << "\n\n";

	cout << "������ ������� �� ����� k2\n\n";
	table.Del("k2");

	cout << "��������� ����� ����� ������� �� ����� k2:\n";
	elem = table.Search("k2");
	cout << "�� �����: " << elem.GetKey() << " �������: " << elem.GetData() << "\n\n";

	cout << "���� �� ����� k7:\n";
	elem = table.Search("k7");
	cout << "�� �����: " << elem.GetKey() << " �������: " << elem.GetData() << "\n\n";

  return 0;
}
 