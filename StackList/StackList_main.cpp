#include "StackList.h"

int main()
{
	setlocale(LC_ALL, "Russian");

  cout << "������� ������ �����: ";
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
			cout << "\n���� ��������� ���� ������: \n";
			stlst.PrintStLst();
			cout << "\n���� �����.\n";
		}
  
		cout << "\n������ ������� � �����: " << stlst.Get() << endl;
		cout << "������ ��� ����:\n";
		stlst.PrintStLst();
		cout << "\n��� ������� ����� = " << stlst.GetLength() << "\n� �� ����� ��� ������������ ����� = " << stlst.GetMaxLength() << endl;

		cout << "\n������� ���� ���������� ����:\n";
		int j = 1;

    while (!stlst.IsEmpty())
     cout << "������� ��� ������� " << j++ << " : " << stlst.Get() << endl;
    cout << "���� ����.\n";
  }

  catch (Exception exp)
  {
    exp.Print();
  }
  return 0;
}