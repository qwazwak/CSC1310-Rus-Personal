/*
 Title:  Movies.h
 Author:  April R Crockett, modified by Rus Hoffman
 Date:  11/7/2017
 Purpose:  Be able to create, manage, print, save & delete a movie library
 */
#if !defined(MOVIES_H)
#define MOVIES_H

#include "LinkedList.h"
#include "Movie.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Movies {
	private:
		LinkedList<Movie*>* movieList;
		//Movie** moviesArray; //an array of pointers - each pointer points to a single Movie
		//int maxMovies; //maximum number of elements in the array
		//int numMovies; //current number of movies in the array
		
		/*

		 o binarySearch - This function should search for a particular movie title to see if it is in the list.  It should return -1 if the Movie title could not be found.  Use the binary search algorithm to implement this function.
		 o bubbleSort – This function should sort the LinkedList of Movies in ascending order by Movie title. This function will call a function called swap in the linkedList class to swap values in the linked list when necessary.  Use the bubble sort algorithm to implement this function.

		 o insertionSort - This function should sort the LinkedList of Movies in ascending order by Movie title. This function will call a function called swap in the linkedList class to swap values in the linked list when necessary.  Use the insertion sort algorithm to implement this function.

		 o insertionSortDescending – This function should be the same as insertionSort except it will sort the LinkedList of Movies in descending order by Movie title instead of ascending order.

		 o selectionSort - This function should sort the LinkedList of Movies in ascending order by Movie title. This function will call a function called swap in the linkedList class to swap values in the linked list when necessary.  Use the selection sort algorithm to implement this function.

		 o mergeSort & merge – These two functions work together to implement the merge sort algorithm, which should sort the LinkedList of Movies in ascending order by Movie title.  The mergeSort function is a recursive function which calls the merge function.  The merge function dynamically allocates a new linked list of Movie pointers to use as the merged linked list.  At some point in the merge function you will need to replace a node….you will do this by deleting the node (deleteNode) at a particular position and then inserting a new node (insertNode function) at a particular position.

		 quickSort & partition – These two functions work together to implement the quick sort algorithm, which should sort the LinkedList of Movies in ascending order by Movie title.  The quicksort function is a recursive function which calls the partition function.  The partition function will use a pivot string (c-string).  The partition function will call a function called swap in the linkedList class to swap values in the linked list when necessary.

		 */

		void algorithmAnalysis();

		size_t search_LinearSearch(Text key);
		size_t search_BinarySearch(Text key);
		size_t search_BinarySearchWorker(Text &key, size_t first, size_t last);
		void sort_BubbleSort();
		void sort_InsertionSort();
		void sort_InsertionSortDescending();
		void sort_SelectionSort();
		void sort_MergeSortParent();
		void sortHelper_MergeSort_MergeSort(size_t start, size_t endPoint);
		void sortHelper_MergeSort_Merge(size_t startOfA, size_t endOfA, size_t startOfB, size_t endOfB);
		void sort_QuickSort();
		void sortHelper_Partition();

	public:
		/*
		 *	Function name:  Movies constructor
		 *	Parameters:  	An integer containing the maximum size of the movie library
		 *	Purpose:  		This function is automatically called when a Movies object is created and it creates a library
		 *					of movies.  The function will dynamically allocate a movies array based
		 *					on the maximum size and will also set the current number of movies to zero.
		 */
		Movies();

		/*
		 *	Function name:  ~Movies destructor
		 *	Purpose:  		This function is automatically called when the Movies object is destroyed.
		 *					This releases the dynamically created individual movies and then deletes the array.
		 */
		~Movies();

		/*
		 *	Function name:  addMovieToArray
		 *	Parameters:  	none
		 *	Returns: 		A boolean indicating if the movie was able to be added or not
		 *	Purpose:  		This function should be called when you need to add a single movie to the
		 *					movie library.
		 */
		void addMovieToList();

		void insertionSort();
		size_t binarySearch(size_t, size_t, Text*);

		/*
		 *	Function name:  displayMovies
		 *	Parameters:  	none
		 *	Returns: 		none (void)
		 *	Purpose:  		This function should be called when the user wants to have all the movies
		 *					in the library printed to the screen.
		 */
		void displayMovies();

		/*
		 *	Function name:  displayMovieTitles
		 *	Parameters:  	none
		 *	Returns: 		none (void)
		 *	Purpose:  		This function should be called when you want to print only the movie titles
		 *					out of the movie library
		 */
		void displayMovieTitles();

		/*
		 *	Function name:  readMoviesFromFile
		 *	Parameters:  	A pointer to a character (c-string or string literal argument) containing the filename
		 *	Returns: 		none (void)
		 *	Purpose:  		This function should be called when the user wants to read movie data from a file
		 *					and add the movies to the movie library.  The file must have data in the following order:
		 *					title, length, year, genre, rating, number of Oscars won, star rating
		 */
		void readMoviesFromFile(char *filename);
		void readMoviesFromFile(string filename);
		void readMoviesFromFile(const char* filename);

		/*
		 *	Function name:  removeMovieFromList
		 *	Parameters:  	none
		 *	Returns: 		none (void)
		 *	Purpose:  		This function should be called when the user wants to remove one single movie
		 *					from the movie library.  The movie to be removed must is identified
		 *					by the user and then removed.
		 */
		void removeMovieFromList();

		/*
		 *	Function name:  editMovieInList
		 *	Parameters:  	none
		 *	Returns: 		none
		 *	Purpose:  		This function should be called when you need to edit a movie in the list
		 */
		void editMovieInList();

		/*
		 *	Function name:  saveToFile
		 *	Parameters:  	A pointer to a character (c-string or string literal argument) containing the filename
		 *			OR	a string containing the filename
		 *	Returns: 		none (void)
		 *	Purpose:  		This function should be called when the user wants to print all the movie data
		 *					from the movie library to a file.  The data is printed in the following order (one piece
		 *					of data per line):
		 *					title, length, year, genre, rating, num oscars won, star rating
		 */
		void saveToFile(string filename);
		void saveToFile(char *filename);

		//accessor functions to get the attribute values
		size_t getNumMovies() const;
		

};

#endif
