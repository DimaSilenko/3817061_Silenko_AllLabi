#include "Vector.h"

void main()
{
	float a[3] = { 1.1, 2.4, 3.4 };
	float b[3] = { 0.55, 1.2, 1.7 };
	int c[3] = { 1, 2, 3 };
	int d[3] = { 3, 2, 1 };

	TVector<float> A(a, 3);
	TVector<float> B(b, 3);
	TVector<int> C(c, 3);
	TVector<int> D(d, 3);
	TVector<int> Sum;
	TVector<float> Razn;
	TVector<float> Umn;
	TVector<float> Del;


	std::cout << A << "\n" << B << "\n" << C << "\n" << D << "\n";
	Sum = C + D;
	Razn = A - B;
	Umn = B * 2;
	Del = A / 2;
	float skal = A * B;
	std::cout << Sum << Razn << Umn << Del << skal << "\n";

	A.Transform(5);
	std::cout << A.GetDlina() << "\n";//

	C[1] = 0;
	std::cout << C << "\n";
	C[1] = 1;

	D.Sort();
	std::cout << D << "\n";

	B.Norm();
	std::cout << B << "\n";

	std::cout << A.OneNorm() << "\n" << A.TwoNorm() << "\n" << A.InfNorm() << "\n" << A.GelderNorm(3) << "\n";
}