/*
	Dominik Jedruszczak

	test_trivial.cpp
	Trivial tests for CMake/GoogleTest/TravisCI Integration testing.
*/

#include "gtest/include/gtest/gtest.h"

/* Integer addition test. */
TEST(IntegerArithmetic, Addition) {
	EXPECT_EQ(2, 1 + 1);
}

/* Integer subtraction test. */
TEST(IntegerArithmetic, Subtraction) {
	EXPECT_EQ(1, 2 - 1);
}

/* Integer multiplication test. */
TEST(IntegerArithmetic, Multiplication) {
	EXPECT_EQ(2, 1 * 2);
}

/* Run tests. */
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
