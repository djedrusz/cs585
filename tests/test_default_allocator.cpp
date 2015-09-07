/*
	Dominik Jedruszczak

	test_default_allocator.cpp
	Tests for the "DefaultAllocator" class.
*/

#include "../gtest/include/gtest/gtest.h"
#include "../src/engine/memory/default_allocator.hpp"

using namespace sgdm;

/* Globals. */
DefaultAllocator<int> defaultAllocator; // Default allocator.
int* memoryBlock; // Memory block.

TEST(DefaultAllocator, Allocation) {
	memoryBlock = defaultAllocator.allocate(10);
	EXPECT_TRUE(memoryBlock != NULL);
}

TEST(DefaultAllocator, Deallocation) {
	defaultAllocator.deallocate(memoryBlock, 10);
	printf("%p\n", memoryBlock);
	EXPECT_TRUE(memoryBlock == NULL);
}

/* Test main. */
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

