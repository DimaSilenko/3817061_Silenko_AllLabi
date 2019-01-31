#include "MultiStack.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

  cout << "�������� ���� ����������\n";
  int tmp = 1;
	int numstack, data;

  try
  {
		cout << "����� ��� ���������� ����� ����� ����� 10 � ������� �� 5 ������.\n";

    TMStack<int> mst(5, 10);

		cout << "�������� ��� ����������:\n";

    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 2; j++)
      {
        mst.Set(i, tmp);
        cout <<"����� [" << tmp << "] ������ � ���� ��� �������  " << i + 1 << endl;
				tmp++;
      }

    mst.PrintMStack();
    cout << "\n\n";

		cout << "������� ����� �����, �� �������� ������ ������ �������: ";
		cin >> numstack;

		cout << "\n�� ����� ��� ������� [" << numstack << "] ����� ������� " << mst.Get(numstack - 1) << endl;

		mst.PrintMStack();

		cout << "\n������� ����� ����� � ������ ������ �������� �������, ���� ���� ��� ��������, ���������� ������������: ";
		cin >> numstack;

		cout << "������� �������, ������� ������ ��������: ";
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