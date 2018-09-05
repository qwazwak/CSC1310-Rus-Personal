/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:      CSC1310 - Program 01 - Bootleg String Class
 *	Author(s):  Rus Hoffman
 *	Date:       September 4, 2018
 *	Purpose:
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
#include "Movie.h"
#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

/*
 Text* movieTitle;  //title of movie
 long movieLength; //length of movie in minutes
 long movieYear; //year released
 Text* movieGenre; //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
 Text* movieRating; //G, PG, PG-13, R, MA
 long movieOscars; //number of oscars won
 double movieNumStars; //taken from IMDB on 10 star scale
 */
/*
 movieTitle;
 movieLength;
 movieYear;
 movieGenre;
 movieRating;
 movieOscars;
 movieNumStars;


 Text* movieTitle;
 long movieLength;
 long movieYear;
 Text* movieGenre;
 Text* movieRating;
 long movieOscars;
 double movieNumStars;
 Text* movieTitle = inputTitle;
 long movieLength = inputLength;
 long movieYear = inputYear;
 Text* movieGenre = inputGenre;
 Text* movieRating = inputRating;
 long movieOscars = inputOscars;
 double movieNumStars = inputStars;
 */

Movie::Movie () {
	movieTitle = new Text;
	movieLength = NULL;
	movieYear = NULL;
	movieGenre = new Text;
	movieRating = new Text;
	movieOscars = NULL;
	movieNumStars = NULL;
}

//Overloading Constructor for quicker setup
Movie::Movie (Text* inputTitle, long inputLength, long inputYear, Text* inputGenre, Text* inputRating, long inputOscars, double inputStars) {
	movieTitle = inputTitle;
	movieLength = inputLength;
	movieYear = inputYear;
	movieGenre = inputGenre;
	movieRating = inputRating;
	movieOscars = inputOscars;
	movieNumStars = inputStars;
}

//Destructor
Movie::~Movie () {
	delete movieTitle;
	delete movieGenre;
	delete movieRating;
}

//Functions:

/*
 Function name:  editMovieDetails
 Parameters:  	editMovieDetails
 Returns: 		editMovieDetails
 Purpose:  		This function should be called when the user wants to edit a single movie's data
 */
void Movie::editMovieDetails () {
	int choice;
	long OGLongData;
	double OGDoubleData;
	char temp[100];

	do {

		cout << "Which detail do you wish to edit?" << endl;
		cout << "1.  Title" << endl;
		cout << "2.  Length" << endl;
		cout << "3.  Year" << endl;
		cout << "4.  Genre" << endl;
		cout << "5.  Rating" << endl;
		cout << "6.  Number of Oscars Won" << endl;
		cout << "7.  Number of Stars" << endl;
		cout << "8.  DONE EDITING" << endl;
		cout << "Enter the number of your selection 1-8:  ";
		cin >> choice;
		cout << endl;
		while (choice < 1 || choice > 8 || cin.fail ()) {
			cin.clear ();
			cout << "Error: make sure you enter only a choice 1 through 8:  ";
			cin >> choice;
		}
		cin.ignore ();

		switch (choice) {
			case 1:
				cout << endl << "Current Title: ";
				movieTitle->displayText ();
				cout << endl << "NEW TITLE:  ";
				cin.getline (temp, 500);
				cout << endl;
				while (cin.fail ()) {
					cout << "An error has occurred" << endl << endl;

					cout << "Current Title: ";
					movieTitle->displayText ();
					cout << endl << "NEW TITLE:  ";
					cin.getline (temp, 500);
				}

				movieTitle->editText (temp);
				break;

			case 2:
				OGLongData = movieLength;
				cout << endl << "Current Length: " << OGLongData;
				cout << endl << "NEW LENGTH:     ";
				cin >> movieLength;
				while (cin.fail () || movieLength <= 0) {
					if (cin.fail () == true) {
						cout << "An error has occurred" << endl;
					}
					cin.clear ();
					cout << "be sure to enter only numbers greater than zero" << endl;
					cout << endl << "Current Length: " << OGLongData;
					cout << endl << "NEW LENGTH:     ";
					cin >> movieLength;
				}
				cin.clear ();
				cin.ignore ();
				break;

			case 3:

				OGLongData = movieYear;
				cout << endl << "Current Year: " << OGLongData;
				cout << endl << "NEW YEAR:     ";
				cin >> movieYear;
				while (cin.fail () || movieYear <= 0) {
					if (cin.fail () == true) {
						cout << "An error has occurred" << endl;
					}
					cin.clear ();
					cout << "be sure to enter only numbers greater than zero" << endl;
					cout << endl << "Current Year: " << OGLongData;
					cout << endl << "NEW YEAR:     ";
					cin >> movieYear;
				}
				cin.clear ();
				cin.ignore ();
				break;

			case 4:
				cout << endl << "Current Genre: ";
				movieGenre->displayText ();
				cout << endl << "NEW GENRE:  ";
				cin.getline (temp, 500);
				cout << endl;
				while (cin.fail ()) {
					cout << "An error has occurred" << endl << endl;

					cout << "Current Genre: ";
					movieGenre->displayText ();
					cout << endl << "NEW GENRE:  ";
					cin.getline (temp, 500);
				}

				movieGenre->editText (temp);
				break;

			case 5:
				cout << endl << "Current Rating: ";
				movieRating->displayText ();
				cout << endl << "NEW RATING:  ";
				cin.getline (temp, 500);
				cout << endl;
				while (cin.fail ()) {
					cout << "An error has occurred" << endl << endl;

					cout << "Current Rating: ";
					movieRating->displayText ();
					cout << endl << "NEW Rating:  ";
					cin.getline (temp, 500);
				}

				movieRating->editText (temp);
				break;

			case 6:
				OGLongData = movieOscars;
				cout << endl << "Current Oscars: " << OGLongData;
				cout << endl << "NEW OSCARS:     ";
				cin >> movieOscars;
				while (cin.fail () || movieOscars <= 0) {
					if (cin.fail () == true) {
						cout << "An error has occurred" << endl;
					}
					cin.clear ();
					cout << "be sure to enter only numbers greater than zero" << endl;
					cout << endl << "Current Oscars: " << movieYear;
					cout << endl << "NEW OSCARS:     ";
					cin >> movieOscars;
				}
				cin.clear ();
				cin.ignore ();
				break;

			case 7:

				OGDoubleData = movieNumStars;
				cout << endl << "Current IMDB Rating: " << OGDoubleData;
				cout << endl << "NEW IMDB RATING:     ";
				cin >> movieOscars;
				while (cin.fail () || movieNumStars < 0) {
					if (cin.fail () == true) {
						cout << "An error has occurred" << endl;
					}
					cin.clear ();
					cout << "be sure to enter only numbers greater than zero" << endl;
					cout << endl << "Current IMDB Rating: " << OGDoubleData;
					cout << endl << "NEW IMDB RATING:     ";
					cin >> movieNumStars;
				}
				cin.clear ();
				cin.ignore ();
				break;
		}
	} while (choice != 8);
}

/*	Function name:  setMovieDetailXXXX
 Parameters:  	A pointer to a movie structure
 A pointer to a Text variable, containing the title of the movie
 An integer containing the length of the movie
 An integer containing the year the movie was released
 A pointer to a Text variable, containing the genre of the movie
 A pointer to a Text variable, containing the rating of the movie
 An integer containing the number of oscars the movie won
 A float containing the IMDB rating of the movie (out of 10 stars)
 Returns: 		nothing (void)
 Purpose:  		This function should be called when the program wants to edit a single movie's single part of data
 */
void Movie::setMovieFull (Text* inputTitle, long inputLength, long inputYear, Text* inputGenre, Text* inputRating, long inputOscars, double inputStars) {
	Text* movieTitle = inputTitle;
	long movieLength = inputLength;
	long movieYear = inputYear;
	Text* movieGenre = inputGenre;
	Text* movieRating = inputRating;
	long movieOscars = inputOscars;
	double movieNumStars = inputStars;
}
void Movie::setMovieDetailTitle (Text* inputTitle) {
	Text* movieTitle = inputTitle;
}
void Movie::setMovieDetailLength (long inputLength) {
	long movieLength = inputLength;
}
void Movie::setMovieDetailReleaseYear (long inputYear) {
	long movieYear = inputYear;
}
void Movie::setMovieDetailGenre (Text* inputGenre) {
	Text* movieGenre = inputGenre;
}
void Movie::setMovieDetailRating (Text* inputRating) {
	Text* movieRating = inputRating;
}
void Movie::setMovieDetailOscarCount (long inputOscars) {
	long movieOscars = inputOscars;
}
void Movie::setMovieDetailIMBDRating (double inputStars) {
	double movieNumStars = inputStars;
}

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
Text* Movie::getMovieDetailTitle () {
	return movieTitle;
}
long Movie::getMovieDetailLength () {
	return movieLength;
}
long Movie::getMovieDetailReleaseYear () {
	return movieYear;
}
Text* Movie::getMovieDetailGenre () {
	return movieGenre;
}
Text* Movie::getMovieDetailRating () {
	return movieRating;
}
long Movie::getMovieDetailOscarCount () {
	return movieOscars;
}
double Movie::getMovieDetailIMBDRating () {
	return movieNumStars;
}

/*
 Function name:  printMovieDetails
 Parameters:  	nothing (void)
 Returns: 		nothing (void)
 Purpose:  		This function should be called when the user wants to print ALL the movie information to the screen.
 */
void Movie::printMovieDetails () {

	cout << right << setw(30) << "Movie Title:  " << left << movieTitle->getText () << "\n";
	cout << right << setw(30) << "Length (minutes):  " << left << movieLength << "\n";
	cout << right << setw(30) << "Year Released:  " << left << movieYear << "\n";
	cout << right << setw(30) << "Genre:  " << left< movieGenre->getText () << "\n";
	cout << right << setw(30) << "Rating:  " << left << movieRating->getText () << "\n";
	cout << right << setw(30) << "Number of Oscars Won:  " << left << movieOscars << "\n";
	cout << right << setw(30) << "Number of Stars:  " << left << movieNumStars << "\n" << flush;
}

/*
 Function name:  printMovieDetailsToFile
 Parameters:  	a file stream object (sent by reference)
 Returns: 		nothing (void)
 Purpose:  		This function should be called when the user wants to print ALL the movie information to the file.
 */
void Movie::printMovieDetailsToFile (ofstream &outFile) {
	outFile << movieTitle->getText () << "\n";
	outFile << movieLength << "\n";
	outFile << movieYear << "\n";
	outFile << movieGenre->getText () << "\n";
	outFile << movieRating->getText () << "\n";
	outFile << movieOscars << "\n";
	outFile << movieNumStars << "\n" << flush;
}
