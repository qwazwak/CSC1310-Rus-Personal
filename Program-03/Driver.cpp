//DONE: create function - linear search
//TODO: create function - Binary Search
//TODO: create function - Bubble Sort
//TODO: create function - Insertion Sort
//TODO: create function - Insertion Sort Descending
//TODO: create function - Selection Sort
//TODO: create function - Merge Sort
//TODO: create function - Quick Sort
//TODO: Create a function called algorithmAnalysis that will use a timer to time how long it takes to run the algorithm on a linked list of movies and print out the times.
//TODO: add algo anal menu option 2nd to last
//DONE: Create Linked list class function Swap
//DONE: Create Linked list class function setnode value

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

void ding(int, int);

#if defined(_WIN32)
#include <windows.h>
#if defined(CUSTOM_TONE)
void ding(int htz = 500, int millisLong = 200) {
	Beep(htz, millisLong);
}
#else
void ding(int, int) {
	char command[6] = "echo";
	command[4] = 07;
	system(command);
}
#endif
#elif defined(__unix__)
void ding(int, int) {
	system("echo -e \"\007\" >/dev/tty10");
}
#else
void ding(int, int) {
	cout << "\a" << flush;
}
#endif

bool confirmDOTtxt(string &input) {
	return (input.at(input.length() - 1) != 't' || input.at(input.length() - 2) != 'x' || input.at(input.length() - 3) != 't' || input.at(input.length() - 4) != '.') ? false : true;
}

int main(int argc, char* argv[]) {
	int menuChoice;
	//int movieChoice;
	//int maxMovies;
	string filename;
	
	Movies* movieLibrary = new Movies();
	if(argc > 1){
		for(long i = 0; i < argc; i++){
			if(strcmp(argv[i], "loadFile") == 0){
				movieLibrary->readMoviesFromFile(argv[i+1]);
			}
		}
	}
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
				cout << "\n" << "\n" << "What is the name of the file? (example.txt):  ";
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
					cout << "\n" << "\n" << "What is the name of the file? (example.txt):  ";
					getline(cin, filename);
				}
				clog << "GOT FILENAME" << endl;
				movieLibrary->readMoviesFromFile(filename.c_str());
				clog << "GOT MOVIES" << endl;
				break;

			case 2:
				cout << "\n\nWhat do you want to name the file? (example.txt):  ";
				cin >> filename;
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
			case 7:
				//cerr << "add me you fuck" << endl;
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
