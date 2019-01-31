#include "ArrList.h"

int main()
{
	try
	{
		setlocale(LC_ALL, "Russian");
		int position, data;

		cout << "Введите размер листа: ";
		int size;
		cin >> size;
		cout << endl;
		TArrList<int> arrlst(size);
		int i;
		for (i = 1; i <= size / 2; i++)
		{
			cout << "Кладем в начало: " << i << endl;
			arrlst.PutStart(i);
		}
		for (i; i <= size; i++)
		{
			cout << "Кладем в конец: " << i << endl;
			arrlst.PutEnd(i);
		}

		cout << "\n\nСоздали лист:" << endl;
		arrlst.Print();
		cout << endl;


		cout << "Первый элемент: " << arrlst.GetStart();

		cout << "\nПоследний элемент: " << arrlst.GetEnd();

		cout << "\nСписок без первого и последнего:\n";
		arrlst.Print();

		cout << "\nВведите номер элемента, который мы добавим к этому списку, отличный от начала и конца: ";
		cin >> position;

		cout << "\nА теперь введите и само значение этого элемента:";
		cin >> data;

		arrlst.Put(position - 1, data);

		cout << "\nОбновленный список:\n";
		arrlst.Print();

		cout << "\nТеперь введите номер элемента, которы вы хотите изъять из списка, отличный от начала и конца: ";
		cin >> position;

		cout << "\nЭтот элемент: " << arrlst.Get(position - 1) << endl;
	}

	catch (Exception exc)
	{
		exc.Print();
	}


  return 0;
}
