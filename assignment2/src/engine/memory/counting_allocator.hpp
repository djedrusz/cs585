/*
	Dominik Jedruszczak

	counting_allocator.hpp
	The declaration of the "CountingAllocator" class.
*/

#ifndef INCLUDED_COUNTING_ALLOCATOR
#define INCLUDED_COUNTING_ALLOCATOR

#include "allocator.hpp"

namespace sgdm { // Stevens Game Development Memory.
	/* An allocator which counts allocations and deallocations for each instance, and all instances. */
	template<typename T>
	class CountingAllocator : public Allocator<T> {
		private:
			/* Data member(s). */
			unsigned int allocations; // The number of allocations.
			unsigned int deallocations; // The number of deallocations.
			static unsigned int totalAllocations; // The number of allocations across all "CountingAllocator" instances.
			static unsigned int totalDeallocations; // The number of deallocations across all "CountingAllocator" instances.
		public:
			/* Constructor(s). */
			CountingAllocator(); // Default constructor.
			CountingAllocator(const CountingAllocator<T>& countingAllocator); // Copy contructor.
			/* Operators. */
			CountingAllocator<T>& operator = (const CountingAllocator<T>& countingAllocator); // Copy assignment operator.
			/* Function(s). */
			T* allocate(unsigned int count); // Allocate the specified amount of memory and return a pointer to the newly formed memory block.
			void deallocate(T* memoryBlock, unsigned int count); // Deallocate the specified amount of memory from the memory block.
			const unsigned int getAllocations(); // Return the number of allocations.
			const unsigned int getDeallocations(); // Return the number of deallocations.
			const unsigned int getOutstandingAllocations(); // Return the number of outstanding allocations.
			const unsigned int getTotalAllocations(); // Return the number of allocations across all "CountingAllocator" intances.
			const unsigned int getTotalDeallocations(); // Return the number of deallocations across all "CountingAllocator" instances.
			const unsigned int getTotalOutstandingAllocations(); // Return the number of outstanding allocations across all "CountingAllocator" instances.
	};
}

#endif
