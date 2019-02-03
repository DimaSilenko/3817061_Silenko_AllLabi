#include "Polish.h"
#include <cstdlib>

//------------------------------------------------------------------------------
int GetPriority(const char prior)
{
  switch (prior)
  {
  case '(':
    return 1;
  case ')':
    return 1;
  case '+':
    return 2;
  case '-':
    return 2;
  case '*':
    return 3;
  case '/':
    return 3;
  default:
    throw Exception("Error not operation");
  }
}

//------------------------------------------------------------------------------
TQueue<char> ConvertToPol(TString str)
{
	TQueue<char> que(str.GetLength() * 3);
	TStack<char> st(str.GetLength() * 3);

	for (int i = 0; i < str.GetLength(); i++)
	{
		if (i == 0)
			if (str[0] == '-')
			{
				que.Put('[');
				que.Put('0');
				que.Put(']');
			}
		if (isdigit(str[i]))       //проверяет аргумент, является ли он десятичной цифрой (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
		{
			que.Put('[');
			while ((i < str.GetLength()) && isdigit(str[i + 1]))
			{
				que.Put(str[i]);
				i++;
			}
			que.Put(str[i]);
			que.Put(']');
		}
		else if (st.IsEmpty())
			st.Put(str[i]);
		else if (IsPolish(str[i]))
		{
			if (str[i] == '(')
				st.Put(str[i]);
			else if (str[i] == ')')
			{
				while (st.Top() != '(')
					que.Put(st.Get());
				st.Get();
			}
			else
			{
				int p = GetPriority(str[i]);
				if (p > GetPriority(st.Top()))
					st.Put(str[i]);
				else if (p <= GetPriority(st.Top()))
				{
					while (!st.IsEmpty() && p <= GetPriority(st.Top()))
						que.Put(st.Get());
					st.Put(str[i]);
				}
			}
		}
	}
	while (!st.IsEmpty())
		que.Put(st.Get());
	return que;
}

//------------------------------------------------------------------------------
//double Res(TQueue<char> que)
//{
//  double res = 0;
//  TStack<double> st(que.GetLength());
//
//  while (!que.IsEmpty())
//  {
//    char s = que.Get();
//    if (s == '[')
//    {
//      s = que.Get();
//      double tmp = std::atof(&s);							//преобразует строку в double
//      while (que.Top() != ']' && !que.IsEmpty())
//      {
//        s = que.Get();
//        tmp = tmp * 10 + std::atof(&s);
//      }
//      que.Get();
//      st.Put(tmp);
//    }
//    if (IsPolish(s))
//    {
//      double d1 = st.Get();
//      double d2 = st.Get();
//      double d3 = 0;
//
//      if (s == '+')
//        d3 = d2 + d1;
//      if (s == '-')
//        d3 = d2 - d1;
//      if (s == '*')
//        d3 = d2 * d1;
//      if (s == '/')
//        d3 = d2 / d1;
//      st.Put(d3);
//    }
//  }
//  res = st.Get();
//  return res;
//}

double Res(TQueue<char> q)
{
	double res = 0;
	TStack<double> S(q.GetLength());
	while (!q.IsEmpty())
	{
		char A = q.Get();
		if (A == '[')
		{
			A = q.Get();
			double tmp = std::atof(&A);
			while (q.Top() != ']' && !q.IsEmpty())
			{
				A = q.Get();
				tmp = tmp * 10 + std::atof(&A);
			}
			q.Get();
			S.Put(tmp);
		}
		if (IsPolish(A))
		{
			double B = S.Get();
			double C = S.Get();
			double D = 0;
			if (A == '+')
				D = C + B;
			if (A == '-')
				D = C - B;
			if (A == '*')
				D = C * B;
			if (A == '/')
				D = C / B;
			S.Put(D);
		}
	}
	res = S.Get();
	return res;
}

//------------------------------------------------------------------------------
bool IsPolish(char s)
{
	return (s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')');
}