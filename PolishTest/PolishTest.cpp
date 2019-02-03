#include "gtest.h"
#include "Polish.h"

TEST(Polish, can_get_priority)
{
  ASSERT_EQ(1, GetPriority(')'));
  ASSERT_EQ(1, GetPriority('('));
  ASSERT_EQ(2, GetPriority('+'));
  ASSERT_EQ(2, GetPriority('-'));
  ASSERT_EQ(3, GetPriority('*'));
  ASSERT_EQ(3, GetPriority('/'));
  ASSERT_ANY_THROW(GetPriority('!'));
}

TEST(Polish, can_convert_to_pol)
{
  char s[] = "5+2";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);
  ASSERT_EQ(que.Get(), '[');
  ASSERT_EQ(que.Get(), '5');
  ASSERT_EQ(que.Get(), ']');
  ASSERT_EQ(que.Get(), '[');
  ASSERT_EQ(que.Get(), '2');
  ASSERT_EQ(que.Get(), ']');
  ASSERT_EQ(que.Get(), '+');
}

TEST(Polish, can_add)
{
  char s[] = "5+7";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);
  EXPECT_EQ(12, Res(que));
}

TEST(Polish, can_add_two_big_number) 
{
  char s[] = "25+13";
  TString str(s);
  TQueue<char> que;

  que = ConvertToPol(str);

  EXPECT_EQ(38, Res(que));
}

TEST(Polish, can_subtract) 
{
  char s[] = "5-1";
  TString str(s);
  TQueue<char> que;

  que = ConvertToPol(str);

  EXPECT_EQ(4, Res(que));
}

TEST(Polish, can_mult)
{
  char s[] = "4*5";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(20, Res(que));
}

TEST(Polish, can_mult_with_three_parametr) 
{
  char s[] = "4*5*3";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(60, Res(que));
}

TEST(Polish, can_mult_and_add_whith_hooks) 
{
  char s[] = "(5+4)*3";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(27, Res(que));
}

TEST(Polish, can_mult_and_add_whithout_hooks) 
{
  char s[] = "5+4*3";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(17, Res(que));
}

TEST(Polish, can_split)
{
  char s[] = "16/4";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(4, Res(que));
}

TEST(Polish, can_mult_large_with_hooks) 
{
  char s[] = "(25+39)*12";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(768, Res(que));
}

TEST(Polish, can_mult_and_split_with_hooks)
{
  char s[] = "(25+39)/4";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(16, Res(que));
}

TEST(Polish, can_add_and_split_with_hooks) 
{
  char s[] = "(25+39)/(20-4)";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(4, Res(que));
}

TEST(Polish, can_add_and_split_with_negative_first_number) 
{
  char s[] = "-6+(25+39)/(20-16)";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(10, Res(que));
}

TEST(Polish, can_check_ispolish)
{
	ASSERT_EQ(1, IsPolish(')'));
	ASSERT_EQ(1, IsPolish('('));
	ASSERT_EQ(1, IsPolish('+'));
	ASSERT_EQ(1, IsPolish('-'));
	ASSERT_EQ(1, IsPolish('*'));
	ASSERT_EQ(1, IsPolish('/'));
	ASSERT_EQ(false, IsPolish('25'));
	ASSERT_EQ(false, IsPolish('!'));
}