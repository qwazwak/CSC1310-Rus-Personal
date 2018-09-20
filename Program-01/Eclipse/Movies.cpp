/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Program 01 - Single Movie Encapsulation class
 *	Author(s):	Rus Hoffman
 *	Date:		September 4, 2018
 *	Purpose:		Practice working with classes which include member classes
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "Movies.h"
#include "Movie.h"
using namespace std;

void Movies::expandarray () {
#if defined(DEBUG)
	clog << "EXPANDING ARRAY" << endl;
#endif
	Movie** moviesBufferArray = new Movie*[maxMoviesHoldable * 2];
	for (long i = 0; i < numMovies; i++) {
		moviesBufferArray[i] = moviesArray[i];
	}
	delete[] moviesArray;
	moviesArray = moviesBufferArray;
	maxMoviesHoldable = maxMoviesHoldable * 2;
}

void Movies::removeMovieByID (long ID) {
	delete moviesArray[ID];
	if(ID != (numMovies - 1)) {
		for (long i = ID; i < numMovies; i++) {
			moviesArray[i] = moviesArray[i + 1];
		}
	}
	delete moviesArray[numMovies - 1];
	numMovies = numMovies - 1;
}

bool Movies::isOnlyNumaric (string input) {
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

bool Movies::isOnlyNumaricFloat (string input) {
	long countOfDot = 0;
	for (unsigned long i = 0; i < input.length(); i++) {
		if( ! (input[i] >= '0' && input[i] <= '9')) {
			if(input[i] == '.'){
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

Movies::Movies () {
	numMovies = 0;
	maxMoviesHoldable = 1;
	moviesArray = new Movie*[maxMoviesHoldable];
}

Movies::Movies (long maxSize) {
	numMovies = 0;
	maxMoviesHoldable = maxSize;
	moviesArray = new Movie*[maxSize];
}

Movies::~Movies () {
	for (long i = 0; i < numMovies; i++) {
		delete moviesArray[i];
	}
	delete[] moviesArray;
}

void Movies::addMovieToArrayDirect (Movie* inputMoviePointer) {
	if(maxMoviesHoldable <= numMovies) {
		this->expandarray();
	}
	moviesArray[numMovies] = inputMoviePointer;
	numMovies = numMovies + 1;
}

void Movies::addMovieToArrayFromUser () {
	cout << "FIX ME" << endl;
	//TODO: rewrite to match others
	bool inputIsGood;
	string inputBuffer;
	bool inputIsOnlyNumbers;

	string title = "error";
	long length = -99;
	long year = -99;
	string genre = "error";
	string rating = "error";
	long numOscars = -99;
	double numStars = -99;

	//get movie data from the user
	cout << "\n";
	cout << "MOVIE TITLE: " << flush;
	getline(cin, title);
	cout << "\n";

	do {
		inputIsGood = true;
		cout << "MOVIE LENGTH (in minutes): " << flush;
		getline(cin, inputBuffer);

		inputIsOnlyNumbers = isOnlyNumaric(inputBuffer);

		if(cin.fail()) {
			cout << "an unknown error has occurred" << "\n";
			cin.clear();
		}
		if(inputIsOnlyNumbers == false) {
			inputIsGood = false;
			cout << "error: only enter numbers" << "\n";
		}
		if(inputIsOnlyNumbers == true) {
			length = stol(inputBuffer);
			if(length < 1) {
				inputIsGood = false;
				cout << "error: only enter a number greater than zero" << "\n";
			}
		}

	} while ( !inputIsGood);
	cout << "\n";

	do {
		inputIsGood = true;
		cout << "MOVIE YEAR: " << flush;
		getline(cin, inputBuffer);

		inputIsOnlyNumbers = isOnlyNumaric(inputBuffer);

		if(cin.fail()) {
			cout << "an unknown error has occurred" << "\n";
			cin.clear();
		}
		if(inputIsOnlyNumbers == false) {
			inputIsGood = false;
			cout << "error: only enter numbers" << "\n";
		}
		if(inputIsOnlyNumbers == true) {
			year = stol(inputBuffer);
		}
	} while ( !inputIsGood);
	cout << "\n";
	cout << "MOVIE GENRE: " << flush;
	getline(cin, genre);
	cout << "\n";
	cout << "MOVIE RATING: " << flush;
	getline(cin, rating);
	cout << "\n";
	do {
		inputIsGood = true;
		cout << "NUMBER OF OSCARS WON: " << flush;
		getline(cin, inputBuffer);

		inputIsOnlyNumbers = isOnlyNumaric(inputBuffer);

		if(cin.fail()) {
			cout << "an unknown error has occurred" << "\n";
			cin.clear();
		}
		if(inputIsOnlyNumbers == false) {
			inputIsGood = false;
			cout << "error: only enter numbers" << "\n";
		}
		if(inputIsOnlyNumbers == true) {
			numOscars = stol(inputBuffer);
			if(length < 1) {
				inputIsGood = false;
				cout << "error: only enter a number greater than zero" << "\n";
			}
		}

	} while ( !inputIsGood);
	cout << "\n";
	do {
			inputIsGood = true;
			cout << "STAR RATING (out of 10): " << flush;
			getline(cin, inputBuffer);

			inputIsOnlyNumbers = isOnlyNumaricFloat(inputBuffer);

			if(cin.fail()) {
				cout << "an unknown error has occurred" << "\n";
				cin.clear();
			}
			if(inputIsOnlyNumbers == false) {
				inputIsGood = false;
				cout << "error: only enter numbers" << "\n";
			}
			if(inputIsOnlyNumbers == true) {
				numStars = stol(inputBuffer);
				if(numStars < 0 || numStars> 10) {
					inputIsGood = false;
					cout << "error: only enter a number between 0 and 10, inclusive" << "\n";
				}
			}

		} while ( !inputIsGood);
	cout << "\n" << flush;
	addMovieToArrayDirect(new Movie(title, length, year, genre, rating, numOscars, numStars));
}
/*
 Function name:	editMovieInArray
 Parameters:		none
 Returns:			none
 Purpose:			This function should be called when you need to edit a movie in the array
 */
void Movies::editMovieInArray () {
	long numberPicked;
	displayAllMoviesOnlyTitle();
	cout << "\n";
	cout << "Enter the number of the movie you wish to edit: " << flush;
	cin >> numberPicked;
	cout << "\n";
	while (numberPicked < 1 || numberPicked > numMovies || cin.fail()) {
		if(cin.fail()) {
			cout << "an error has occurred" << "\n";
		}
		if(numberPicked < 1 || numberPicked > numMovies) {
			cout << "invalid input, only enter a number 1-numMovies" << "\n";
		}
		cout << "Enter the number of the movie you wish to edit: " << flush;
		cin >> numberPicked;
	}
	moviesArray[numberPicked - 1]->editMovieDetails();
}

void Movies::removeMovieByUserChoice () {
	long numberPicked;
	cout << "Current list of movies:" << "\n";
	displayAllMoviesOnlyTitle();
	cout << "\n";
	do {
		cout << "Enter the number of the movie to remove: ";
		cin >> numberPicked;
		if(cin.fail()) {
			cout << "an error has occurred" << "\n";
		}
		if(numberPicked < 1 || numberPicked > numMovies) {
			cout << "invalid input, only enter a number 1-" << numMovies << "\n";
		}
	} while (numberPicked < 1 || numberPicked > numMovies || cin.fail());
	removeMovieByID(numberPicked - 1);
}

void Movies::displayAllMoviesOnlyTitle () {
	cout << "\n";
	for (long i = 0; i < numMovies; i++) {
		cout << setw(30) << right << "Movie Number: " << left << i + 1 << setw(0) << "\n";
		moviesArray[i]->printMovieTitle();
		cout << "\n";
	}
	cout << setw(0) << flush;
}

void Movies::displayAllMoviesFullDetails () {
	cout << setfill(' ') << "\n";
	for (long i = 0; i < numMovies; i++) {
		cout << left << setw(0) << "                  ------" << "Number " << right << setw(5) << i + 1 << setw(0) << left << "------                  " << "\n";
		moviesArray[i]->printMovieDetails();
		cout << left << setw(0) << "                  ------" << "Number " << right << setw(5) << i + 1 << setw(0) << left << "------                  " << "\n";
		cout << "\n" << "\n";
	}
	cout << setw(0) << flush;
}

void Movies::importFromFile (char* filename) {
	string tempString(filename);
	this->importFromFile(filename);
}

void Movies::importFromFile (string filename) {
#if defined(DEBUG)
	clog << "Movies CLASS DEBUG: " << "starting import" << endl;
#endif
	ifstream ifs;
	string inputBuffer;
	string movieTitle;
	long movieLength;
	long movieYear;
	string movieGenre;
	string movieRating;
	long movieOscars;
	double movieNumStars;

	ifs.open(filename);

	while (true) {
		getline(ifs, movieTitle);

		getline(ifs, inputBuffer);		//ifs >> movieLength;
		movieLength = stol(inputBuffer);

		getline(ifs, inputBuffer);		//ifs >> movieYear;
		movieYear = stol(inputBuffer);

		//ifs.ignore();
		getline(ifs, movieGenre);

		getline(ifs, movieRating);

		getline(ifs, inputBuffer);		//ifs >> movieOscars;
		movieOscars = stol(inputBuffer);

		getline(ifs, inputBuffer);		//ifs >> movieNumStars;
		movieNumStars = stol(inputBuffer);
		//ifs.ignore();

#if defined(MOVIES_LOG_ON_IMPORT)
		cout << movieTitle << "\n";
		cout << movieLength << "\n";
		cout << movieYear << "\n";
		cout << movieGenre << "\n";
		cout << movieRating << "\n";
		cout << movieOscars << "\n";
		cout << movieNumStars << "\n" << flush;
#endif
		if(ifs.eof()) {
			break;
		}
		this->addMovieToArrayDirect(new Movie(movieTitle, movieLength, movieYear, movieGenre, movieRating, movieOscars, movieNumStars));
	}
	ifs.close();
#if defined(DEBUG)
	clog << "Movies CLASS DEBUG: " << "done with import" << endl;
#endif
}

void Movies::exportToFile (char* filename) {
	string temp(filename);
	this->exportToFile(temp);
}

void Movies::exportToFile (string filename) {
	ofstream outputStream;
	outputStream.open(filename);
	for (long i = 0; i < numMovies; i++) {
		moviesArray[i]->printMovieDetailsToFile(outputStream);
	}
	outputStream << flush;
	outputStream.close();
}
