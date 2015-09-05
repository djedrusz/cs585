/*
	Dominik Jedruszczak

	default_allocator.cpp
	The implementation of the "DefaultAllocator" class.
*/

#include "default_allocator.hpp"

namespace sgdm { // Stevens Game Development Memory.
	/* Allocate the specified amount of memory and return a pointer to the newly allocated memory block. */
	template<typename T>
	T* DefaultAllocator<T>::allocate(unsigned int count) {
		return new T[count];
	}

	/* Deallocate the specified amount of memory from the specified memory block. */
	template<typename T>
	void DefaultAllocator<T>::deallocate(T* memoryBlock, unsigned int count) {
		delete memoryBlock;
	}
}
