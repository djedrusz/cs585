/*
	Dominik Jedruszczak

	dynamic_array.hpp
	Declaration of the "DynamicArray" class.
*/

#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLUDED_DYNAMIC_ARRAY

#include <cstring>
#include "../memory/default_allocator.hpp"

#define DYNAMIC_ARRAY_DEFAULT_ALLOCATOR *(new sgdm::DefaultAllocator<T>()) // The default allocator.
#define DYNAMIC_ARRAY_DEFAULT_CAPACITY 10 // The default capacity.
#define DYNAMIC_ARRAY_GROW_RATIO 1.5 // The ratio at which the array grows.
#define DYNAMIC_ARRAY_SHRINK_THRESHOLD_RATIO 0.25 // The threshold at which the array shrinks.
#define DYNAMIC_ARRAY_SHRINK_RATIO 0.5 // The ratio at which the array shrinks.

namespace sgdc { // Stevens Game Development Containers.
	/* An array which grows and shrinks dynamically. */
	template<typename T>
	class DynamicArray {
		private:
			/* Data member(s). */
			const sgdm::Allocator<T>& allocator; // The allocator.
			T* array; // The underlying array.
			unsigned int capacity; // The current maximum number of elements.
			unsigned int size; // The current number of elements.
			/* Function(s). */
			void grow(); // Increase the capacity of the array.
			void shrink(); // Decrease the capacity of the array.
			// TODO: Merge grow and shrink into one function which takes an unsigned int "newCapacity" argument.
		public:
			/* Constructor(s). */
			DynamicArray(); // Default constructor.
			DynamicArray(sgdm::Allocator<T>& _allocator); // Constructor with specified allocator.
			DynamicArray(unsigned int _capacity); // Constructor with specified initial capacity.
			DynamicArray(sgdm::Allocator<T>& _allocator, unsigned int _capacity); // Constructor with specified allocator and initial capacity.
			/* Destructor(s). */
			~DynamicArray(); // Default destructor.
			/* Operator(s). */
			DynamicArray<T>& operator = (const DynamicArray<T>& dynamicArray); // Copy assignment operator.
			/* Function(s). */
			void prepend(const T& element); // Prepend an element.
			void append(const T& element); // Append an element.
			void insert(unsigned int index, const T& element); // Insert an element at the specified index.
			const T& pull(); // Remove and return the first element.
			const T& push(); // Remove and return the last element.
			const T& remove(unsigned int index); // Remove and return the element at the specified index.
			void set(unsigned int index, const T& element); // Set the element at the specified index.
			const T& get(unsigned int index); // Return the element at the specified index.
			const unsigned int getSize(); // Return the size.
	};
}

#endif
