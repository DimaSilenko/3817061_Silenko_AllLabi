#include "Matrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix)
{
	ASSERT_NO_THROW(TMatrix<int> m);
}

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);

	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);

	EXPECT_NE(&m1, &m2);
}

TEST(TMatrix, can_get_length)
{
	TMatrix<int> m1(5);

	EXPECT_EQ(5, m1.GetLength());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(3);
	m[1][1] = 6;

	EXPECT_EQ(6, m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[-1][1] = 9);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[4][4] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(3);

	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_length)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);

	ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, assign_operator_change_matrix_length)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(5);

	m2 = m1;

	EXPECT_EQ(3, m2.GetLength());
}

TEST(TMatrix, can_assign_matrices_of_different_length)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(5);

	ASSERT_NO_THROW(m2 = m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(m1);

	EXPECT_EQ(true, m2 == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(3);

	EXPECT_EQ(true, m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(5);

	EXPECT_EQ(false, m2 == m1);
}

TEST(TMatrix, can_add_matrices_with_equal_length)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);

	ASSERT_NO_THROW(m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_length)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_length)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);

	ASSERT_NO_THROW(m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_length)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TMatrix, compare_matrices_after_add)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(m1);
	TMatrix<int> exp = m2 + m1;

	EXPECT_EQ(exp, m2);
}

TEST(TMatrix, compare_matrices_after_subtract)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(m1);
	TMatrix<int> exp = m2 - m1;

	EXPECT_EQ(exp, m2);
}

TEST(TMatrix, check_operator_unequal_with_equal_matrices)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(m1);

	EXPECT_EQ(false, m1 != m2);
}

TEST(TMatrix, check_operator_unequal_matrices_not_equal_length)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(5);

	EXPECT_EQ(true, m1 != m2);
}

TEST(TMatrix, check_operator_unequal_with_itself)
{
	TMatrix<int> m(3);

	EXPECT_EQ(false, m != m);
}

TEST(Matrix, throws_when_create_matrix_with_zero_size)
{
  ASSERT_ANY_THROW(TMatrix <int> M(0));
}

TEST(Matrix, throws_when_create_matrix_with_too_large_size)
{
  ASSERT_ANY_THROW(TMatrix <int> M(10001));
}



//TEST(Matrix, can_addition_matrix)
//{
//  TMatrix <int> M1(2), M2(2), MT(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2 - i; j++) {
//      M1[i][j] = i + j;
//      M2[i][j] = i + j + 2;
//      MT[i][j] = M1[i][j] + M2[i][j];
//    }
//  ASSERT_TRUE(MT == (M1 + M2));
//}
//

//TEST(Matrix, can_subtraction_matrix)
//{
//  TMatrix <int> M1(2), M2(2), MT(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2 - i; j++) 
//    {
//      M1[i][j] = i + j;
//      M2[i][j] = i + j + 2;
//      MT[i][j] = M1[i][j] - M2[i][j];
//    }
//  ASSERT_TRUE(MT == (M1 - M2));
//}

//TEST(Matrix, can_multiplication_matrix)
//{
//  TMatrix <int> M1(3), M2(3), MT(3);
//  M1[0][0] = 1; M1[0][1] = 2; M1[0][2] = 3;
//  M1[1][0] = 4; M1[1][1] = 5;
//  M1[2][0] = 6;
//
//  M2[0][0] = 3; M2[0][1] = 5; M2[0][2] = 7;
//  M2[1][0] = 9; M2[1][1] = 11;
//  M2[2][0] = 13;
//
//  MT[0][0] = 3; MT[0][1] = 23; MT[0][2] = 68;
//  MT[1][0] = 36; MT[1][1] = 109;
//  MT[2][0] = 78;
//  ASSERT_TRUE(MT == (M1 * M2));
//}
//