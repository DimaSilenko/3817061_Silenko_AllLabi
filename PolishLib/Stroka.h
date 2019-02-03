#pragma once
#include <iostream>
#include "ExceptionLib.h"

class TString
{
protected:
  char* string;																						//Сама строка
  int length;																							//Длинна строки

public:
  TString();
  TString(TString &str);
  TString(char* _string);
  ~TString();

  int GetLength();																				//Получить длинну строки
  void DeleteString();																		//Удалить строку

  TString operator+(TString &str);
  TString& operator=(TString &str);
  char& operator[](int i);

  friend std::istream& operator>>(std::istream &istr, TString &str);
  friend std::ostream& operator<<(std::ostream &ostr, const TString &str);
};