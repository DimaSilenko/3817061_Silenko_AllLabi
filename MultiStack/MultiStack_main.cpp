#include "MultiStack.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

  cout << "—оздадим свой мультистек\n";
  int tmp = 1;
	int numstack, data;

  try
  {
		cout << "ѕусть наш мультистек имеет общую длину 10 и состоит из 5 стеков.\n";

    TMStack<int> mst(5, 10);

		cout << "«аполним наш мультистек:\n";

    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 2; j++)
      {
        mst.Set(i, tmp);
        cout <<"„исло [" << tmp << "] кладем в стек под номером  " << i + 1 << endl;
				tmp++;
      }

    mst.PrintMStack();
    cout << "\n\n";

		cout << "¬ведите номер стека, из которого хотите изъ€ть элемент: ";
		cin >> numstack;

		cout << "\n»з стека под номером [" << numstack << "] изъ€т элемент " << mst.Get(numstack - 1) << endl;

		mst.PrintMStack();

		cout << "\n¬ведите номер стека в которй хотите добавить элемент, если стек уже заполнен, мультистек перепакуетс€: ";
		cin >> numstack;

		cout << "¬ведите элемент, который хотите добавить: ";
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