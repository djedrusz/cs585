/*
	Dominik Jedruszczak

	game.m.cpp
	TODO.
*/

#include "src/engine/memory/counting_allocator.hpp"
#include <stdio.h>

/* TODO. */
int main(int argc, char** argv) {
	sgdm::CountingAllocator<int> da();
	printf("success");
	return 0;
}
