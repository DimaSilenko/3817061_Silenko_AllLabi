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

	cout << "Создадим таблицу из 6 элементов\n\n";

	cout << "Ищем по ключу k1:\n";
	elem = table.Search("k1");
	cout << "По ключу: " << elem.GetKey() << " найдено: " << elem.GetData() << "\n\n";

	cout << "Ищем по ключу k2:\n";
	elem = table.Search("k2");
	cout << "По ключу: " << elem.GetKey() << " найдено: " << elem.GetData() << "\n\n";

	cout << "Удалим элемент по ключу k2\n\n";
	table.Del("k2");

	cout << "Попробуем снова найти элемент по ключу k2:\n";
	elem = table.Search("k2");
	cout << "По ключу: " << elem.GetKey() << " найдено: " << elem.GetData() << "\n\n";

	cout << "Ищем по ключу k7:\n";
	elem = table.Search("k7");
	cout << "По ключу: " << elem.GetKey() << " найдено: " << elem.GetData() << "\n\n";

  return 0;
}
 