#if defined(fidsonfds)
/*
 * Title:  LinkedList.h
 * Author:  April Crockett, modified by Rus Hoffman
 * Date:  2/4/2018
 * Purpose:  A template class which implements a singly-linked list.
 */
namespace qLib {
#if !defined(LINKEDLISTSORTING_HPP)
#define LINKEDLISTSORTING_HPP

#include "LinkedListPlusPlus.hpp"
#include <iostream>
	/*
	 #if __cplusplus >= 201103L
	 #include <chrono>
	 #include <random>
	 #else
	 #include <cstdlib>
	 #endif
	 */
	using namespace std;
	double multiply(double left, double right) {
		return left * right;
	}

	double binary_op(double left, double right, double (*f)(double, double)) {
		return (*f)(left, right);
	}

	template<typename Tvar> size_t search_LinearSearch(LinkedListPlus<Tvar>* theList, Tvar* key, bool (*comparisonFunctionIsEqual)(Tvar, Tvar)) {
		for (size_t currentCompareTo = 0; currentCompareTo < theList->getLength(); currentCompareTo++) {
			if((*comparisonFunctionIsEqual)(theList->getNodeValue(currentCompareTo), key)) {
				return currentCompareTo;
			}
		}
		return -1;
	}
	size_t search_BinarySearch();

	template<typename Tvar> Tvar* search_BinarySearchWorker(Tvar* key, Tvar** array, size_t first, size_t last);

	template<typename Tvar> void sort_BubbleSort(LinkedListPlus<Tvar>* theList, bool (*comparisonFunctionIsFirstLower)(Tvar, Tvar)) {
		for (size_t maxElement = theList->getLength() - 1; maxElement > 0; maxElement--) {
			for (size_t i = 0; i < maxElement; i++) {
				//If out of order, swap
				if(!(*comparisonFunctionIsFirstLower)(theList->getNodeValue(i), theList->getNodeValue(i + 1))) {
					theList->swapNodes(i, i + 1);
				}
			}
		}
	}

	template<typename Tvar> void sort_InsertionSort(){

		Text* key;   //key is the item that we are sorting at the moment
		Text* currentComparingValue;
		size_t keyIndex;
		size_t lastSortedIndex;

		size_t j;   //j is the position of where key should be inserted into the sorted array

		cout << "\nSorting the array with the Insertion Sort algorithm.\n\n";

		//i will hold the subscript of the unsorted array
		size_t limit = movieList->getLength();
		for (size_t unsortedIndexStart = 1; unsortedIndexStart < limit; unsortedIndexStart++) {
			for (size_t unsortedCompareToThisPoint = unsortedIndexStart - 1; unsortedCompareToThisPoint >= 0 && movieList->getNodeValue(unsortedIndexStart) < unsortedCompareToThisPoint; unsortedCompareToThisPoint++) {
				if(movieList->getNodeValue(unsortedIndexStart) < unsortedCompareToThisPoint) {
					movieList->swapNodes(unsortedIndexStart, unsortedCompareToThisPoint);
				}
				else {
					break;
				}
			}
		}



	}
	void sort_InsertionSortDescending();
	void sort_SelectionSort();
	void sort_MergeSort();
	void sortHelper_Merge();
	void sort_QuickSort();
	void sortHelper_Partition();

#endif
}
#endif
