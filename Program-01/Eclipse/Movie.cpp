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

/*
bool Movie::isOnlyNumaric (string input) {
	for (unsigned long i = 0; i < input.length(); i++) {
		if( ! (input[i] >= '0' && input[i] <= '9')) {
			return false;
		}
	}
	if(input[0] == '\n') {
		return false;
	}
	return true;
}

bool Movie::isOnlyNumaricFloat (string input) {
	long countOfDot = 0;
	for (unsigned long i = 0; i < input.length(); i++) {
		if( ! (input[i] >= '0' && input[i] <= '9')) {
			if(input[i] == '.') {
				++countOfDot;
			}
			else {
				return false;
			}
		}
	}
	if(input[0] == '\n' || countOfDot < 0 || countOfDot > 1) {
		return false;
	}

	return true;
}
*/

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
	movieRating = new Text(inputRating);
	movieOscars = inputOscars;
	movieNumStars = inputStars;
}

Movie::Movie (string inputTitle, long inputLength, long inputYear, string inputGenre, string inputRating, long inputOscars, double inputStars) {
	movieTitle = new Text(inputTitle);
	movieLength = inputLength;
	movieYear = inputYear;
	movieGenre = new Text(inputGenre);
	movieRating = new Text(inputRating);
	movieOscars = inputOscars;
	movieNumStars = inputStars;
}

Movie::~Movie () {
	delete movieTitle;
	delete movieGenre;
	delete movieRating;
}

void Movie::editMovieDetails () {
	long choice;
	long OGLongData;
	double OGDoubleData;
	string inputTextBuffer;
	cout << setw(0) << setfill(' ');
	do {
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
		do {
			if(cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "an error has occurred" << "\n";
			}
			else
				if(choice < 1 || choice > 8) {
					cout << "only enter a number between 1 and 8" << "\n";
				}
			cout << "CHOOSE 1-8:  " << flush;
			cin >> choice;
		} while (cin.fail() || choice < 1 || choice > 8);
		cin.ignore();

		switch (choice) {
			case 1:
				do {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "an error has occurred" << "\n";
					}
					cout << "Current Title: " << movieTitle->getText() << "\n";
					cout << "NEW TITLE:  " << flush;
					getline(cin, inputTextBuffer);
				} while (cin.fail());
				movieTitle->editText(inputTextBuffer);
				cin.clear();
				cout << flush;
				break;

			case 2:
				OGLongData = movieLength;
				do {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "an error has occurred" << "\n";
					}
					else {
						if(choice < 1) {
							cout << "only enter a number between above zero" << "\n";
						}
					}
					cout << "Current Length: " << OGLongData << "\n";
					cout << "NEW LENGTH:  " << flush;
					cin >> movieLength;
				} while (cin.fail() || movieLength < 1);
				cin.clear();
				cout << flush;
				break;

			case 3:
				OGLongData = movieYear;
				do {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "an error has occurred" << "\n";
					}
					cout << "Current Year: " << OGLongData << "\n";
					cout << "NEW YEAR:  " << flush;
					cin >> movieYear;
				} while (cin.fail());
				cin.clear();
				cout << flush;
				break;

			case 4:
				do {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "an error has occurred" << "\n";
					}
					cout << "Current Genre: " << movieGenre->getText() << "\n";
					cout << "NEW GENRE:  " << flush;
					getline(cin, inputTextBuffer);
				} while (cin.fail());
				movieGenre->editText(inputTextBuffer);
				cin.clear();
				cout << flush;
				break;

			case 5:
				do {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "an error has occurred" << "\n";
					}
					cout << "Current Rating: " << movieRating->getText() << "\n";
					cout << "NEW RATING:  " << flush;
					getline(cin, inputTextBuffer);
				} while (cin.fail());
				movieRating->editText(inputTextBuffer);
				cin.clear();
				cout << flush;
				break;

			case 6:
				OGLongData = movieOscars;
				do {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "an error has occurred" << "\n";
					}
					else {
						if(movieOscars < 0) {
							cout << "only enter a number equal to or above 0" << "\n";
						}
					}
					cout << "Current Oscar Count: " << OGLongData << "\n";
					cout << "NEW OSCAR COUNT:  " << flush;
					cin >> movieOscars;
				} while (cin.fail() || movieOscars < 0);
				cin.clear();
				cout << flush;
				break;

			case 7:
				OGDoubleData = movieNumStars;
				do {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "an error has occurred" << "\n";
					}
					else {
						if(movieOscars < 0) {
							cout << "only enter a number between 0 and 10, inclusive" << "\n";
						}
					}
					cout << "Current IMDB Rating: " << OGDoubleData << "\n";
					cout << "NEW IMDB RATING:  " << flush;
					cin >> movieNumStars;
				} while (cin.fail() || movieNumStars < 0 || movieNumStars > 10);
				cin.clear();
				cout << flush;
				break;
		}
	} while (choice != 8);
}

void Movie::setMovieFull (Text* inputTitle, long inputLength, long inputYear, Text* inputGenre, Text* inputRating, long inputOscars, double inputStars) {
	setMovieDetailTitle(inputTitle);
	setMovieDetailLength(inputLength);
	setMovieDetailReleaseYear(inputYear);
	setMovieDetailGenre(inputGenre);
	setMovieDetailRating(inputRating);
	setMovieDetailOscarCount(inputOscars);
	setMovieDetailIMBDRating(inputStars);

}
void Movie::setMovieDetailTitle (Text* inputTitle) {
	delete movieTitle;
	movieTitle = new Text(inputTitle->getText());
}
void Movie::setMovieDetailLength (long inputLength) {
	movieLength = inputLength;
}
void Movie::setMovieDetailReleaseYear (long inputYear) {
	movieYear = inputYear;
}
void Movie::setMovieDetailGenre (Text* inputGenre) {
	delete movieGenre;
	movieGenre = new Text(inputGenre->getText());
}
void Movie::setMovieDetailRating (Text* inputRating) {
	delete movieRating;
	movieRating = new Text(inputRating->getText());
}
void Movie::setMovieDetailOscarCount (long inputOscars) {
	movieOscars = inputOscars;
}
void Movie::setMovieDetailIMBDRating (double inputStars) {
	movieNumStars = inputStars;
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
	cout << right << setw(30) << "Movie Title:  " << left << movieTitle->getText() << setw(0) << "\n";
}

void Movie::printMovieDetails () {
	cout << right << setw(30) << "Movie Title:  " << left << movieTitle->getText() << "\n";
	cout << right << setw(30) << "Length (minutes):  " << left << movieLength << "\n";
	cout << right << setw(30) << "Year Released:  " << left << movieYear << "\n";
	cout << right << setw(30) << "Genre:  " << left << movieGenre->getText() << "\n";
	cout << right << setw(30) << "Rating:  " << left << movieRating->getText() << "\n";
	cout << right << setw(30) << "Number of Oscars Won:  " << left << movieOscars << "\n";
	cout << right << setw(30) << "Number of Stars:  " << left << movieNumStars << "\n" << setw(0) << flush;
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
