/*
	Dominik Jedruszczak

	game.m.cpp
	TODO.
*/

#include <cstdio>
/* Please forgive me for my '.cpp' inclusion heresy. But it's the only way I can debug while I sort out the linking issues. */
#include "src/engine/memory/default_allocator.hpp"
//#include "src/engine/memory/default_allocator.cpp"
#include "src/engine/memory/counting_allocator.hpp"
//#include "src/engine/memory/counting_allocator.cpp"
#include "src/engine/containers/dynamic_array.hpp"
//#include "src/engine/containers/dynamic_array.cpp"

/* TODO. */
int main(int argc, char** argv) {
	sgdm::CountingAllocator<int>* countingAllocator = new sgdm::CountingAllocator<int>();
	/*sgdm::CountingAllocator<int>* countingAllocator2 = new sgdm::CountingAllocator<int>();

	printf("%u\n", countingAllocator->getAllocations());
	printf("%u\n", countingAllocator2->getAllocations());
	printf("%u\n", countingAllocator->getTotalAllocations());
	printf("%u\n\n", countingAllocator2->getTotalAllocations());

	int* memoryBlock = countingAllocator->allocate(15);

	printf("%u\n", countingAllocator->getAllocations());
        printf("%u\n", countingAllocator2->getAllocations());
        printf("%u\n", countingAllocator->getTotalAllocations());
        printf("%u\n\n", countingAllocator2->getTotalAllocations());

	int* memoryBlock2 = countingAllocator2->allocate(30);

	printf("%u\n", countingAllocator->getAllocations());
        printf("%u\n", countingAllocator2->getAllocations());
        printf("%u\n", countingAllocator->getTotalAllocations());
        printf("%u\n\n", countingAllocator2->getTotalAllocations());

	countingAllocator->deallocate(memoryBlock, 15);

	printf("%u\n", countingAllocator->getDeallocations());
        printf("%u\n", countingAllocator2->getDeallocations());
        printf("%u\n", countingAllocator->getTotalDeallocations());
        printf("%u\n\n", countingAllocator2->getTotalDeallocations());

	countingAllocator2->deallocate(memoryBlock2, 30);

	printf("%u\n", countingAllocator->getDeallocations());
        printf("%u\n", countingAllocator2->getDeallocations());
        printf("%u\n", countingAllocator->getTotalDeallocations());
        printf("%u\n\n", countingAllocator2->getTotalDeallocations());

	printf("%u\n", countingAllocator->getOutstandingAllocations());
        printf("%u\n", countingAllocator2->getOutstandingAllocations());
        printf("%u\n", countingAllocator->getTotalOutstandingAllocations());
        printf("%u\n", countingAllocator2->getTotalOutstandingAllocations());*/

	sgdc::DynamicArray<int>* dynamicArray = new sgdc::DynamicArray<int>(*countingAllocator, 10);
	printf("%u\n", countingAllocator->getOutstandingAllocations());
	printf("%u\n", dynamicArray->getSize());

	dynamicArray->append(0);
	dynamicArray->append(1);
	dynamicArray->append(2);
	dynamicArray->append(3);
	dynamicArray->append(4);
	dynamicArray->append(5);
	dynamicArray->append(6);
	dynamicArray->append(7);
	dynamicArray->append(8);
	dynamicArray->append(9);
	dynamicArray->append(10);

	printf("%u\n", countingAllocator->getOutstandingAllocations());
	printf("%u\n", dynamicArray->getSize());

	dynamicArray->prepend(-1);
	dynamicArray->prepend(-2);

	dynamicArray->insert(13, 12);
	dynamicArray->insert(13, 11);


	for (unsigned int i = 0; i < dynamicArray->getSize(); i++) {
		printf("%i, ", dynamicArray->get(i));
	}
	printf("\n");

	delete dynamicArray;
	printf("%u\n", countingAllocator->getOutstandingAllocations());


	return 0;
}
