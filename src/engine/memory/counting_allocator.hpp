/*
	Dominik Jedruszczak

	counting_allocator.hpp
	The declaration of the "CountingAllocator" class.
*/

#ifndef INCLUDED_COUNTING_ALLOCATOR
#define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator.hpp"

namespace sgdm { // Stevens Game Development Memory.
	/* An allocator which counts allocations and deallocations for each instance, and all instances. */
	template<typename T>
	class CountingAllocator : public DefaultAllocator<T> {
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

	/* Initialize the static "CountingAllocator" data members. */
        template<typename T>
        unsigned int CountingAllocator<T>::totalAllocations = 0;
        template<typename T>
        unsigned int  CountingAllocator<T>::totalDeallocations = 0;

        /* Default constructor. */
        template<typename T>
        CountingAllocator<T>::CountingAllocator() {
                allocations = 0;
                deallocations = 0;
        }

        /* Copy constructor. */
        template<typename T>
        CountingAllocator<T>::CountingAllocator(const CountingAllocator<T>& countingAllocator) {
                allocations = countingAllocator.getAllocations();
                deallocations = countingAllocator.getDeallocations();
        }

        /* Copy assignment operator. */
        template<typename T>
        CountingAllocator<T>& CountingAllocator<T>::operator = (const CountingAllocator<T>& countingAllocator) {
                /* Avoid self-assignment. */
                if (*this != countingAllocator) {
                        ;
                }

                return *this;
        }

        /* Allocate the specified amount of memory and return a pointer to the newly allocated memory block. */
        template<typename T>
        T* CountingAllocator<T>::allocate(unsigned int count) {
                allocations += count;
                totalAllocations += count;

                return new T[count];
        }

	/* Deallocate the specified amount of memory from the specified memory block. */
        template<typename T>
        void CountingAllocator<T>::deallocate(T* memoryBlock, unsigned int count) {
                deallocations += count;
                totalDeallocations += count;

                delete memoryBlock;
		memoryBlock = NULL;
        }

        /* Return the number of allocations. */
        template<typename T>
        const unsigned int CountingAllocator<T>::getAllocations() {
                return allocations;
        }

        /* Return the number of deallocations. */
        template<typename T>
        const unsigned int CountingAllocator<T>::getDeallocations() {
                return deallocations;
        }

        /* Return the number of outstanding allocations. */
        template<typename T>
        const unsigned int CountingAllocator<T>::getOutstandingAllocations() {
                return allocations - deallocations;
        }

	/* Return the number of allocations across all "CountingAllocator" instances. */
        template<typename T>
        const unsigned int CountingAllocator<T>::getTotalAllocations() {
                return totalAllocations;
        }

        /* Return the number of deallocations across all "CountingAllocator" instances. */
        template<typename T>
        const unsigned int CountingAllocator<T>::getTotalDeallocations() {
                return totalDeallocations;
        }

        /* Return the number of outstanding allocations across all "CountingAllocator" instances. */
        template<typename T>
        const unsigned int CountingAllocator<T>::getTotalOutstandingAllocations() {
                return totalAllocations - totalDeallocations;
        }
}

#endif
