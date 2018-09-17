/*
 Title:  Driver.cpp
 Author:  April Crockett
 Date:  11/7/2017
 Purpose:  To demonstrate the Movies, Movie, and Text structure code working
 by allowing the user to add, save, delete, and edit movies to/from a library.
 */
#include "Movies.h"
#include "Movie.h"
#include "Text.h"
#include <iostream>

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
	if(input[0] == '\n'){
		return false;
	}
	return true;
}

int main () {
	long menuChoice;
	long maxMovies = 1;
	string filename;
	string inputBuffer;
	//cout << "\n\nWhat is the maximum number of movies you can have in your library?\n";
	//cin >> maxMovies;
	//while (maxMovies <= 0) {
//		cout << "\n\nYou have to have at least one movie in your library.\n";
//		cout << "What is the maximum number of movies you can have in your library.\n";
//		cin >> maxMovies;
//	}
	Movies movieLibrary(maxMovies);
	bool inputIsOnlyNumbers;
	bool inputIsGood;

	do {
		cout << "\n\nWhat would you like to do?\n";
		cout << "1.  Read movies from file.\n";
		cout << "2.  Save movies to a file.\n";
		cout << "3.  Add a movie.\n";
		cout << "4.  Delete a movie.\n";
		cout << "5.  Edit a movie.\n";
		cout << "6.  Print all movies.\n";
		cout << "7.  Delete ALL movies and end the program.\n";
		do {
			inputIsGood = true;
			cout << "CHOOSE 1-7:  " << flush;
			getline(cin, inputBuffer);

			inputIsOnlyNumbers = isOnlyNumaric(inputBuffer);

			if(cin.fail()){
				cout << "an unknown error has occurred" << "\n";
				cin.clear();
			}
			if(inputIsOnlyNumbers == false) {
				inputIsGood = false;
				cout << "error: only enter numbers" << "\n";
			}
			if(inputIsOnlyNumbers == true){
				menuChoice = stol(inputBuffer);
				if(menuChoice < 1 || menuChoice > 7){
					inputIsGood = false;
					cout << "error: only enter a number 1 to 7" << "\n";
				}
			}

		} while (!inputIsGood);


		switch (menuChoice) {
			case 1:
				cout << "\n";
				cout << "What is the name of the file? (example.txt):  " << flush;
				//cin.ignore();
				getline(cin, filename);
				cout << "\n";
				while (cin.fail()) {
					cout << "an error has occured, try again" << "\n";
					cout << "What is the name of the file? (example.txt):  " << flush;
				}
				cout << filename << endl;
				movieLibrary.importFromFile(filename);     //function is in Movies.cpp
				break;

			case 2:
				cout << "\n";
				cout << "What do you want to name the file? (example.txt):  ";
				cin >> filename;
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

			case 7:     //delete all movies
				break;

		}

	} while (menuChoice != 7);

	cout << "\n" << "shutting down" << "\n" << flush;
	return 0;
}
