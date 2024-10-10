#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
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
	TMatrix<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			a[i][j] = i + i;
		}
	}
	TMatrix<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			a[i][j] = i + i;
		}
	}
	TMatrix<int> b(a);
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			a[i][j] += i;
		}
	}
	EXPECT_NE(a, b);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> a(10);
	ASSERT_NO_THROW(a.GetSize());
	EXPECT_EQ(10, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> a(10);
	ASSERT_NO_THROW(a[0][0] = 10);
	ASSERT_NO_THROW(a[0][0]);
	a[4][5] = 5;
	EXPECT_EQ(5, a[4][5]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> a(10);
	ASSERT_ANY_THROW(a[4][-1] = 10);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(10);
	ASSERT_ANY_THROW(a[11][12] = 10);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	const int size = 5;
	TMatrix<int> v1(size), v2(size), testv(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			v1[i][j] = i;
		}
	}
	ASSERT_NO_THROW(v1 = v1);

}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 5;
	TMatrix<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			v1[i][j] = i;
		}
	}
	ASSERT_NO_THROW(v2 = v1);
	EXPECT_EQ(v1, v2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int size1 = 4, size2 = 6;
	TMatrix<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		for (int j = i; j < size1; j++)
		{
			v1[i][j] = i;
		}
	}
	ASSERT_NO_THROW(v2 = v1);

	EXPECT_EQ(size1, v2.GetSize());
	EXPECT_EQ(v1, v2);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int size1 = 5, size2 = 6;
	TMatrix<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		for (int j = i; j < size1; j++)
		{
			v1[i][j] = i;
		}
	}
	ASSERT_NO_THROW(v2 = v1);

}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	const int size = 5;
	TMatrix<int> v1(size), v2(size);
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	const int size = 2;
	TMatrix<int> v1(size);
	EXPECT_EQ(v1, v1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int size1 = 2, size2 = 5;
	TMatrix<int> v1(size1), v2(size2);
	EXPECT_NE(v1, v2);

}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int size = 5;
	TMatrix<int> v1(size), v2(size), testv(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			v1[i][j] = j;
			v2[i][j] = j + 5;
			testv[i][j] = v1[i][j] + v2[i][j];
		}
		
	}
	ASSERT_NO_THROW(v1 + v2);
	EXPECT_EQ(v1 + v2, testv);
	//ADD_FAILURE();
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	const int size1 = 5, size2 = 2;
	TMatrix<int> v1(size1), v2(size2);
	ASSERT_ANY_THROW(v1 + v2);
	//ADD_FAILURE();
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int size = 5;
	TMatrix<int> v1(size), v2(size), testv(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			v1[i][j] = i;
			v2[i][j] = i + i;
			testv[i][j] = v2[i][j] - v1[i][j];
		}
	}
	ASSERT_NO_THROW(v2 - v1);
	EXPECT_EQ(v2 - v1, testv);
	//ADD_FAILURE();
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int size1 = 5, size2 = 2;
	TMatrix<int> v1(size1), v2(size2);
	ASSERT_ANY_THROW(v1 - v2);
	//ADD_FAILURE();
}

