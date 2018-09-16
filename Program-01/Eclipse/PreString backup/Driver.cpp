/*
 Title:  Driver.cpp
 Author:  April Crockett
 Date:  11/7/2017
 Purpose:  To demonstrate the Movies, Movie, and Text structure code working
 by allowing the user to add, save, delete, and edit movies to/from a library.
 */
#define DEBUG TRUE
#include "Movies.h"
#include "Movie.h"
#include "Text.h"
#include <iostream>

using namespace std;

void bootlegClearScreen (ostream& stream = cout, unsigned int numLines = 60) {
	for (unsigned int i = 0; i < numLines; i++) {
		stream << "\n";
	}
	stream << flush;
}

int main () {
	long menuChoice;
	long maxMovies;
	string filename;

	cout << "\n\nWhat is the maximum number of movies you can have in your library?\n";
	cin >> maxMovies;
	while (maxMovies <= 0) {
		cout << "\n\nYou have to have at least one movie in your library.\n";
		cout << "What is the maximum number of movies you can have in your library.\n";
		cin >> maxMovies;
	}
	Movies movieLibrary(maxMovies);

	do {
		bootlegClearScreen(cout, 100);

		cout << "\n";
		cout << "What would you like to do?" << "\n";
		cout << "1.  Read movies from file." << "\n";
		cout << "2.  Save movies to a file." << "\n";
		cout << "3.  Add a movie." << "\n";
		cout << "4.  Delete a movie." << "\n";
		cout << "5.  Edit a movie." << "\n";
		cout << "6.  Print all movies." << "\n";
		cout << "7.  Delete ALL movies and end the program." << "\n";
		cout << "Enter an option 1-7:  " << flush;
		cin >> menuChoice;
		while (menuChoice < 1 || menuChoice > 7 || cin.fail()) {
			if(cin.fail()) {
				cin.ignore();
				cin.clear();
				cout << "an error has occurred, be sure to only enter a number 1-7" << "\n";
			}
			if(menuChoice < 1 || menuChoice > 7) {
				cout << "That is not a valid choice." << "\n";
			}
			cout << "CHOOSE 1-7:  ";
			cin >> menuChoice;
		}

		switch (menuChoice) {
			case 1:    // import movies from file
				cout << "\n";
				cout << "(example.txt)" << "\n";
				cout << "Enter the filename:  " << "\n" << flush;
				cin.ignore();
				getline(cin, filename);
				movieLibrary.importFromFile(filename);
				break;

			case 2:    //export movies
				cout << "\n\nWhat do you want to name the file? (example.txt):  ";
				cin.ignore();
				getline(cin, filename);
				movieLibrary.exportToFile(filename);
				break;

			case 3:    //add a movie
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

	cout << "\n\nGOODBYE!\n\n";
#if defined(DEBUG)
	clog << "Driver DEBUG: " << "end program" << endl;
#endif
	return 0;
}
