#ifndef MOVIE_H
#define MOVIE_H
/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:      CSC1310 - Program 01 - Bootleg String Class
 *	Author(s):  Rus Hoffman
 *	Date:       September 4, 2018
 *	Purpose:
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Movie {
	private:
		//Variables:
		Text* movieTitle;    //title of movie
		long movieLength;    //length of movie in minutes
		long movieYear;    //year released
		Text* movieGenre;    //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
		Text* movieRating;    //G, PG, PG-13, R, MA
		long movieOscars;    //number of oscars won
		double movieNumStars;    //taken from IMDB on 10 star scale

		//Private functions:

	public:
		Movie ();

		//Overloading Constructor for quicker setup
		Movie (Text*, long, long, Text*, Text*, long, double);
		Movie (char*, long, long, char*, char*, long, double);
		Movie (string, long, long, string, string, long, double);

		//Destructor
		~Movie ();

		/*
		 Function name:  editMovieDetails
		 Parameters:  	editMovieDetails
		 Returns: 		editMovieDetails
		 Purpose:  		This function should be called when the user wants to edit a single movie's data
		 */
		void editMovieDetails ();

		/*
		 Function name:  setMovieDetailXXXX
		 Parameters:  	A pointer to a movie structure
		 A pointer to a Text variable, containing the title of the movie
		 An integer containing the length of the movie
		 An integer containing the year the movie was released
		 A pointer to a Text variable, containing the genre of the movie
		 A pointer to a Text variable, containing the rating of the movie
		 An integer containing the number of oscars the movie won
		 A float containing the IMDB rating of the movie (out of 10 stars)
		 Returns: 		nothing (void)
		 Purpose:  		This function should be called when the user wants to edit a single
		 movie's data
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
		 Function name:  getMovieDetailXXXX
		 Parameters:  		A pointer to a Text variable, containing the title of the movie
		 An integer containing the length of the movie
		 An integer containing the year the movie was released
		 A pointer to a Text variable, containing the genre of the movie
		 A pointer to a Text variable, containing the rating of the movie
		 An integer containing the number of oscars the movie won
		 A float containing the IMDB rating of the movie (out of 10 stars)
		 Returns: 		the contained value
		 Purpose:  		This function should be called when the user wants to access a single movie's data
		 */
		Text* getMovieDetailTitle ();
		long getMovieDetailLength ();
		long getMovieDetailReleaseYear ();
		Text* getMovieDetailGenre ();
		Text* getMovieDetailRating ();
		long getMovieDetailOscarCount ();
		double getMovieDetailIMBDRating ();

		/*
		 Function name:  printMovieDetails
		 Parameters:  	nothing (void)
		 Returns: 		nothing (void)
		 Purpose:  		This function should be called when the user wants to print ALL the movie information to the screen.
		 */
		void printMovieTitle ();

		/*
		 Function name:  printMovieDetails
		 Parameters:  	nothing (void)
		 Returns: 		nothing (void)
		 Purpose:  		This function should be called when the user wants to print ALL the movie information to the screen.
		 */
		void printMovieDetails ();

		/*
		 Function name:  printMovieDetailsToFile
		 Parameters:  	a file stream object (sent by reference)
		 Returns: 		nothing (void)
		 Purpose:  		This function should be called when the user wants to print ALL the movie information to the file.
		 */
		void printMovieDetailsToFile (ofstream &outFile);

};

#endif // MOVIE_H
