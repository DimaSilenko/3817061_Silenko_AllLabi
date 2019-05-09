#include "MultiStack.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

  cout << "Создадим свой мультистек\n";
  int tmp = 1;
	int numstack, data;

  try
  {
		cout << "Пусть наш мультистек имеет общую длину 10 и состоит из 5 стеков.\n";

    TMStack<int> mst(5, 10);

		cout << "Заполним наш мультистек:\n";

    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 2; j++)
      {
        mst.Set(i, tmp);
        cout <<"Число [" << tmp << "] кладем в стек под номером  " << i + 1 << endl;
				tmp++;
      }

    mst.PrintMStack();
    cout << "\n\n";

		cout << "Введите номер стека, из которого хотите изъять элемент: ";
		cin >> numstack;

		cout << "\nИз стека под номером [" << numstack << "] изъят элемент " << mst.Get(numstack - 1) << endl;

		mst.PrintMStack();

		cout << "\nВведите номер стека в которй хотите добавить элемент, если стек уже заполнен, мультистек перепакуется: ";
		cin >> numstack;

		cout << "Введите элемент, который хотите добавить: ";
		cin >> data;

		mst.Set(numstack-1, data);

    mst.PrintMStack();

  }

  catch (Exception exp)
  {
    exp.Print();
  }

  return 0;
}