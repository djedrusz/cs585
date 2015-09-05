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
			sgdm::Allocator<T>& allocator; // The allocator.
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

    // TODO: Merge grow and shrink into one function that takes an unsigned int "newCapacity" arg$

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

#endif
