/*
	Dominik Jedruszczak

	default_allocator.hpp
	The declaration of the "DefaultAllocator" class.
*/

#ifndef INCLUDED_DEFAULT_ALLOCATOR
#define INCLUDED_DEFAULT_ALLOCATOR

#include "allocator.hpp"

namespace sgdm { // Stevens Game Development Memory.
	/* The default allocator for containers. */
	template<typename T>
	class DefaultAllocator : public Allocator<T> {
		private:
			/* Data Member(s). */
			/* Function(s). */
		public:
			/* Constructor(s). */
			/* Destructor(s). */
			/* Data Member(s). */
			/* Function(s). */
			T* allocate(unsigned int count); // Allocate the specified amount of memory and return a pointer to the newly allocated memory block.
			void deallocate(T* memoryBlock, unsigned int count); // Deallocate the specified amount of memory from the specified memory block.
	};
}

#endif
