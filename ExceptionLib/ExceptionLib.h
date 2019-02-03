#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exception
{
private:
	string str;
public:
	Exception(string _str) : str(_str) {}
	void Print() { cout << "\nWarning! \nMessage: " << str << endl; }
};
