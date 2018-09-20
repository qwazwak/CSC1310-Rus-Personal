/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Program 01 - Single Movie Encapsulation class
 *	Author(s):	Rus Hoffman
 *	Date:		September 4, 2018
 *	Purpose:		Practice working with classes which include member classes
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MOVIE_H
#define MOVIE_H

#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#if !defined(CLEARSCREEN_SIZE)
#define CLEARSCREEN_SIZE 100
#endif

class Movie {
	private:
		//Variables:
		Text* movieTitle;     //title of movie
		long movieLength;     //length of movie in minutes
		long movieYear;     //year released
		Text* movieGenre;     //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
		Text* movieRating;     //Age rating, EX: G, PG, PG-13, R, MA
		long movieOscars;     //number of Oscars won
		double movieNumStars;     //taken from IMDB on 10 star scale

		bool isOnlyNumaric (string input);
		bool isOnlyNumaricFloat (string input);

		void bootlegCLS ();

	public:
		Movie ();

		//Overloading Constructor for quicker setup
		Movie (Text*, long, long, Text*, Text*, long, double);
		Movie (char*, long, long, char*, char*, long, double);
		Movie (string, long, long, string, string, long, double);

		//Destructor
		~Movie ();

		/*
		 Function name:	editMovieDetails
		 Parameters:		nothing (void)
		 Returns:			nothing (void)
		 Purpose:			This function should be called to give the user a menu to edit the movie's details
		 */
		void editMovieDetails ();

		/*
		 Function name:	setMovieDetailXXX
		 Parameters:		Either the variable for that value, or all of them depending on which function
		 Returns:			nothing (void)
		 Purpose:			This function should be called when the program needs to replace a single movie's variable, or all of them
		 */
		void setMovieFull (Text*, long, long, Text*, Text*, long, double);
		void setMovieDetailTitle (Text*);
		void setMovieDetailLength (long);
		void setMovieDetailReleaseYear (long);
		void setMovieDetailGenre (Text*);
		void setMovieDetailRating (Text*);
		void setMovieDetailOscarCount (long);
		void setMovieDetailIMBDRating (double);

		/*
		 Function name:	getMovieDetailXXX
		 Parameters:		nothing (void)
		 Returns:			the contained value
		 Purpose:			This function should be called when the program needs to get a single movie's piece of data
		 */
		Text* getMovieDetailTitle ();
		long getMovieDetailLength ();
		long getMovieDetailReleaseYear ();
		Text* getMovieDetailGenre ();
		Text* getMovieDetailRating ();
		long getMovieDetailOscarCount ();
		double getMovieDetailIMBDRating ();

		/*
		 Function name:	printMovieTitle
		 Parameters:		nothing (void)
		 Returns:			nothing (void)
		 Purpose:			This function should be called when the program needs to print the movies title to the cout buffer
		 */
		void printMovieTitle ();

		/*
		 Function name:	printMovieDetails
		 Parameters:		nothing (void)
		 Returns: 		nothing (void)
		 Purpose:			This function should be called when the program needs to print ALL the movie information to the cout buffer
		 */
		void printMovieDetails ();

		/*
		 Function name:	printMovieDetailsNoFlush
		 Parameters:		nothing (void)
		 Returns: 		nothing (void)
		 Purpose:			This function should be called when the program needs to print ALL the movie information to the cout buffer, but without flushing the cout buffer
		 */
		void printMovieDetailsNoFlush ();

		/*
		 Function name:	printMovieDetailsToFile
		 Parameters:		a file stream object (sent by reference)
		 Returns:			nothing (void)
		 Purpose:  		This function should be called when the program needs to print ALL the movie information to a file. Does not modify stream settings at all
		 */
		void printMovieDetailsToFile (ofstream& outFile);

		/*
		 Function name:	printMovieDetailsToFileNoFlushing
		 Parameters:		a file stream object (sent by reference)
		 Returns: 		nothing (void)
		 Purpose:  		This function should be called when the program needs to print ALL the movie information to a file without flushing the buffer automatically. Does not modify stream settings at all
		 */
		void printMovieDetailsToFileNoFlushing (ofstream& outFile);

};

#endif //end MOVIE_H define
