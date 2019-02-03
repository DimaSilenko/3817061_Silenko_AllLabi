#include "Polish.h"

int  main()
{
	setlocale(LC_ALL, "Russian");

  try
  {
    cout << "Введите математическое выражение, которое будет сосчитано переводом в обратную польскую: ";
    TString str;
    cin >> str;

    cout << str << " в обратной польской: ";
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
