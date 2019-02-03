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
	int beg = 0;
	int end = 0;

	TQueue<char> que(str.GetLength() * 3);
	TStack<char> st(str.GetLength() * 3);

	for (int i = 0; i < str.GetLength(); i++)
	{
		if (i == 0)
		{
			if (str[0] == '-')
			{
				que.Put('[');
				que.Put('0');
				que.Put(']');
			}
			else if (IsPolish(str[0]))
				if (GetPriority(str[0]) != 1)
					throw Exception("Error math expression");
		}
		if (isdigit(str[i]))
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
		else if (st.IsEmpty() && IsPolish(str[i]))
		{
			st.Put(str[i]);
			if (str[i] == '(')
				beg++;
			if (str[i] == ')')
				throw Exception("Error math expression");
		}
		else if (IsPolish(str[i]))
		{
			if (str[i] == '(')
			{
				st.Put(str[i]);
				beg++;
			}
			else if (str[i] == ')')
			{
				end++;
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
		else if (str[i] != '\0')
			throw Exception("Error math expression");
	}
	while (!st.IsEmpty())
		que.Put(st.Get());
	if (beg != end)
		throw Exception("Error math expression");
	return que;
}

//------------------------------------------------------------------------------
double Res(TQueue<char> que)
{
	double res = 0;
	TStack<double> st(que.GetLength());
	if (IsPolish(que.Top()))
		throw Exception("Error queue");
	int i = 0;
	int dit = 0;
	int tmp = 0;
	while (!que.IsEmpty())
	{
		i++;
		char c = que.Get();
		if (c == '[')
		{
			dit++;
			c = que.Get();
			double tmp = std::atof(&c);
			while (que.Top() != ']' && !que.IsEmpty())
			{
				c = que.Get();
				tmp = tmp * 10 + std::atof(&c);
			}
			que.Get();
			st.Put(tmp);
		}
		else if (IsPolish(c))
		{
			double A = st.Get();
			double B = st.Get();
			double C = 0;
			if (c == '+')
				C = B + A;
			if (c == '-')
				C = B - A;
			if (c == '*')
				C = B * A;
			if (c == '/')
				C = B / A;
			st.Put(C);
		}
		else
			throw Exception("Error symbol queue");
		if (i == 2 && dit != 2)
			throw Exception("Error queue");
	}
	res = st.Get();
	if (!st.IsEmpty())
		throw Exception("Error queue");
	return res;
}

//------------------------------------------------------------------------------
bool IsPolish(char s)
{
	return (s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')');
}