#include "StackList.h"

int main()
{
	setlocale(LC_ALL, "Russian");

  cout << "Введите размер стека: ";
  int len;
  cin >> len;

  try
  {
    TStackList<int> stlst(len);

    for (int i = 0; i < len; i++)
    {
      stlst.Put(i);
    }

		if (stlst.IsFull())
		{
			cout << "\nСтек выбранной вами длинны: \n";
			stlst.PrintStLst();
			cout << "\nСтек полон.\n";
		}
  
		cout << "\nПервый элемент в стеке: " << stlst.Get() << endl;
		cout << "Теперь это стек:\n";
		stlst.PrintStLst();
		cout << "\nЕго текущая длина = " << stlst.GetLength() << "\nВ то время как максимальная длина = " << stlst.GetMaxLength() << endl;

		cout << "\nВыведем весь оставшийся стек:\n";
		int j = 1;

    while (!stlst.IsEmpty())
     cout << "Элемент под номером " << j++ << " : " << stlst.Get() << endl;
    cout << "Стек пуст.\n";
  }

  catch (Exception exp)
  {
    exp.Print();
  }
  return 0;
}