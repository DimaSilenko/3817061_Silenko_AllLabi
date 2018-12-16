#include "gtest.h"
#include "Queue.h"


TEST(TQueue, can_create_queue_with_positive_size){
	ASSERT_NO_THROW(TQueue<int> Qu(25));
}

TEST(TQueue, cant_create_queue_with_negative_size){
	ASSERT_ANY_THROW(TQueue<int> Qu(-25));
}

TEST(TQueue, can_create_copied_queue){
	TQueue<int> Qu1(25);
	ASSERT_NO_THROW(TQueue<int> Qu2(Qu1));
}

TEST(TQueue, check_full_queue){
	TQueue<int> Qu(1);
	Qu.Put(1);
	EXPECT_EQ(1, Qu.IsFull());
}

TEST(TQueue, check_empty_queue){
	TQueue<int> Qu(7);
	EXPECT_EQ(1, Qu.IsEmpty());
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

TEST(TQueue, can_put_element){
	TQueue<int> Qu(4);

	ASSERT_NO_THROW(Qu.Put(25));
}

TEST(TQueue, can_get_element){
	TQueue<int> Qu(4);
	Qu.Put(25);

	EXPECT_EQ(25, Qu.Get());
}

