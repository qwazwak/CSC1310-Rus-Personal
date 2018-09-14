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
	clog << "starting expandarray" << endl;
#endif
	Movie** moviesBufferArray = new Movie*[maxMoviesHoldable * 2];
	for (long i = 0; i < numMovies; i++) {
		moviesBufferArray[i] = moviesArray[i];
	}
	delete[] moviesArray;
	moviesArray = moviesBufferArray;
	maxMoviesHoldable = maxMoviesHoldable * 2;
#if defined(DEBUG)
	clog << "end array expanding" << endl;
#endif
}

void Movies::removeMovieByID (long ID) {
	delete moviesArray[ID];
	numMovies = numMovies - 1;
	if(ID != (numMovies - 1)) {
		for (long i = ID; i < numMovies; i++) {
			moviesArray[i] = moviesArray[i + 1];
		}
	}
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
	for (long i = 0; i < maxMoviesHoldable; i++) {
		delete moviesArray[i];
	}
	delete[] moviesArray;
}

void Movies::addMovieToArrayDirect (Movie* inputMoviePointer) {
	if(maxMoviesHoldable == numMovies) {
		expandarray();
	}
	moviesArray[numMovies] = inputMoviePointer;
	numMovies = numMovies + 1;
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
	if(numMovies >= maxMoviesHoldable) {
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

void Movies::removeMovieByUserChoice () {

	cout << "Current list of movies:" << "\n";
	displayAllMoviesOnlyTitle();
	cout << "\n" << "\n";
	cout << "Enter ";
}

void Movies::displayAllMoviesOnlyTitle () {
	cout << "\n";
	for (long i = 0; i < numMovies; i++) {
		cout << setw(30) << right << "Movie Number: " << left << i << setw(0);
		moviesArray[i]->printMovieTitle();
	}
	cout << setw(0) << flush;
}

void Movies::displayAllMoviesFullDetails () {
	cout << "\n";
	for (long i = 0; i < numMovies; i++) {
		moviesArray[i]->printMovieDetails();
	}
	cout << setw(0) << flush;
}

void Movies::importFromFile (string filename) {
#if defined(DEBUG)
	clog << "Movies CLASS DEBUG: " << "starting import" << endl;
#endif
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
		ifs.ignore(256, '\n');
		getline(ifs, movieTitle);
		ifs >> movieLength;
		ifs >> movieYear;
		ifs.ignore(256, '\n');
		getline(ifs, movieGenre);
		getline(ifs, movieRating);
		ifs >> movieGenre;
		ifs >> movieOscars;
		ifs >> movieNumStars;

		if(ifs.eof()) {
			break;
		}
		addMovieToArrayDirect(new Movie(movieTitle, movieLength, movieYear, movieGenre, movieRating, movieOscars, movieNumStars));
	}
	ifs.close();
#if defined(DEBUG)
	clog << "Movies CLASS DEBUG: " << "done with import" << endl;
#endif
}

void Movies::importFromFile (char* filename) {
	string tempString(filename);
	importFromFile(filename);
}

void Movies::exportToFile (string filename) {
	exportToFile(filename.c_str());
}

void Movies::exportToFile (char *filename) {
	ofstream outputStream;
	outputStream.open(filename);
	for (long i = 0; i < numMovies; i++) {
		moviesArray[i]->printMovieDetailsToFile(outputStream);
		outputStream << flush;
	}
	outputStream.close();
}
