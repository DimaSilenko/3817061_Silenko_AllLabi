#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception 
{
private:
  string str;
public:
  Exception(std::string _str);
  void Print();
};

Exception::Exception(std::string _str) : str(_str) {}

void Exception::Print()
{
  cout << "\nWarning! \nMessage: " << str << endl;
}
