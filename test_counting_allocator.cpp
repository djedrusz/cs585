/*
	Dominik Jedruszczak

	test_counting_allocator.cpp
	Tests for the "CountingAllocator" class.
*/

#include "../gtest/include/gtest/gtest.h"
#include "../src/engine/memory/counting_allocator.hpp"

using namespace sgdm;

/* Globals. */
/* Counting Allocators. */
CountingAllocator<int> countingAllocator;
CountingAllocator<int> countingAllocator2;
/* Memory Blocks. */
int* memoryBlock;
int* memoryBlock2;

TEST(CountingAllocator, Initialization) {
	EXPECT_EQ(0, countingAllocator.getAllocations());
	EXPECT_EQ(0, countingAllocator.getDeallocations());
	EXPECT_EQ(0, countingAllocator.getTotalAllocations());
	EXPECT_EQ(0, countingAllocator.getTotalDeallocations());
}

TEST(CountingAllocator, Allocation) {
	memoryBlock = countingAllocator.allocate(10);
	memoryBlock2 = countingAllocator2.allocate(15);

	EXPECT_EQ(10, countingAllocator.getAllocations());
	EXPECT_EQ(15, countingAllocator2.getAllocations());
	EXPECT_EQ(25, countingAllocator.getTotalAllocations());
	EXPECT_EQ(25, countingAllocator2.getTotalAllocations());
}

TEST(CountingAllocator, Deallocation) {
	countingAllocator.deallocate(memoryBlock, 10);
	countingAllocator2.deallocate(memoryBlock2, 15);

	EXPECT_TRUE(memoryBlock == NULL);
	EXPECT_TRUE(memoryBlock2 == NULL);

	EXPECT_EQ(10, countingAllocator.getDeallocations());
	EXPECT_EQ(15, countingAllocator2.getDeallocations());
	EXPECT_EQ(25, countingAllocator.getTotalDeallocations());
	EXPECT_EQ(25, countingAllocator.getTotalDeallocations());
}

TEST(CountingAllocator, OustandingAllocation) {
	EXPECT_EQ(0, countingAllocator.getOutstandingAllocations());
	EXPECT_EQ(0, countingAllocator2.getOutstandingAllocations());
	EXPECT_EQ(0, countingAllocator.getTotalOutstandingAllocations());
	EXPECT_EQ(0, countingAllocator2.getTotalOutstandingAllocations());
}

/* Test main. */
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
