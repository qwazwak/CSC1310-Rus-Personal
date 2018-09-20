/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Program 01 - Driver source
 *	Author(s):	Rus Hoffman
 *	Date:		September 4, 2018
 *	Purpose:		drive the Movies, Movie, and Text classes
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "Movies.h"
#include "Movie.h"
#include "Text.h"
#include <iostream>
#include <limits>

using namespace std;

void bootlegClearScreen (unsigned int numLinesToClear = 60) {
	cout << flush;
	for (unsigned int i = 0; i < numLinesToClear; i = i + 1) {
		cout << "\n";
	}
	cout << flush;
}

bool isOnlyNumaric (string input) {
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

int main () {
	long menuChoice;
	const long INITMAXMOVIE = 1;
	string filename;
	Movies movieLibrary(INITMAXMOVIE);

	do {
		cin.clear();
		cout << "\n" << "\n" << "\n";
		cout << "What would you like to do?" << "\n";
		cout << "1.  Read movies from file" << "\n";
		cout << "2.  Save movies to a file" << "\n";
		cout << "3.  Add a movie" << "\n";
		cout << "4.  Delete a movie" << "\n";
		cout << "5.  Edit a movie" << "\n";
		cout << "6.  Print all movies" << "\n";
		cout << "7.  Delete ALL movies and end the program" << "\n";

		cout << "CHOOSE 1-7:  " << flush;
		cin >> menuChoice;
		while (cin.fail() || menuChoice < 1 || menuChoice > 7) {
			if(cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "an error has occurred, try again" << "\n";
			}
			else {
				if(menuChoice < 1 || menuChoice > 7) {
					cout << "only enter a number between 1 and 7, inclusive" << "\n";
				}
			}
			cout << "CHOOSE 1-7:  " << flush;
			cin >> menuChoice;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n";


		switch (menuChoice) {
			case 1:
				cout << "\n" << "What is file named? (example.txt):  ";
				getline(cin, filename);
				while ( (cin.fail() || (filename[filename.length() - 2] == 't' && filename[filename.length() - 3] == 'x' && filename[filename.length() - 4] == 't' && filename[filename.length() - 5] == '.'))) {
					if(cin.fail()) {
						cout << "an error has occurred" << "\n";
					}
					else {
						if(filename[filename.length() - 2] == 't' && filename[filename.length() - 3] == 'x' && filename[filename.length() - 4] == 't' && filename[filename.length() - 5] == '.') {
							cout << "error: be sure the file name ends in .txt" << "\n";
						}
					}
					cout << "What is file named? (example.txt):  ";
					getline(cin, filename);
				}
				movieLibrary.importFromFile(filename);     //function is in Movies.cpp
				break;

			case 2:
				cout << "\n" << "What do you want to name the file? (example.txt):  ";
				getline(cin, filename);
				while ( (cin.fail() || (filename[filename.length() - 2] == 't' && filename[filename.length() - 3] == 'x' && filename[filename.length() - 4] == 't' && filename[filename.length() - 5] == '.'))) {
					if(cin.fail()) {
						cout << "an error has occurred" << "\n";
					}
					else {
						if(filename[filename.length() - 2] == 't' && filename[filename.length() - 3] == 'x' && filename[filename.length() - 4] == 't' && filename[filename.length() - 5] == '.') {
							cout << "error: be sure the file name ends in .txt" << "\n";
						}
					}
					cout << "What do you want to name the file? (example.txt):  ";
					getline(cin, filename);

				}
				movieLibrary.exportToFile(filename);     //function is in Movies.cpp
				break;

			case 3:     //add a movie
				movieLibrary.addMovieToArrayFromUser();
				break;

			case 4:     //remove a movie
				movieLibrary.removeMovieByUserChoice();
				break;

			case 5:     //edit a movie
				movieLibrary.editMovieInArray();
				break;

			case 6:     //print all movies
				movieLibrary.displayAllMoviesFullDetails();
				break;

			case 7:
				//exit menu loop and close program
				break;

		}

	} while (menuChoice != 7);

	cout << "\n" << "END PROGRAM" << "\n" << flush;
	return 0;
}
