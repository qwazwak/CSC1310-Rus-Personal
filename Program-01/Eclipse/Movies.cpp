/*
 Title:  Movies.cpp
 Author:  April R Crockett
 Date:  11/7/2017
 Purpose:  Be able to create, manage, print, save & delete a movie library
 */
#include "Movies.h"
#include "Movie.h"
using namespace std;

void Movies::expandarray () {
#if defined(DEBUG)
	clog << "starting expandarray" << endl;
#endif
	Movie** moviesBufferArray = new Movie*[arraySize * 2];
	for (size_t i = 0; i < arraySize; i++) {
		moviesBufferArray[i] = moviesArray[i];
	}
	delete[] moviesArray;
	moviesArray = moviesBufferArray;
	arraySize = arraySize * 2;
#if defined(DEBUG)
	clog << "end array expanding" << endl;
#endif
}

void Movies::removeMovieByID (long ID) {

}

Movies::Movies () {
	numMovies = 0;
	arraySize = 1;
	moviesArray = new Movie*[1];
}

Movies::~Movies () {
	for (size_t i = 0; i < arraySize; i++) {
		delete moviesArray[i];
	}
	delete[] moviesArray;
}

void Movies::addMovieToArrayDirect (Movie* inputMoviePointer) {
	if(numMovies >= arraySize) {
		Movie** moviesBufferArray = new Movie*[arraySize * 2];
		for (size_t i = 0; i < arraySize; i++) {
			moviesBufferArray[i] = moviesArray[i];
		}
		delete[] moviesArray;
		moviesArray = moviesBufferArray;
		arraySize = arraySize * 2;
	}
	moviesArray[numMovies] = inputMoviePointer;
	numMovies++;
}

void Movies::addMovieToArrayFromUser () {
	string title;
	long length;
	long year;
	string genre;
	string rating;
	long numOscars;
	double numStars;

	//get movie data from the user
	cin.ignore();     //remove the \n from the keyboard buffer
	cout << "\n" << "\n";
	cout << "MOVIE TITLE: " << flush;
	getline(cin, title);
	cout << "\n" << "MOVIE LENGTH (in minutes): " << flush;
	cin >> length;
	cout << "\n" << "MOVIE YEAR: " << flush;
	cin >> year;
	cin.ignore();
	cout << "\n" << "MOVIE GENRE: " << flush;
	getline(cin, genre);
	cout << "\n" << "MOVIE RATING: " << flush;
	getline(cin, rating);
	cout << "\n" << "NUMBER OF OSCARS WON: " << flush;
	cin >> numOscars;
	cout << "\n" << "STAR RATING (out of 10): " << flush;
	cin >> numStars;

	//create the movie
	Movie* oneMovie = new Movie(title, length, year, genre, rating, numOscars, numStars);

	//add the movie to the library
	if(numMovies >= arraySize) {
		expandarray();     //increase size by 2
	}
	moviesArray[numMovies] = oneMovie;

	numMovies++;
}

/*
 Function name:	editMovieInArray
 Parameters:		none
 Returns:			none
 Purpose:			This function should be called when you need to edit a movie in the array
 */
void Movies::editMovieInArray () {

}

void Movies::removeMovieFromUser () {
	cout << "Current list of movies:" << "\n";
	displayAllMoviesOnlyTitle();
	cout << "\n" << "\n";
	cout << "Enter ";

}



void Movies::displayAllMoviesOnlyTitle () {
	cout << setw(0);
	for (unsigned long i = 0; i < numMovies; i++) {
		moviesArray[i]->printMovieTitle();
	}
	cout << setw(0) << flush;
}

void Movies::displayAllMoviesFullDetails () {
	cout << "\n";
	for (unsigned long i = 0; i < numMovies; i++) {
		moviesArray[i]->printMovieDetails();
	}
	cout << setw(0) << flush;
}

void Movies::removeMovieByUserChoice () {

}

void Movies::importFromFile (string filename) {
	importFromFile(filename.c_str());
}

void Movies::importFromFile (char* filename) {
	ifstream ifs;
	string movieTitle;
	long movieLength;
	long movieYear;
	string movieGenre;
	string movieRating;
	long movieOscars;
	double movieNumStars;

	ifs.open(filename);

	while (true) {
		ifs >> movieTitle;
		ifs >> movieLength;
		ifs >> movieYear;
		ifs >> movieGenre;
		ifs >> movieRating;
		ifs >> movieOscars;
		ifs >> movieNumStars;

		if(ifs.eof()) {
			break;
		}
		addMovieToArrayDirect(new Movie(movieTitle, movieLength, movieYear, movieGenre, movieRating, movieOscars, movieNumStars));
	}
	ifs.close();
}

void Movies::exportToFile (string filename) {
	exportToFile(filename.c_str());
}

void Movies::exportToFile (char *filename) {
	ofstream outputStream;
	outputStream.open(filename);
	for (size_t i = 0; i < numMovies; i++) {
		moviesArray[i]->printMovieDetailsToFile(outputStream);
	}
	outputStream.close();
}
