#include "Polish.h"

int  main()
{
	setlocale(LC_ALL, "Russian");

  try
  {
    cout << "������� �������������� ���������, ������� ����� ��������� ��������� � �������� ��������: ";
    TString str;
    cin >> str;

    cout << str << " � �������� ��������: ";
    TQueue<char> que;

    que = ConvertToPol(str);
    que.Print();

    cout << " = " << Res(que) << endl;
  }
  
  catch (Exception exp)
  {
    exp.Print();
  }
  return 0;
}
