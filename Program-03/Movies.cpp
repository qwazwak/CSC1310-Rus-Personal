/*
 *	Title:  Movies.cpp
 *	Author:  April R Crockett, modified by Rus Hoffman
 *	Date:  11/7/2017
 *	Purpose:  Be able to create, manage, print, save & delete a movie library
 */
#include "Movies.h"
#include "Movie.h"
#include "LinkedList.h"
#include <cstring>
#include <cmath>
time_t getTime();
double totalTime(time_t start, time_t end);
void Movies::algorithmAnalysis() {
#if defined(DEBUG)
	clog << "" << endl;
#endif
#if defined(DEBUG)
	clog << "starting benchmark" << endl;
#endif
	time_t benchmarkStartBuffer;
	double benchmarkDelta_;

}

size_t Movies::search_LinearSearch(Text key) {
	string compareBuffer;
	for (size_t i = 0; i < movieList->getLength(); i++) {
		compareBuffer = string(key.getText());
		if(compareBuffer.compare(movieList->getNodeValue(i)->getMovieTitle()->getText()) == 0) {
			return i;
		}
	}
	return -1;
}
size_t Movies::search_BinarySearch(Text key) {
	return search_BinarySearchWorker(key, 0, this->movieList->getLength() - 1);
}

size_t Movies::search_BinarySearchWorker(Text &key, size_t first, size_t last) {
	if(last == first) {
		return first;
	}
	size_t midpoint = static_cast<size_t>(floor(static_cast<double>(first + last) / 2.0));
	string stringKey(key.getText());
	string stringMidpoint(movieList->getNodeValue(midpoint)->getMovieTitle()->getText());
	if(stringKey.compare(stringMidpoint) > 0) {
		return this->search_BinarySearchWorker(key, midpoint, last);
	}
	else if(stringKey.compare(stringMidpoint) < 0) {
		return this->search_BinarySearchWorker(key, first, midpoint);
	}
	cerr << "FUCK" << endl;
	return NULL;
}

void Movies::sort_BubbleSort() {
	for (size_t maxElement = movieList->getLength() - 1; maxElement > 0; maxElement--) {
		for (size_t i = 0; i < maxElement; i++) {
			//swap the two adjacent elements if the one on the left is greater than the one on the right
			if(movieList->getNodeValue(i)->getMovieTitle() > movieList->getNodeValue(i + 1)->getMovieTitle()) {
				movieList->swapNodes(i, i + 1);
			}
		}
	}
}
void Movies::sort_InsertionSort() {
	size_t limit = movieList->getLength();
	string compareBuffer;
	for (size_t unsortedIndexStart = 1; unsortedIndexStart < limit; unsortedIndexStart++) {
		compareBuffer = string(movieList->getNodeValue(unsortedIndexStart)->getMovieTitle()->getText());

		for (size_t unsortedCompareToThisPoint = unsortedIndexStart - 1;

		unsortedCompareToThisPoint < limit && compareBuffer.compare(string(movieList->getNodeValue(unsortedCompareToThisPoint)->getMovieTitle()->getText())) < 0;

		unsortedCompareToThisPoint++) {
			if(movieList->getNodeValue(unsortedIndexStart)->getMovieTitle() < movieList->getNodeValue(unsortedCompareToThisPoint)->getMovieTitle()) {
				movieList->swapNodes(unsortedIndexStart, unsortedCompareToThisPoint);
			}
			else {
				break;
			}
		}
	}

}
void Movies::sort_InsertionSortDescending() {
	this->sort_InsertionSort();
	size_t limit = movieList->getLength();
	for (size_t i = 0; i < static_cast<size_t>(floor(static_cast<double>(limit) / 2.0)); i++) {
		this->movieList->swapNodes(i, limit - i);
	}
}
void Movies::sort_SelectionSort() {
	size_t currentLowestIndex = 0;
	size_t limit = movieList->getLength();
	for (size_t i = 0; i < limit; i++) {
		for (size_t comparingPoint = i; comparingPoint < limit; comparingPoint++) {
			if(movieList->getNodeValue(comparingPoint) <= movieList->getNodeValue(currentLowestIndex)) {
				movieList->swapNodes(comparingPoint, currentLowestIndex);
				currentLowestIndex = comparingPoint;
			}
		}
	}
}

void Movies::sort_MergeSortParent() {
	sortHelper_MergeSort_MergeSort(0, movieList->getLength());
}
void Movies::sortHelper_MergeSort_MergeSort(size_t start, size_t endpoint) {
	if(start < endpoint/*&& start != end*/) {
		size_t midpoint = static_cast<size_t>(ceil((static_cast<double>(start) + static_cast<double>(endpoint)) / 2.0));
		sortHelper_MergeSort_MergeSort(start, midpoint);
		sortHelper_MergeSort_MergeSort(midpoint + 1, endpoint);

		sortHelper_MergeSort_Merge(start, midpoint, midpoint + 1, endpoint);
	}
}
void Movies::sortHelper_MergeSort_Merge(size_t startOfA, size_t endOfA, size_t startOfB, size_t endOfB) {
	size_t sizeOfA = endOfA - startOfA + 1;
	size_t remaingValuesA = sizeOfA;
	size_t sizeOfB = endOfB - startOfB + 1;
	size_t remaingValuesB = sizeOfB;
	size_t currentArrayIndex = 0;
	Movie** mergedArray = new Movie*[sizeOfA + sizeOfB];

	while (remaingValuesA > 0 && remaingValuesB > 0) {
		// if not in order:
		if(movieList->getNodeValue(sizeOfA - remaingValuesA)->getMovieTitle() <= movieList->getNodeValue(sizeOfB - remaingValuesB)->getMovieTitle()) {
			mergedArray[currentArrayIndex++] = movieList->getNodeValue(sizeOfA - remaingValuesA--);
		}
		else {
			mergedArray[currentArrayIndex++] = movieList->getNodeValue(sizeOfB - remaingValuesB--);
		}
	}

	while (remaingValuesA > 0) {
		mergedArray[currentArrayIndex++] = movieList->getNodeValue(sizeOfA - remaingValuesA--);
	}

	while (remaingValuesB > 0) {
		mergedArray[currentArrayIndex++] = movieList->getNodeValue(sizeOfB - remaingValuesA--);
	}
	for (size_t i = 0; i < sizeOfA + sizeOfB; i++) {
		movieList->setNodeValue(sizeOfA + i, mergedArray[i]);
	}
}
/*
 Movie* Movies::sortHelper_MergeSort_Merge(Movie* arrayA, Movie* arrayB, size_t sizeOfA, size_t sizeOfB) {
 Movie* mergedArray = new Movie[sizeOfA + sizeOfB];
 Movie movieBuffer;
 size_t remaingValuesA = sizeOfA;
 size_t remaingValuesB = sizeOfB;

 while (remaingValuesA > 0 && remaingValuesB > 0) {
 if(arrayA[sizeOfA - remaingValuesA].getMovieTitle() >= arrayB[sizeOfB - remaingValuesB].getMovieTitle()) {

 }
 }

 delete[] arrayA;
 delete[] arrayB;
 return mergedArray;
 }
 */
/*
 void Merge(int arr[], int i, int j, int k) {
 int mergedSize = k - i + 1;                // Size of merged partition
 int mergePos = 0;                          // Position to insert merged number
 int leftPos = 0;                           // Position of elements in left partition
 int rightPos = 0;                          // Position of elements in right partition
 int* mergedNumbers = new int[mergedSize];   // Dynamically allocates temporary array
 // for merged arr

 leftPos = i;                               // Initialize left partition position
 rightPos = j + 1;                          // Initialize right partition position

 // Add smallest element from left or right partition to merged arr
 while (leftPos <= j && rightPos <= k) {
 if(arr[leftPos] < arr[rightPos]) {
 mergedNumbers[mergePos] = arr[leftPos];
 ++leftPos;
 }
 else {
 mergedNumbers[mergePos] = arr[rightPos];
 ++rightPos;

 }
 ++mergePos;
 }

 // If left partition is not empty, add remaining elements to merged numbers
 while (leftPos <= j) {
 mergedNumbers[mergePos] = arr[leftPos];
 ++leftPos;
 ++mergePos;
 }

 // If right partition is not empty, add remaining elements to merged numbers
 while (rightPos <= k) {
 mergedNumbers[mergePos] = arr[rightPos];
 ++rightPos;
 ++mergePos;
 }

 // Copy merge number back to arr
 for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
 arr[i + mergePos] = mergedNumbers[mergePos];
 }
 }
 */
void Movies::sort_QuickSort() {

}
void Movies::sortHelper_Partition() {

}

Movies::Movies() {
	movieList = new LinkedList<Movie*>;
}

Movies::~Movies() {
	delete movieList;
}

void Movies::addMovieToList() {
	char tempString[100];
	size_t length;
	size_t year;
	size_t numOscars;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;

	//add a movie
	cin.ignore();   //remove the \n from the keyboard buffer
	cout << "\n\nMOVIE TITLE: ";
	cin.getline(tempString, 100);
	title = new Text(tempString);
	cout << "\nMOVIE LENGTH (in minutes): ";
	cin >> length;
	cout << "\nMOVIE YEAR: ";
	cin >> year;
	cin.ignore();
	cout << "\nMOVIE GENRE: ";
	cin.getline(tempString, 100);
	genre = new Text(tempString);
	cout << "\nMOVIE RATING: ";
	cin.getline(tempString, 100);
	rating = new Text(tempString);
	cout << "\nNUMBER OF OSCARS WON: ";
	cin >> numOscars;
	cout << "\nSTAR RATING (out of 10): ";
	cin >> numStars;

	//create the movie
	Movie* oneMovie = new Movie(title, length, year, genre, rating, numOscars, numStars);

	//add the movie to the list (library)
	movieList->appendNode(oneMovie);

	//confirm addition to user
	cout << endl;
	title->displayText();
	cout << " was added to the movie library!\n";

}

void Movies::removeMovieFromList() {
	size_t movieChoice;

	if(movieList->getLength() <= 1) {
		cout << endl << "There must always be at least one movie in your library.  You can\'t";
		cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else {
		cout << "\n\nChoose from the following movies to remove:\n";
		displayMovieTitles();
		cout << "\nChoose a movie to remove between 1 & " << movieList->getLength() << ":  ";
		cin >> movieChoice;

		while (movieChoice < 1 || movieChoice > movieList->getLength()) {
			cout << "\nOops!  You must enter a number between 1 & " << movieList->getLength() << ":  ";
			cin >> movieChoice;
		}
		cout << "\n\nThe movie \"";
		movieList->getNodeValue(movieChoice - 1)->getMovieTitle()->displayText();
		cout << "\" has been successfully deleted.\n";

		movieList->deleteNode(movieChoice - 1);

	}
}

void Movies::editMovieInList() {
	size_t movieChoice;

	cout << "\n\nChoose from the following movies to edit:\n";
	this->displayMovieTitles();

	cout << "\nChoose a movie to edit between 1 & " << movieList->getLength() << ":  ";
	cin >> movieChoice;

	while (movieChoice < 1 || movieChoice > movieList->getLength()) {
		cout << "\nOops!  You must enter a number between 1 & " << movieList->getLength() << ":  ";
		cin >> movieChoice;
	}

	Movie* oneMovie = movieList->getNodeValue(movieChoice - 1);

	oneMovie->editMovie();
}

void Movies::displayMovies() {
	if(movieList->getLength() > 0) {
		for (size_t x = 0; x < (movieList->getLength()); x++) {
			cout << endl << right << setw(50) << "----------MOVIE " << (x + 1) << "----------";
			movieList->getNodeValue(x)->printMovieDetails();
			cout << endl << right << setw(50) << "----------MOVIE " << (x + 1) << "----------";
		}
	}
	else
		cout << "\nThere are no movies in your library yet.";
}

void Movies::displayMovieTitles() {
	//Text* movieTitle;
	for (size_t x = 0; x < movieList->getLength(); x++) {
		cout << "\nMOVIE " << (x + 1) << ": ";
		movieList->getNodeValue(x)->getMovieTitle()->displayText();
	}
}

void Movies::readMoviesFromFile(string filename) {
	this->readMoviesFromFile(filename.c_str());
}

void Movies::readMoviesFromFile(char *filename) {
	string buffer(filename);
	this->readMoviesFromFile(buffer);
}
void Movies::readMoviesFromFile(const char *filename) {
	string filename_as_string(filename);
	size_t numMoviesReadFromFile = 0;
	ifstream inFile;
	string inputBuffer;
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	size_t movieLength;   //length of movie in minutes
	size_t movieYear;   //year released
	size_t movieOscars;   //number of oscars won
	float movieNumStars;   //from IMDB out of 10 stars

	inFile.open(filename_as_string.c_str());
	if(inFile.good()) {
		getline(inFile, inputBuffer);
		while (!inFile.eof()) {
			title = new Text(inputBuffer);   //create a text for the movie title
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore();   //get rid of \n in the inFile buffer

			getline(inFile, inputBuffer);   //read in genre
			genre = new Text(inputBuffer);   //create a text for genre
			getline(inFile, inputBuffer);   //read in rating
			rating = new Text(inputBuffer);   //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore();   //get rid of \n in the inFile buffer

			//one movie has been read from the file.  Now create a movie object
			oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);

			//add the movie to the list (library)
			movieList->appendNode(oneMovie);

			//confirm addition to user
			cout << "\n" << title->getString() << " was added to the movie library!\n";

			getline(inFile, inputBuffer);   //read in the next movie title if there is one

			numMoviesReadFromFile++;
		}

		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file.\n\n";
	}
	else {
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
	cout << flush;
}

void Movies::saveToFile(string filename) {
	this->saveToFile(filename.c_str());
}
void Movies::saveToFile(char *filename) {
	ofstream outFile;

	outFile.open(filename);

	for (size_t x = 0; x < movieList->getLength(); x++) {
		movieList->getNodeValue(x)->printMovieDetailsToFile(outFile);   //function in Movies.cpp
	}
	outFile.close();

	cout << "\n\nAll movies in your library have been printed to " << filename << "\n" << flush;
}

size_t Movies::getNumMovies() const {
	return movieList->getLength();
}
