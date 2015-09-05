/*
	Dominik Jedruszczak

	dynamic_array.cpp
	Implementation of the "DynamicArray" class.
*/

#include "dynamic_array.hpp"

namespace sgdc { // Stevens Game Development Containers.
	/* Increase the capacity of the array. */
	template<typename T>
	void DynamicArray<T>::grow() {
		unsigned int newCapacity = (unsigned int)(capacity * DYNAMIC_ARRAY_GROW_RATIO);
		T* newArray = allocator.allocate(newCapacity);
		memcpy(newArray, array, size * sizeof(T));
		allocator.deallocate(array, capacity);
		capacity = newCapacity;
		array = newArray;
	}

	/* Decrease the capacity of the array. */
	template<typename T>
	void DynamicArray<T>::shrink() {
		unsigned int newCapacity = (unsigned int)(capacity * DYNAMIC_ARRAY_SHRINK_RATIO);
		T* newArray = allocator.allocate(newCapacity);
		memcpy(newArray, array, size * sizeof(T));
		allocator.deallocate(array, capacity);
		capacity = newCapacity;
		array = newArray;
	}

	// TODO: Merge grow and shrink into one function that takes an unsigned int "newCapacity" argument. */

	/* Default constructor. */
	template<typename T>
	DynamicArray<T>::DynamicArray()
	: allocator(DYNAMIC_ARRAY_DEFAULT_ALLOCATOR) {
		array = allocator.allocate(DYNAMIC_ARRAY_DEFAULT_CAPACITY);
		capacity = DYNAMIC_ARRAY_DEFAULT_CAPACITY;
		size = 0;
	}

	/* Constructor with specified allocator. */
	template<typename T>
	DynamicArray<T>::DynamicArray(sgdm::Allocator<T>& _allocator)
	: allocator(_allocator) {
		array = allocator.allocate(DYNAMIC_ARRAY_DEFAULT_CAPACITY);
		capacity = DYNAMIC_ARRAY_DEFAULT_CAPACITY;
		size = 0;
	}

	/* Constructor with specified initial capacity. */
	template<typename T>
	DynamicArray<T>::DynamicArray(unsigned int _capacity)
	: allocator(DYNAMIC_ARRAY_DEFAULT_ALLOCATOR) {
		array = allocator.allocate(_capacity);
		capacity = _capacity;
		size = 0;
	}

	/* Constructor with specified allocator and inital capacity. */
	template<typename T>
	DynamicArray<T>::DynamicArray(sgdm::Allocator<T>& _allocator, unsigned int _capacity)
	: allocator(_allocator) {
		array = allocator.allocate(_capacity);
		capacity = _capacity;
		size = 0;
	}

	/* Default destructor. */
	template<typename T>
	DynamicArray<T>::~DynamicArray() {
		allocator.deallocate(array, capacity);
	}

	/* Copy assignment operator. */
	template<typename T>
	DynamicArray<T>& DynamicArray<T>::operator = (const DynamicArray<T>& dynamicArray) {
		allocator = dynamicArray.allocator;
		array = allocator.allocate(dynamicArray.capacity);
		memcpy(array, dynamicArray.array, dynamicArray.capacity * sizeof(T));
		capacity = dynamicArray.capacity;
		size = dynamicArray.size;
	}

	/* Prepend an element. */
	template<typename T>
	void DynamicArray<T>::prepend(const T& element) {
		if (size >= capacity) {
			grow();
		}

		memmove(&array[1], array, size * sizeof(T));
		array[0] = element;
		size++;
	}

	/* Append an element. */
	template<typename T>
	void DynamicArray<T>::append(const T& element) {
		if (size >= capacity) {
			grow();
		}

		array[size] = element;
		size++;
	}

	/* Insert an element at the specified index. */
	template<typename T>
	void DynamicArray<T>::insert(unsigned int index, const T& element) {
		if (size >= capacity) {
			grow();
		}

		// Consider using "append" when index > (size - 1).

		memmove(&array[index + 1], &array[index], (size - index) * sizeof(T));
		array[index] = element;
		size++;
	}

	/* Remove and return the first element. */
	template<typename T>
	const T& DynamicArray<T>::pull() {
		const T& element = array[0];
		memmove(array, &array[1], (size - 1) * sizeof(T));
		size--;

		if (size <= capacity * DYNAMIC_ARRAY_SHRINK_THRESHOLD_RATIO) {
			shrink();
		}

		return element;
	}

	/* Remove and return the last element. */
	template<typename T>
	const T& DynamicArray<T>::push() {
		const T& element = array[size - 1];
		size--;

		if (size <= capacity * DYNAMIC_ARRAY_SHRINK_THRESHOLD_RATIO) {
			shrink();
		}

		return element;
	}

	/* Remove and return the element at the specified index. */
	template<typename T>
	const T& DynamicArray<T>::remove(unsigned int index) {
		const T& element = array[index];
		memmove(&array[index], &array[index + 1], (size - index) * sizeof(T));
		size--;

		if (size <= capacity * DYNAMIC_ARRAY_SHRINK_THRESHOLD_RATIO) {
			shrink();
		}

		return element;
	}

	/* Set the element at the specified index. */
	template<typename T>
	void DynamicArray<T>::set(unsigned int index, const T& element) {
		array[index] = element;
	}

	/* Return the element at the specified index. */
	template<typename T>
	const T& DynamicArray<T>::get(unsigned int index) {
		return array[index];
	}

	/* Return the size. */
	template<typename T>
	const unsigned int DynamicArray<T>::getSize() {
		return size;
	}
}
