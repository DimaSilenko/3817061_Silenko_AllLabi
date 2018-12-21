#include "gtest.h"
#include "Queue.h"


TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> Qu(25));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> Qu(-25));
}

TEST(TQueue, can_create_copied_queue){
	TQueue<int> Qu1(25);
	ASSERT_NO_THROW(TQueue<int> Qu2(Qu1));
}

TEST(TQueue, check_full_queue_true)
{
	TQueue<int> Qu(1);
	Qu.Put(1);
	EXPECT_EQ(1, Qu.IsFull());
}

TEST(TQueue, check_full_queue_false)
{
	TQueue<int> Qu(1);
	EXPECT_EQ(0, Qu.IsFull());
}

TEST(TQueue, check_empty_queue_true){
	TQueue<int> Qu(7);
	EXPECT_EQ(1, Qu.IsEmpty());
}

TEST(TQueue, check_empty_queue_false) {
	TQueue<int> Qu(7);
	Qu.Put(1);
	EXPECT_EQ(0, Qu.IsEmpty());
}

TEST(TQueue, cant_put_element_in_full_queue){
	TQueue<int> Qu(4);
	for(int i=0;i<4;i++)
		Qu.Put(25);

	ASSERT_ANY_THROW(Qu.Put(25));
}

TEST(TQueue, cant_get_element_in_empty_queue){
	TQueue<int> Qu(4);

	ASSERT_ANY_THROW(Qu.Get());
}

TEST(TQueue, can_put_element)
{
	TQueue<int> Qu(4);

	ASSERT_NO_THROW(Qu.Put(25));
}

TEST(TQueue, can_get_element)
{
	TQueue<int> Qu(4);
	Qu.Put(25);

	EXPECT_EQ(25, Qu.Get());
}

TEST(TQueue, check_get_end_put_in_queue)
{
	TQueue <int> Qu(5);
	for (int i = 1; i < 6; i++)
		Qu.Put(i); // 1 2 3 4 5

	Qu.Get(); // 2 3 4 5 
	Qu.Get(); // 3 4 5
	Qu.Get(); // 4 5

	Qu.Put(10); // 4 5 10 
	Qu.Put(5); // 4 5 10 5
	Qu.Get(); // 5 10 5
	ASSERT_EQ(5, Qu.Get());
}


TEST(TQueue, Prav_vivod)
{
	TQueue<int> Qu(3);
	Qu.Put(1), Qu.Put(2), Qu.Put(3);
	ASSERT_EQ(Qu.Get(), 1);
	ASSERT_EQ(Qu.Get(), 2);
	ASSERT_EQ(Qu.Get(), 3);
}

