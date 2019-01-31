#include "gtest.h"
#include "MultiStack.h"

TEST(TNewStack, throws_when_create_newstack_with_negative_size)
{
  int *mas = NULL;
  ASSERT_ANY_THROW(TNewStack<int> newst(-1, mas));
}
 
TEST(TNewStack, can_create_newstack)
{
  int *mas = NULL;
  ASSERT_NO_THROW(TNewStack<int> newst(2, mas));
}

TEST(TNewStack, can_create_copy_newstack)
{
  int *mas = NULL;
  TNewStack<int> newst1(2, mas);
  ASSERT_NO_THROW(TNewStack<int> newst2(newst1));
}

TEST(TNewStack, can_get_free_cell)
{
  int *mas = new int[5];
  TNewStack<int> newst(5, mas);
  newst.Push(3);
  newst.Push(2);
  ASSERT_EQ(3, newst.GetFreeCell());
}

TEST(TNewStack, can_get_top)
{
  int *mas = new int[5];
  TNewStack<int> newst(5, mas);
  newst.Put(3);
  newst.Put(2);
  ASSERT_EQ(2, newst.GetTop());
}

TEST(TNewStack, can_get_size)
{
  int *mas = NULL;
  TNewStack<int> newst(5, mas);
  ASSERT_EQ(5, newst.GetLength());
}

TEST(TNewStack, can_set_multistack)
{
  int *mas1 = new int[5];
  int *mas2 = new int[5];
  TNewStack<int> newst(5, mas1);
  newst.SetMas(10, mas2);
  ASSERT_EQ(10, newst.GetLength());
}

TEST(TNewStack, throw_set_multistack_negative_size)
{
  int *mas1 = new int[5];
  int *mas2 = new int[5];
  TNewStack<int> newst(5, mas1);
  ASSERT_ANY_THROW(newst.SetMas(-1, mas2));
}

TEST(TNewStack, can_put_and_get_elem)
{
  int *mas = new int[5];
  TNewStack<int> newst(5, mas);
  newst.Push(3);
  newst.Push(2);
  ASSERT_EQ(2, newst.Get());
  ASSERT_EQ(3, newst.Get());
}

TEST(TNewStack, throw_when_put_to_full)
{
	int* mas = new int[3];
	TNewStack<int> newst(3, mas);
	newst.Push(1);
	newst.Push(2);
	newst.Push(3);

	ASSERT_ANY_THROW(newst.Push(4));
}

TEST(TMStack, can_create_mstack_with_positive_length)
{
  ASSERT_NO_THROW(TMStack<int> mst(5, 25));
}

TEST(TMStack, cant_create_mstack_with_negative_length)
{
  ASSERT_ANY_THROW(TMStack<int> mst(5, -1));
}

TEST(TMStack, cant_create_mstack_with_negative_kol)
{
  ASSERT_ANY_THROW(TMStack<int> mst(0, 10));
}

TEST(TMStack, can_copy_mstack)
{
  TMStack<int> mst1(5, 25);
  ASSERT_NO_THROW(TMStack<int> mst2(mst1));
}

TEST(TMStack, can_get_length)
{
  TMStack<int> mst(5, 25);
  ASSERT_EQ(mst.GetLength(), 25);
}

TEST(TMStack, can_set_element)
{
  TMStack<int> mst(5, 25);
  ASSERT_NO_THROW(mst.Set(1, 2));
}

TEST(TMStack, throws_when_set_element_in_full_mstack)
{
  TMStack<int> mst(2, 4);
  mst.Set(0, 1);
  mst.Set(0, 1);
  mst.Set(1, 1);
  mst.Set(1, 1);
  ASSERT_ANY_THROW(mst.Set(1,1));
}

TEST(TMStack, throws_when_set_element_in_negative_index)
{
  TMStack<int> mst(5, 10);
  ASSERT_ANY_THROW(mst.Set(-2, 2));
}

TEST(TMStack, can_get_element)
{
  TMStack<int> mst(5, 25);
  mst.Set(1, 15);
  ASSERT_EQ(15, mst.Get(1));
}

TEST(TMStack, can_repack)
{
  TMStack<int> mst(2, 6);
  mst.Set(0, 1);
  mst.Set(0, 2);
  mst.Set(0, 3);
  mst.Set(1, 4);
  ASSERT_NO_THROW(mst.Set(0,5));
  ASSERT_EQ(mst.Get(0), 5);
}

TEST(TMStack, throws_when_get_element_from_negative_index)
{
  TMStack<int> mst(5, 10);
  mst.Set(0, 125);
  ASSERT_ANY_THROW(mst.Get(-1));
}

TEST(TMStack, throws_when_get_element_from_empty_mstack)
{
  TMStack<int> mst(2, 5);
  ASSERT_ANY_THROW(mst.Get(1));
}

TEST(TMStack, correct_order_get)
{
  TMStack <int> mst(2, 5);
  mst.Set(1, 1);
  mst.Set(1, 2);
  mst.Set(1, 3);
  ASSERT_EQ(3, mst.Get(1));
  ASSERT_EQ(2, mst.Get(1));
  ASSERT_EQ(1, mst.Get(1));
}

TEST(TMStack, IsEmpty_return_true)
{
  TMStack<int> mst(5, 10);
  ASSERT_TRUE(mst.IsEmpty(1));
}

TEST(TMStack, IsEmpty_return_false)
{
  TMStack<int> mst(5, 10);
  mst.Set(0, 1);
  ASSERT_FALSE(mst.IsEmpty(0));
}

TEST(TMStack, IsFull_return_true)
{
  TMStack<int> mst(5, 10);
  mst.Set(1, 125);
  mst.Set(1, 15);
  ASSERT_TRUE(mst.IsFull(1));
}

TEST(TMStack, IsFull_return_false)
{
  TMStack<int> mst(5, 10);
  mst.Set(1, 125);
  ASSERT_FALSE(mst.IsFull(1));
}

TEST(TMStack, throw_when_check_is_full_or_empty_with_negative_index)
{
  TMStack<int> mst(5, 10);
  ASSERT_ANY_THROW(mst.IsFull(-1));
  ASSERT_ANY_THROW(mst.IsEmpty(-1));
}