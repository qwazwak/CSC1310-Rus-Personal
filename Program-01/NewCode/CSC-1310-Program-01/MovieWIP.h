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
			Text* movieTitle;  //title of movie
			int movieLength; //length of movie in minutes
			int movieYear; //year released
			Text* movieGenre; //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
			Text* movieRating; //G, PG, PG-13, R, MA
			int movieOscars; //number of oscars won
			float movieNumStars; //taken from IMDB on 10 star scale

		//Private functions:


	public:
		Movie() {
			textIsAllocated = false;
			textLength = 0;
		}
			/
		//Overloading Constructor for quicker setup
		Movie(const char* inputText) {

		}

		//Destructor
		~Movie() {
			if (textIsAllocated == true) {
				delete[] textArray;
			}
		}

		//Functions:


};


#endif // MOVIE_H
