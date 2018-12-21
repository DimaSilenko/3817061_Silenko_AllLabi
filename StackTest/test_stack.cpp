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

TEST(TStack, check_full_stack_true)
{
	TStack<int> St(1);
	St.Put(1);
	EXPECT_EQ(1, St.IsFull());
}

TEST(TStack, check_full_stack_false)
{
	TStack<int> St(1);
	EXPECT_EQ(0, St.IsFull());
}

TEST(TStack, check_empty_stack_true)
{
	TStack<int> St(25);
	EXPECT_EQ(1, St.IsEmpty());
}

TEST(TStack, check_empty_stack_false)
{
	TStack<int> St(25);
	St.Put(1);
	EXPECT_EQ(0, St.IsEmpty());
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

TEST(Stack, Prav_vivod)
{
	TStack <int> St(3);
	St.Put(1), St.Put(2), St.Put(3);
	ASSERT_EQ(St.Get(), 3);
	ASSERT_EQ(St.Get(), 2);
	ASSERT_EQ(St.Get(), 1);
}


TEST(TStack, Sravnenie_true)
{
	TStack <int> St1(1), St2(1);
	St1.Put(1);
	St2.Put(1);
	ASSERT_TRUE(St1 == St2);
}

TEST(Stack, Sravnenie_false)
{
	TStack <int> St1(1), St2(1);
	St1.Put(1);
	St2.Put(2);
	ASSERT_FALSE(St1 == St2);
}

TEST(Stack, Sravnenie_false_when_dif_length)
{
	TStack <int> St1(1), St2(3);
	ASSERT_FALSE(St1 == St2);
}

TEST(Stack, Sravnenie_false_when_dif_top)
{
	TStack <int> St1(3), St2(3);
	St1.Put(1);
	St2.Put(1), St2.Put(2);
	ASSERT_FALSE(St1 == St2);
}

TEST(Stack, NegativSravnenie_false)
{
	TStack <int> St1(1), St2(1);
	St1.Put(1);
	St2.Put(1);
	ASSERT_FALSE(St1 != St2);
}

TEST(Stack, NegativSravnenie_true)
{
	TStack <int> St1(1), St2(1);
	St1.Put(1);
	St2.Put(2);
	ASSERT_TRUE(St1 != St2);
}

TEST(Stack, NegativSravnenie_true_when_dif_size)
{
	TStack <int> St1(1), St2(3);
	ASSERT_TRUE(St1 != St2);
}

TEST(Stack, NegativSravnenie_true_when_dif_top)
{
	TStack <int> St1(3), St2(3);
	St1.Put(1);
	St2.Put(1), St2.Put(2);
	ASSERT_TRUE(St1 != St2);
}

TEST(Stack, assignment)
{
	TStack <int> St1(3), St2(1);
	St1.Put(1), St1.Put(2), St1.Put(3);
	St2 = St1;
	ASSERT_TRUE(St2 == St1);
}









