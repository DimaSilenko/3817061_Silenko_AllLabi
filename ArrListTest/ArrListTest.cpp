#include <gtest.h>
#include "ArrList.h"

TEST(ArrList, can_create_list_with_not_specified_size)
{
  ASSERT_NO_THROW(TArrList <int> arrlst());
}

TEST(ArrList, can_create_list_with_specified_size)
{
  ASSERT_NO_THROW(TArrList <int> arrlst(3));
}

TEST(ArrList, can_create_copy_empty_list)
{
  TArrList <int> arrlst1(1);
  arrlst1.PutStart(1);
  TArrList <int> arrlst2(arrlst1);
  ASSERT_EQ(arrlst1.GetStart(), arrlst2.GetStart());
}

TEST(ArrList, can_create_copy_not_empty_list)
{
  TArrList <int> arrlst1(3);

  ASSERT_NO_THROW(TArrList <int> arrlst2(arrlst1));
}

TEST(ArrList, throws_when_create_list_with_zero_size)
{
  ASSERT_ANY_THROW(TArrList <int> arrlst(0));
}

TEST(ArrList, throws_when_create_list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrList <int> arrlst(-1));
}

TEST(ArrList, can_get_start)
{
  TArrList <int> arrlst(2);
  arrlst.PutStart(1);
  arrlst.PutStart(2);
  ASSERT_EQ(2, arrlst.GetStart());
  ASSERT_EQ(1, arrlst.GetStart());
}

TEST(ArrList, can_put_start)
{
	TArrList <int> arrlst(2);
	arrlst.PutStart(1);
	ASSERT_NO_THROW(arrlst.PutStart(2));
}

TEST(ArrList, can_put_and_get_end)
{
  TArrList <int> arrlst(2);
  arrlst.PutEnd(1);
  arrlst.PutEnd(2);
  ASSERT_EQ(2, arrlst.GetEnd());
  ASSERT_EQ(1, arrlst.GetEnd());
}

TEST(ArrList, can_use_full_check_false)
{
  TArrList <int> arrlst(1);
  ASSERT_FALSE(arrlst.IsFull());
}

TEST(ArrList, can_use_full_check_true)
{
  TArrList <int> arrlst(1);
  arrlst.PutStart(17);
  ASSERT_TRUE(arrlst.IsFull());
}

TEST(ArrList, can_use_empty_check_false)
{
  TArrList <int> arrlst(1);
  arrlst.PutStart(5);
  ASSERT_FALSE(arrlst.IsEmpty());
}

TEST(ArrList, can_use_empty_check_true)
{
  TArrList <int> arrlst(1);
  ASSERT_TRUE(arrlst.IsEmpty());
}

TEST(ArrList, throws_when_in_full_list_put_start_elem)
{
  TArrList <int> arrlst(1);
  arrlst.PutStart(1);
  ASSERT_ANY_THROW(arrlst.PutStart(2));
}

TEST(ArrList, throws_when_in_full_list_put_end_elem)
{
  TArrList <int> arrlst(1);
  arrlst.PutStart(1);
  ASSERT_ANY_THROW(arrlst.PutEnd(2));
}

TEST(ArrList, throws_when_in_empty_list_get_start_elem)
{
  TArrList <int> arrlst(1);
  ASSERT_ANY_THROW(arrlst.GetStart());
}

TEST(ArrList, throws_when_in_empty_list_get_end_elem)
{
  TArrList <int> arrlst(1);
  ASSERT_ANY_THROW(arrlst.GetEnd());
}

TEST(ArrList, true_output)
{
  TArrList <int> arrlst(5);
  arrlst.PutStart(1); // 1
  arrlst.PutEnd(2);   // 1 2
  arrlst.PutStart(0); // 0 1 2
  arrlst.PutEnd(4);   // 0 1 2 4
  arrlst.PutStart(6); // 6 0 1 2 4 
  ASSERT_EQ(4, arrlst.GetEnd());     // 6 0 1 2  
  ASSERT_EQ(6, arrlst.GetStart());   // 0 1 2
  ASSERT_EQ(2, arrlst.GetEnd());     // 0 1 
  ASSERT_EQ(0, arrlst.GetStart());   // 1
  ASSERT_EQ(1, arrlst.GetEnd());     // empty
}

TEST(ArrList, throws_when_in_empty_list_get_elem)
{
  TArrList <int> arrlst(7);
  ASSERT_ANY_THROW(arrlst.Get(3));
}

TEST(ArrList, throws_when_in_full_list_put_elem)
{
  TArrList <int> arrlst(3);
  arrlst.PutEnd(1);
  arrlst.PutEnd(1);
  arrlst.PutEnd(1);

  ASSERT_ANY_THROW(arrlst.Put(1, 6));
}

TEST(ArrList, throws_when_incurrent_index_when_list_put_elem)
{
  TArrList <int> arrlst(4);
  arrlst.PutEnd(1);
  arrlst.PutEnd(1);
  arrlst.PutEnd(1);

  ASSERT_ANY_THROW(arrlst.Put(10, 6));
}

TEST(ArrList, throws_when_incurrent_index_when_list_get_elem)
{
  TArrList <int> arrlst(3);
  arrlst.PutEnd(1);
  arrlst.PutEnd(1);
  arrlst.PutEnd(1);

  ASSERT_ANY_THROW(arrlst.Get(15));
}

TEST(ArrList, can_get_elem)
{
  TArrList <int> arrlst(3);
  arrlst.PutEnd(1);
  arrlst.PutEnd(2);
  arrlst.PutEnd(3);

  ASSERT_EQ(arrlst.Get(1), 2);
}

TEST(ArrList, can_put_elem)
{
  TArrList <int> arrlst(4);
  arrlst.PutEnd(1);
  arrlst.PutEnd(2);
  arrlst.PutEnd(3);
  arrlst.Put(2, 10);

  ASSERT_EQ(arrlst.Get(1), 2);
  ASSERT_EQ(arrlst.Get(1), 10);
}