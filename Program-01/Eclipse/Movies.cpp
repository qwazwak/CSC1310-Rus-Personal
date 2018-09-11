/*
 Title:  Movies.cpp
 Author:  April R Crockett
 Date:  11/7/2017
 Purpose:  Be able to create, manage, print, save & delete a movie library
 */
#include "Movies.h"
#include "Movie.h"

using namespace std;

/*
 //Variables:
 Movie** moviesArray;    //an array of pointers - each pointer points to a single Movie
 size_t arraySize;
 //size_t maxMovies;    //maximum number of elements in the array
 size_t numMovies;    //current number of movies in the array
 bool anyMoviesInLibrary;
 */

Movies::Movies () {
	anyMoviesInLibrary = false;
	numMovies = 0;
	arraySize = 1;
	moviesArray = new Movies*[1];
}

//Overloading Constructor for quicker setup

//Destructor
Movies::~Movies () {
	for (size_t i = 0; i < arraySize; i++) {
		delete moviesArray[i];
	}
	delete[] moviesArray;
}

/*
 Function name:  resizeMovieArray
 Parameters:  	The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function is called by addMovieToArray when the array size is not big enough
 to hold a new movie that needs to be added.  The function makes the array twice
 as big as it currently is and then moves all the movie pointers to this new array.
 */
void Movies::expandarray () {
	Movie** moviesBufferArray = new Movies*[arraySize * 2];
	for (size_t i = 0; i < arraySize; i++) {
		moviesBufferArray[i] = moviesArray[i];
	}
	delete[] moviesArray;
	moviesArray = moviesBufferArray;
	arraySize = arraySize * 2;
}

/*
 Function name:  addMovieToArray
 Parameters:  	1) The movies structure (which contains the movie library)
 Returns: 		none
 Purpose:  		This function should be called when you need to add a single movie to the
 movie library.
 */
void Movies::addMovieToArrayDirect (Movie* inputMoviePointer) {
	if(numMovies >= arraySize) {
		Movie** moviesBufferArray = new Movies*[arraySize * 2];
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
	cin.ignore();  //remove the \n from the keyboard buffer
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
	Movie* oneMovie = createMovie(title, length, year, genre, rating, numOscars, numStars);

	//add the movie to the library
	if(myMovies->numMovies == myMovies->maxMovies)
		resizeMovieArray(myMovies);	//increase size by 2

	myMovies->moviesArray[myMovies->numMovies] = oneMovie;

	numMovies++;
}

/*
 Function name:  editMovieInArray
 Parameters:  	The movies structure (which contains the movie library)
 Returns: 		none
 Purpose:  		This function should be called when you need to edit a movie in the array
 */
void Movies::editMovieInArray () {

}

/*
 Function name:  destroyMovies
 Parameters:  	1) The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when you need to remove all the single
 movies in the movie library as well as the movie library.  This releases
 all the dynamically allocated space in memory.
 */
void Movies::removeMovie () {

}

/*
 Function name:  displayMovies
 Parameters:  	1) The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when the user wants to have all the movies
 in the library printed to the screen.
 */
void Movies::displayMoviesAll () {

}

/*
 Function name:  displayMovieTitles
 Parameters:  	1) The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when you want to print only the movie titles
 out of the movie library
 */
void Movies::displayMovieTitles () {

}

/*
 Function name:  readMoviesFromFile
 Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the filename
 2) The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when the user wants to read movie data from a file
 and add the movies to the movie library.  The file must have data in the following order:
 title, length, year, genre, rating, num oscars won, star rating
 */
void Movies::readMoviesFromFile (string filename) {
	readMoviesFromFile(filename.c_str());
}
void Movies::readMoviesFromFile (char* filename) {
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

/*
 Function name:  removeMovieFromArray
 Parameters:  	The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when the user wants to remove one single movie
 from the movie library.  The function will list all the movie names and allow
 the user to select the movie that they wish to remove. Then this function removes the movie.
 */
void Movies::removeMovieByUserChoice () {

}

/*
 Function name:  saveToFile
 Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the filename
 2) The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when the user wants to print all the movie data
 from the movie library to a file.  The data is printed in the following order (one piece
 of data per line):
 title, length, year, genre, rating, num oscars won, star rating
 */
void Movies::saveToFile (string filename) {
	saveToFile(filename.c_str());
}
void Movies::saveToFile (char *filename) {
	ofstream outputStream;
	outputStream.open(filename);
	for (size_t i = 0; i < numMovies; i++) {
		moviesArray[i]->printMovieDetailsToFile(outputStream);
	}
	outputStream.close();
}

