#include "Vector.h"

int main()
{
	cout << "Vectors:\n";
	TVector <int> V1(3), V2(3), Res(3);
	for (int i = 0; i < 3; i++)
	{
		V1[i] = (i + 1 - (i + 2) * 4);
		V2[i] = (i * 6 + 3 - i) * 2;
	}
	cout << "\nV1: " << V1 << endl;
	cout << "V2: " << V2 << endl;

	cout << "\n\nOperations Arifm:\n\n";
	try
	{
		Res = V1 + V2;
		cout << "Result V1 + V2: " << Res << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	try
	{
		Res = V1 - V2;
		cout << "Result V1 - V2: " << Res << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	try
	{
		int k = V1 * V2;
		cout << "Result V1 * V2: " << k << endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}

	cout << "\n\nUse your input / output streams:\n";
	TVector <int> V(5);
	cin >> V;
	cout << "\nYour vector: " << V << endl;
	return 0;
}