/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Program 01 - Single Movie Encapsulation class
 *	Author(s):	Rus Hoffman
 *	Date:		September 4, 2018
 *	Purpose:		Practice working with classes which include member classes
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
#include "Movie.h"
#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

Movie::Movie () {
	movieTitle = new Text;
	movieLength = -1;
	movieYear = -1;
	movieGenre = new Text;
	movieRating = new Text;
	movieOscars = -1;
	movieNumStars = -1;
}

Movie::Movie (Text* inputTitle, long inputLength, long inputYear, Text* inputGenre, Text* inputRating, long inputOscars, double inputStars) {
	movieTitle = inputTitle;
	movieLength = inputLength;
	movieYear = inputYear;
	movieGenre = inputGenre;
	movieRating = inputRating;
	movieOscars = inputOscars;
	movieNumStars = inputStars;
}
Movie::Movie (char* inputTitle, long inputLength, long inputYear, char* inputGenre, char* inputRating, long inputOscars, double inputStars) {
	movieTitle = new Text(inputTitle);
	movieLength = inputLength;
	movieYear = inputYear;
	movieGenre = new Text(inputGenre);
	;
	movieRating = new Text(inputRating);
	movieOscars = inputOscars;
	movieNumStars = inputStars;
}
Movie::Movie (string inputTitle, long inputLength, long inputYear, string inputGenre, string inputRating, long inputOscars, double inputStars) {
	movieTitle = new Text(inputTitle);
	movieLength = inputLength;
	movieYear = inputYear;
	movieGenre = new Text(inputGenre);
	;
	movieRating = new Text(inputRating);
	movieOscars = inputOscars;
	movieNumStars = inputStars;
}

Movie::~Movie () {
#if defined(DEBUG)
	clog << "Movie CLASS DEBUG: " << "Deallocating memory" << endl;
#endif
	delete movieTitle;
	delete movieGenre;
	delete movieRating;
}

void Movie::editMovieDetails () {
	long choice;
	long OGLongData;
	double OGDoubleData;
	string inputTextBuffer;

	do {
#if defined(DEBUG)
		clog << "Movie CLASS DEBUG: " << "entering detail edit loop" << endl;
#endif
		cout << "\n";
		cout << "Which detail do you wish to edit?" << "\n";
		cout << "1.  Title" << "\n";
		cout << "2.  Length" << "\n";
		cout << "3.  Year" << "\n";
		cout << "4.  Genre" << "\n";
		cout << "5.  Rating" << "\n";
		cout << "6.  Number of Oscars Won" << "\n";
		cout << "7.  Number of Stars" << "\n";
		cout << "8.  DONE EDITING" << "\n";
		cout << "CHOOSE 1-8:  " << flush;
		cin >> choice;
		cout << "\n";
		while (choice < 1 || choice > 8 || cin.fail()) {
#if defined(DEBUG)
			clog << "Movie CLASS DEBUG: " << "user failed to enter valid input" << endl;
#endif
			cin.clear();
			cout << "Error: make sure you enter only a choice 1 through 8:  " << flush;
			cin >> choice;
			cout << "\n";
		}
		cin.clear();
		cin.ignore();
		cout << "\n";
#if defined(DEBUG)
		clog << "Movie CLASS DEBUG: " << "about to enter switch statement" << endl;
#endif
		switch (choice) {
			case 1:
				cout << "Current Title: " << movieTitle << "\n";
				cout << "NEW TITLE:  " << flush;
				getline(cin, inputTextBuffer);
				cout << "\n" << flush;

				while (cin.fail()) {
					cout << "An error has occurred" << "\n" << "\n";
					cout << "Current Title: " << movieTitle << "\n";
					cout << "NEW TITLE:  " << flush;
					getline(cin, inputTextBuffer);
					cout << "\n";
				}
				movieTitle->editText(inputTextBuffer);
				cin.clear();
				cin.ignore();
				cout << flush;
				break;

			case 2:
				OGLongData = movieLength;
				cout << "Current Length: " << OGLongData << "\n";
				cout << "NEW LENGTH:  " << flush;
				cin >> movieLength;
				cout << "\n";
				while (cin.fail() || movieLength <= 0) {
					if(cin.fail() == true) {
						cin.clear();
						cout << "An error has occurred" << "\n" << "\n";
					}
					cout << "be sure to enter only numbers greater than zero with no spaces" << "\n" << "\n";
					cout << "Current Length: " << OGLongData;
					cout << "NEW LENGTH:     " << flush;
					cin >> movieLength;
					cout << "\n";
				}
				cin.clear();
				cin.ignore();
				cout << flush;
				break;

			case 3:

				OGLongData = movieYear;
				cout << "Current Year: " << OGLongData << "\n";
				cout << "NEW YEAR:     " << flush;
				cin >> movieYear;
				while (cin.fail() || movieYear <= 0) {
					if(cin.fail() == true) {
						cin.clear();
						cout << "An error has occurred" << "\n" << "\n";
					}
					cin.clear();
					cout << "be sure to enter only numbers greater than zero with no spaces" << "\n" << "\n";
					cout << "Current Year: " << OGLongData << "\n";
					cout << "NEW YEAR:     " << flush;
					cin >> movieYear;
				}
				cin.clear();
				cin.ignore();
				cout << flush;
				break;

			case 4:
				cout << "Current Genre: " << movieGenre << "\n";
				cout << "NEW GENRE:     " << flush;
				getline(cin, inputTextBuffer);
				cout << "\n" << flush;
				while (cin.fail()) {
					cin.clear();
					cout << "An error has occurred" << "\n" << "\n";

					cout << "Current Genre: " << movieGenre << "\n";
					cout << "NEW GENRE:  " << flush;
					getline(cin, inputTextBuffer);
				}

				movieGenre->editText(inputTextBuffer);
				cin.clear();
				cin.ignore();
				cout << flush;
				break;

			case 5:
				cout << "Current Rating: " << movieRating << "\n";
				cout << "NEW RATING:     " << flush;
				getline(cin, inputTextBuffer);
				cout << "\n";
				while (cin.fail()) {
					cout << "An error has occurred" << "\n" << "\n";

					cout << "Current Rating: ";
					cout << movieRating << "\n";
					cout << "NEW Rating:     " << flush;
					getline(cin, inputTextBuffer);
					cout << "\n" << flush;
				}

				movieRating->editText(inputTextBuffer);
				cin.clear();
				cin.ignore();
				cout << flush;
				break;

			case 6:
				OGLongData = movieOscars;
				cout << "Current Oscars: " << OGLongData << "\n";
				cout << "NEW OSCARS:     " << flush;
				cin >> movieOscars;
				cout << "\n" << flush;
				while (cin.fail() || movieOscars <= 0) {
					if(cin.fail() == true) {
						cin.clear();
						cout << "An error has occurred" << "\n" << "\n";
					}
					cout << "be sure to enter only numbers greater than zero with no spaces" << "\n" << "\n";
					cout << "Current Oscars: " << movieYear << "\n";
					cout << "NEW OSCARS:     " << flush;
					cin >> movieOscars;
				}
				cin.clear();
				cin.ignore();
				cout << flush;
				break;

			case 7:

				OGDoubleData = movieNumStars;
				cout << "Current IMDB Rating: " << OGDoubleData << "\n";
				cout << "NEW IMDB RATING:     " << flush;
				cin >> movieOscars;
				cout << "\n" << flush;
				while (cin.fail() || movieNumStars < 0) {
					if(cin.fail() == true) {
						cout << "An error has occurred" << "\n" << flush;
					}
					cin.clear();
					cout << "be sure to enter only numbers greater than or equal to zero" << "\n" << "\n";
					cout << "Current IMDB Rating: " << OGDoubleData << "\n";
					cout << "NEW IMDB RATING:     " << flush;
					cin >> movieNumStars;
					cout << "\n";
				}
				cin.clear();
				cin.ignore();
				cout << flush;
				break;
		}
	} while (choice != 8);
}

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

void Movie::printMovieTitle () {
	cout << right << setw(30) << "Movie Title:  " << left << movieTitle << "\n";
}

void Movie::printMovieDetails () {
	cout << right << setw(30) << "Movie Title:  " << left << movieTitle << "\n";
	cout << right << setw(30) << "Length (minutes):  " << left << movieLength << "\n";
	cout << right << setw(30) << "Year Released:  " << left << movieYear << "\n";
	cout << right << setw(30) << "Genre:  " << left << movieGenre << "\n";
	cout << right << setw(30) << "Rating:  " << left << movieRating << "\n";
	cout << right << setw(30) << "Number of Oscars Won:  " << left << movieOscars << "\n";
	cout << right << setw(30) << "Number of Stars:  " << left << movieNumStars << "\n" << flush;
}

void Movie::printMovieDetailsToFile (ofstream &outFile) {
	outFile << movieTitle->getText() << "\n";
	outFile << movieLength << "\n";
	outFile << movieYear << "\n";
	outFile << movieGenre->getText() << "\n";
	outFile << movieRating->getText() << "\n";
	outFile << movieOscars << "\n";
	outFile << movieNumStars << "\n" << flush;
}

void Movie::printMovieDetailsToFileNoFlushing (ofstream &outFile) {
	outFile << movieTitle->getText() << "\n";
	outFile << movieLength << "\n";
	outFile << movieYear << "\n";
	outFile << movieGenre->getText() << "\n";
	outFile << movieRating->getText() << "\n";
	outFile << movieOscars << "\n";
	outFile << movieNumStars << "\n";
}
