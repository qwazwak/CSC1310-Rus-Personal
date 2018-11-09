/*
 * Title:  Driver.cpp
 * Author:  April Crockett, modified by Rus Hoffman
 * Date:  11/7/2017
 * Purpose:  To demonstrate the Movies, Movie, and Text structure code working
 * by allowing the user to add, save, delete, and edit movies to/from a library.
 */

#define RUN_FAST
#define SHOW_SORT

#include "Movies.h"
#include "Movie.h"
#include "Text.h"
#include "timer.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	long menuChoice;
	string filename;
	
	Movies* movieLibrary = new Movies();

	do {
		cout << "\n\nWhat would you like to do?\n";
		cout << "1.  Read movies from file.\n";
		cout << "2.  Save movies to a file.\n";
		cout << "3.  Add a movie.\n";
		cout << "4.  Delete a movie.\n";
		cout << "5.  Edit a movie.\n";
		cout << "6.  Print all movies.\n";
		cout << "7.  Algorithm Analysis.\n";
		cout << "8.  Delete ALL movies and end the program.\n";
		cout << "CHOOSE 1-8:  ";
		cin >> menuChoice;
		while (menuChoice < 1 || menuChoice > 8 || cin.fail()) {
			if(cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "An error has occured, be sure to enter only numbers" << "\n";
			}
			else {
				cout << "That is not a valid choice" << "\n";
			}
			cout << "CHOOSE 1-8:  " << flush;
			cin >> menuChoice;
		}
		
		switch (menuChoice) {
			case 1:
				cin.ignore();
				cout << "\n\nWhat is the name of the file? (example.txt):  ";
				getline(cin, filename);
				while (filename.length() <= 5 || cin.fail()) {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "An error has occured, try again" << "\n";
					}
					else {
						cout << "That is not a valid choice" << "\n";
					}
					cout << "\n\nWhat is the name of the file? (example.txt):  ";
					getline(cin, filename);
				}
				movieLibrary->readMoviesFromFile(filename.c_str());
				break;

			case 2:
				cin.ignore();
				cout << "\n\nWhat do you want to name the file? (example.txt):  ";
				getline(cin, filename);
				while (cin.fail() || !((filename.at(filename.length() - 1) != 't' || filename.at(filename.length() - 2) != 'x' || filename.at(filename.length() - 3) != 't' || filename.at(filename.length() - 4) != '.') ? false : true)) {
					if(cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "An error has occured, try again" << "\n";
					}
					else {
						cout << "be sure to include the file extention '.txt'" << "\n";
					}
					cout << "\n\nWhat do you want to name the file? (example.txt):  ";
					getline(cin, filename);
				}
				movieLibrary->saveToFile(filename);
				break;

			case 3:     //add a movie
				movieLibrary->addMovieToList();
				break;

			case 4:   //delete a movie if there is more than one movie in the library.
				movieLibrary->removeMovieFromList();
				break;

			case 5:     //edit a movie
				movieLibrary->editMovieInList();
				break;

			case 6:     //print all movies
				movieLibrary->displayMovies();
				break;
			case 7:	//Benchmark the algos
				movieLibrary->algorithmAnalysis();
				break;

			case 8:     //delete all movies
				delete movieLibrary;
				break;
		}
		
	}while (menuChoice != 8);

	cout << "\n\nGOODBYE!\n\n" << flush;
	return 0;
}
