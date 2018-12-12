#include "Matrix.h"

int main()
{
  cout << "Matrix: \n";
  TMatrix<int> M1(5), M2(5), Res(5);
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5 - i; j++) 
    {
      M1[i][j] = (i + 3) * (j + 3) -1;
      M2[i][j] = (i * 8 + j + 3 + i) * 2;
    }
  cout << "\nM1:" << endl << M1 << endl;
  cout << "\nM2:" << endl << M2 << endl;

  cout << "\nOperations Arifm: \n\n";
  try {
    Res = M1 + M2;
    cout << "Result M1 + M2:" << endl << Res << endl;
  }
  catch (Exception exp)
  {
    exp.Print();
  }

  try {
    Res = M1 - M2;
    cout << "Result M1 - M2:" << endl << Res << endl;
  }
  catch (Exception exp)
  {
    exp.Print();
  }

  try {
    Res = M1 * M2;
    cout << "Result M1 * M2:" << endl << Res << endl;
  }
  catch (Exception exp)
  {
    exp.Print();
  }

  cout << "\n\nUse your input / output streams:\n";
  TMatrix <int> MT(3);
  cin >> MT;
  cout << "\nYour matrix:" << endl << MT;
  return 0;
}