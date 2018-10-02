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
#include <limits>
using namespace std;

void Movies::expandarray () {
#if defined(DEBUG_LOGGING)
	clog << "EXPANDING ARRAY from size: " << maxMoviesHoldable << endl;
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
	string title = "error";
	long length = -99;
	long year = -99;
	string genre = "error";
	string rating = "error";
	long numOscars = -99;
	double numStars = -99;
	cout << "\n";

//Movie title block - getline - start
	cout << "MOVIE TITLE:  ";
	getline(cin, title);
	while (cin.fail() || title.empty()) {
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "an error has occurred" << "\n";
		}
		else {
			if(title.empty()) {
				cout << "do not leave title empty" << "\n";
			}
		}
		cout << "What do you want to name the file? (example.txt):  ";
		getline(cin, title);

	}
	cout << "\n";
//Movie title block - getline - end
//Movie length block - cin - start
	cout << "LENGTH (MINUTES):  ";
	cin >> length;
	while (cin.fail() || length < 1) {
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "an error has occurred" << "\n";
			cout << "only enter numbers with no spaces" << "\n";
		}
		else {
			if(length < 1) {
				cout << "only enter a number greater than zero" << "\n";
			}
		}
		cout << "LENGTH (MINUTES):  ";
		cin >> length;
	}
	cout << "\n";
//Movie length block - cin - end
//Movie year block - cin - start
	cout << "RELEASE YEAR:  ";
	cin >> year;
	while (cin.fail()) {
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "an error has occurred" << "\n";
			cout << "only enter numbers with no spaces" << "\n";
		}
		cout << "RELEASE YEAR:  ";
		cin >> year;
	}
	cout << "\n";
//Movie year block - cin - end
//Movie genre block - getline - start
	cout << "GRENRE(S):  ";
	getline(cin, genre);
	while (cin.fail() || genre.empty()) {
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "an error has occurred" << "\n";
		}
		else {
			if(genre.empty()) {
				cout << "do not leave genre(s) empty" << "\n";
			}
		}
		cout << "GRENRE(S):  ";
		getline(cin, genre);

	}
	cout << "\n";
//Movie genre block - getline - end
//Movie age rating block - getline - start
	cout << "MOVIE RATING (AGE):  ";
	getline(cin, rating);
	while (cin.fail() || rating.empty()) {
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "an error has occurred" << "\n";
		}
		else {
			if(genre.empty()) {
				cout << "do not leave rating empty" << "\n";
			}
		}
		cout << "MOVIE RATING (AGE):  ";
		getline(cin, rating);

	}
	cout << "\n";
//Movie age rating block - getline - end
//Movie oscars block - cin - start
	cout << "NUMBER OF OSCARS WON:  ";
	cin >> numOscars;
	while (cin.fail() || numOscars < 0) {
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "an error has occurred" << "\n";
			cout << "only enter numbers with no spaces" << "\n";
		}
		else {
			if(numOscars < 0) {
				cout << "only enter a number greater than or equal to zero" << "\n";
			}
		}
		cout << "NUMBER OF OSCARS WON:  ";
		cin >> numOscars;
	}
	cout << "\n";
//Movie oscars block - cin - end
//Movie IMDB block - cin - start
	cout << "IMDB STAR COUNT:  ";
	cin >> numStars;
	while (cin.fail() || numStars < 0 || numStars > 10) {
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "an error has occurred" << "\n";
			cout << "only enter numbers with no spaces" << "\n";
		}
		else {
			if(numStars < 0 || numStars > 10) {
				cout << "only enter a number between zero and ten inclusive" << "\n";
			}
		}
		cout << "IMDB STAR COUNT:  ";
		cin >> numStars;
	}
	cout << "\n";
//Movie IMDB block - cin - end
	cout << "\n" << flush;
	addMovieToArrayDirect(new Movie(title, length, year, genre, rating, numOscars, numStars));
}

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
			cout << "invalid input, only enter a number between 1  and " << numMovies << "inclusive" << "\n";
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
		moviesArray[i]->printMovieDetailsNoFlush();
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
#if defined(DEBUG_LOGGING)
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
#if defined(DEBUG_LOGGING)
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
