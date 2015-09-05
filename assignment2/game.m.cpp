/*
	Dominik Jedruszczak

	game.m.cpp
	TODO.
*/

#include <cstdio>
#include "src/engine/memory/counting_allocator.hpp"
#include "src/engine/containers/dynamic_array.hpp"

/* TODO. */
int main(int argc, char** argv) {
	sgdc::DynamicArray<int>* da = new sgdc::DynamicArray<int>(10);
	/*sgdm::CountingAllocator<int> ca;
	sgdc::DynamicArray<int> da(10);
	da.append(7);


	printf("Expected = 10,\tActual = %u", ca.getAllocations());*/
}
