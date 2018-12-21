#include "Matrix.h"
#include <cstdlib>
#include <iomanip>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(static_cast<unsigned int>(time(0)));
	double ra, nd, om;

  cout << "Матрицы: \n";
  TMatrix<double> M1(5), M2(5), Res(5);
	TMatrix<double> MDel(5);
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5 - i; j++) 
    {
			ra = rand();
			nd = ra / RAND_MAX;
			om = nd * 49 + 1;

			M1[i][j] = om;

			ra = rand();
			nd = ra / RAND_MAX;
			om = nd * 49 + 1;

			M2[i][j] = om;
    }
  cout << "\nМатрица 1:" << endl << M1 << endl;
  cout << "\nМатрица 2:" << endl << M2 << endl;

  cout << "\nАрифметические операции: \n\n";
  try {
    Res = M1 + M2;
    cout << "Матрица 1 + Матрица 2:" << endl << Res << endl;
  }
  catch (Exception exp)
  {
    exp.Print();
  }

  try {
    Res = M1 - M2;
    cout << "Матрица 1 - Матрица 2:" << endl << Res << endl;
  }
  catch (Exception exp)
  {
    exp.Print();
  }

  try {
    Res = M1 * M2;
    cout << "Матрица 1 * Матрица 2:" << endl << Res << endl;
  }
  catch (Exception exp)
  {
    exp.Print();
  }

	try {
		MDel = M1 / M2;
		cout << "Матрица 1 / Матрица 2:" << endl  << MDel << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

  cout << "\n\nВведите матрицу размерности 3:\n";
  TMatrix <int> MT(3);
  cin >> MT;
  cout << "\nВведенная вами матрица:" << endl << MT;

	//тестирование скорости
	/*TMatrix <int> MTest1(3000);
	TMatrix <int> MTest2(3000);
	TMatrix <int> MTest3(3000);

	for (int i = 0; i < 3000; i++)
	{
		for (int j = 0; j < 3000 - i; j++)
		{
			MTest1[i][j] = rand();
			MTest2[i][j] = rand();
		}
	}
	int start = clock();
	MTest3 = MTest1 + MTest2;
	int end = clock();

	cout << "Время: " << (end - start) << endl;*/

  return 0;
}