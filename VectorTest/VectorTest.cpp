#include "gtest.h"

#include "Vector.h"

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}



TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(5);
	TVector<int> exp(v);

	EXPECT_EQ(v, exp);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(5);
	TVector<int> v2(v1);

	EXPECT_NE(&v1, &v2);
}

TEST(TVector, can_get_length)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetLength());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TVector, can_set_and_get_double_element)
{
	TVector<double> v(4);
	v[0] = 4.4;

	EXPECT_EQ(4.4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(3);

	ASSERT_ANY_THROW(v[-1] = 2);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(3);

	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_length)
{
	TVector<int> v1(3);
	TVector<int> v2(3);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, assign_operator_change_vector_length)
{
	TVector<int> v1(3);
	TVector<int> v2(5);

	v2 = v1;

	EXPECT_NE(5, v2.GetLength());

}

TEST(TVector, can_assign_vectors_of_different_length)
{
	TVector<int> v1(3);
	TVector<int> v2(5);

	ASSERT_NO_THROW(v2 = v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(3);
	TVector<int> v2(3);

	EXPECT_EQ(true, v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(2);

	ASSERT_NO_THROW(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(3);
	TVector<int> v2(5);

	EXPECT_EQ(false, v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(3);

	ASSERT_NO_THROW(v + 6);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3);

	ASSERT_NO_THROW(v - 6);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3);

	ASSERT_NO_THROW(v * 6);
}

TEST(TVector, can_add_vectors_with_equal_length)
{
	TVector<int> v1(2);
	TVector<int> v2(2);

	ASSERT_NO_THROW(v1 + v2);
}

TEST(TVector, can_add_double_vectors_with_equal_length)
{
	TVector<double> v1(2);
	TVector<double> v2(2);
	v1[0] = 4.4;
	v2[0] = 5.5;

	EXPECT_EQ(v1[0] + v2[0], 9.9);
}


TEST(TVector, cant_add_vectors_with_not_equal_length)
{
	TVector<int> v1(2);
	TVector<int> v2(3);

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_length)
{
	TVector<int> v1(2);
	TVector<int> v2(2);

	ASSERT_NO_THROW(v1 - v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_length)
{
	TVector<int> v1(2);
	TVector<int> v2(3);

	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_length)
{
	TVector<int> v1(2);
	TVector<int> v2(2);

	ASSERT_NO_THROW(v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_length)
{
	TVector<int> v1(2);
	TVector<int> v2(3);

	ASSERT_ANY_THROW(v1 * v2);
}

TEST(TVector, check_operator_unequal_with_equal_vectors)
{
	TVector<int> v1(3);
	TVector<int> v2(v1);

	EXPECT_EQ(false, v1 != v2);
}

TEST(TVector, check_operator_unequal_vectors_not_equal_length)
{
	TVector<int> v1(3);
	TVector<int> v2(4);

	EXPECT_EQ(true, v1 != v2);

}

TEST(TVector, compare_after_add_scalar)
{
	TVector<int> v1(3);
	TVector<int> v2(v1);

	EXPECT_NE(v1 + 2, v2);
}

TEST(TVector, compare_after_subtract_scalar)
{
	TVector<int> v1(3);
	TVector<int> v2(v1);

	EXPECT_NE(v1 - 2, v2);
}

TEST(TVector, compare_after_set_element)
{
	TVector<int> v1(3);
	TVector<int> v2(v1);

	v1[1] = 8;

	EXPECT_NE(v1, v2);
}

TEST(Vector, thorws_when_index_argument_more_or_eq_length)
{
	TVector <int> V(3);
	ASSERT_ANY_THROW(V[3]);
}

TEST(Vector, can_use_index_operator)
{
	TVector <int> V(3);
	V[1] = 3;
	int temp = V[1] + 1;
	ASSERT_EQ(4, temp);
}

