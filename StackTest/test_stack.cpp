#include "gtest.h"
#include "Stack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> St(25)); 
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> St(-25)); 
}

TEST(TStack, create_empty_stack)
{
	TStack<int> St(3);

	EXPECT_EQ(true, St.IsEmpty());
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> St1(25);
	ASSERT_NO_THROW(TStack<int> St2(St1));
}

TEST(TStack, check_full_stack)
{
	TStack<int> St(1);
	St.Put(1);
	EXPECT_EQ(1, St.IsFull());
}

TEST(TStack, check_empty_stack)
{
	TStack<int> St(25);
	EXPECT_EQ(1, St.IsEmpty());
}

TEST(TStack, cant_put_element_in_full_stack)
{
	TStack<int> St(4);
	St.Put(1);
	St.Put(2);
	St.Put(3);
	St.Put(4);
	ASSERT_ANY_THROW(St.Put(5));
}

TEST(TStack, cant_get_element_in_empty_stack)
{
	TStack<int> St(4);
	ASSERT_ANY_THROW(St.Get());
}

TEST(TStack, can_put_and_get_element)
{
	TStack<int> St(4);
	St.Put(1);
	St.Put(2);
	St.Put(3);
	EXPECT_EQ(3, St.Get());
}














