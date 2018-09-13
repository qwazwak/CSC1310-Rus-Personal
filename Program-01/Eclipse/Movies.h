/*
 Title:  Movies.h
 Author:  April R Crockett
 Date:  11/7/2017
 Purpose:  Be able to create, manage, print, save & delete a movie library
 */
#if !defined(MOVIES_H)
#define MOVIES_H

#include "Movie.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Movies {
	private:
		//Variables:
		Movie** moviesArray;	//The main array of pointers - each pointer points to a single Movie
		size_t arraySize;		//Number of allocated 'movie' spots
		size_t numMovies;		//Number of stored movies
		//size_t maxMovies;		//Maximum storable movies

		/*
		 Function name:	expandarray
		 Parameters:		none (void)
		 Returns: 		none (void)
		 Purpose:  		Double the capacity of the moviesArray
		 */
		long letUserSelectMovie ();

		/*
		 Function name:	expandarray
		 Parameters:		none (void)
		 Returns: 		none (void)
		 Purpose:  		Double the capacity of the moviesArray
		 */
		void expandarray ();

		/*
		 Function name:	removeMovieByID
		 Parameters:		none (void)
		 Returns: 		none (void)
		 Purpose:  		remove one movie from the array and shift other movies as required
		 */
		void removeMovieByID (long);
	public:
		Movies ();

		//Destructor
		~Movies ();

		/*
		 Function names:	addMovieToArrayDirect
		 Parameters:		a pointer to a movie to add
		 Returns: 		none
		 Purpose:  		This function should be called when the program/programmer needs to add a single movie to the movie library directly and quickly.
		 */
		void addMovieToArrayDirect (Movie* inputMoviePointer);

		/*
		 Function names:	addMovieToArrayFromUser
		 Parameters:		none
		 Returns: 		none
		 Purpose:  		This function should be called when the user wants to add a single movie to the movie library and inpout the movie details
		 */
		void addMovieToArrayFromUser ();

		/*
		 Function name:	editMovieInArray
		 Parameters:		none
		 Returns:			none
		 Purpose:			This function should be called when you need to edit a movie in the array
		 */
		void editMovieInArray ();

		/*
		 Function name:	destroyMovies
		 Parameters:		1) The movies structure (which contains the movie library)
		 Returns:			none (void)
		 Purpose:			This function should be called when you need to remove all the single
		 movies in the movie library as well as the movie library.  This releases
		 all the dynamically allocated space in memory.
		 */
		void removeMovieFromUser ();

		/*
		 Function name:	displayAllMoviesOnlyTitle
		 Parameters:		1) The movies structure (which contains the movie library)
		 Returns:			none (void)
		 Purpose:			This function should be called when the user wants to have all the movies
		 in the library printed to the screen.
		 */
		void displayAllMoviesOnlyTitle ();

		/*
		 Function name:	displayMoviesFullDetails
		 Parameters:		nothing (void)
		 Returns:			nothing (void)
		 Purpose:  		This function should be called when the user wants to have all the movies and all details in the library printed to the screen.
		 */
		void displayAllMoviesFullDetails ();

		/*
		 Function name:	removeMovieFromArray
		 Parameters:		The movies structure (which contains the movie library)
		 Returns:			none (void)
		 Purpose:			This function should be called when the user wants to remove one single movie
		 from the movie library.  The function will list all the movie names and allow
		 the user to select the movie that they wish to remove. Then this function removes the movie.
		 */
		void removeMovieByUserChoice ();

		/*
		 Function name:	importFromFile
		 Parameters:		A string or char array of the filename, with extention. Only supports pure text
		 Returns:			nothing (void)
		 Purpose:			This function should be called when the program/programmer wants to read movie data from a file and add the movies to the movie library.  The file must have data in the following order: title, length, year, genre, rating, num oscars won, star rating
		 */
		void importFromFile (string filename);
		void importFromFile (char* filename);

		/*
		 Function name:	exportToFile
		 Parameters:		A string or char array of the filename, with extention. Only supports pure text
		 Returns:			none (void)
		 Purpose:			This function should be called when the program/programmer wants to print all the movie data from the movie library to a file.  The data is printed in the following order (one piece of data per line): title, length, year, genre, rating, num oscars won, star rating
		 */
		void exportToFile (string filename);
		void exportToFile (char *filename);
};

#endif
