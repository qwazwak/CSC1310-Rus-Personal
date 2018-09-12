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
 Movie** moviesArray;	//The main array of pointers - each pointer points to a single Movie
 size_t arraySize;		//Number of allocated 'movie' spots
 size_t numMovies;		//Number of stored movies
 //size_t maxMovies;		//Maximum storable movies
 */

/*
 Function name:	expandarray
 Parameters:		none (void)
 Returns: 		none (void)
 Purpose:  		Double the capacity of the moviesArray
 */
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

/*
 Function name:	removeMovieByID
 Parameters:		none (void)
 Returns: 		none (void)
 Purpose:  		remove one movie from the array and shift other movies as required
 */
void Movies::removeMovieByID () {

}

//public:
Movies::Movies () {
	numMovies = 0;
	arraySize = 1;
	moviesArray = new Movie*[1];
}

//Destructor
Movies::~Movies () {
	for (size_t i = 0; i < arraySize; i++) {
		delete moviesArray[i];
	}
	delete[] moviesArray;
}

/*
 Function names:	addMovieToArrayDirect
 Parameters:		a pointer to a movie to add
 Returns: 		none
 Purpose:  		This function should be called when the program/programmer needs to add a single movie to the movie library directly and quickly.
 */
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

/*
 Function names:	addMovieToArrayFromUser
 Parameters:		none
 Returns: 		none
 Purpose:  		This function should be called when the user wants to add a single movie to the movie library and inpout the movie details
 */
void Movies::addMovieToArrayFromUser () {
	string title;
	long length;
	long year;
	string genre;
	string rating;
	long numOscars;
	double numStars;

	//get movie data from the user
	cin.ignore();    //remove the \n from the keyboard buffer
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
		expandarray();    //increase size by 2
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

/*
 Function name:  destroyMovies
 Parameters:  	1) The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when you need to remove all the single
 movies in the movie library as well as the movie library.  This releases
 all the dynamically allocated space in memory.
 */
void Movies::removeMovieFromUser () {

}

/*
 Function name:  displayMoviesTitles
 Parameters:  	1) The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when the user wants to have all the movies
 in the library printed to the screen.
 */
void Movies::displayMoviesTitles () {

}

/*
 Function name:	displayMoviesFullDetails
 Parameters:		nothing (void)
 Returns:			nothing (void)
 Purpose:  		This function should be called when the user wants to have all the movies and all details in the library printed to the screen.
 */
void Movies::displayMoviesFullDetails () {

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
 Function name:  displayMovieTitles
 Parameters:  	1) The movies structure (which contains the movie library)
 Returns: 		none (void)
 Purpose:  		This function should be called when you want to print only the movie titles
 out of the movie library
 */
void Movies::displayMovieTitles () {

}

/*
 Function name:  importFromFile
 Parameters:  	A string or char array of the filename, with extention. Only supports pure text
 Returns: 		nothing (void)
 Purpose:  		This function should be called when the program/programmer wants to read movie data from a file and add the movies to the movie library.  The file must have data in the following order: title, length, year, genre, rating, num oscars won, star rating
 */
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

/*
 Function name:  exportToFile
 Parameters:  	A string or char array of the filename, with extention. Only supports pure text
 Returns: 		none (void)
 Purpose:  		This function should be called when the program/programmer wants to print all the movie data from the movie library to a file.  The data is printed in the following order (one piece of data per line): title, length, year, genre, rating, num oscars won, star rating
 */
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
