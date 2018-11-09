/*
 *	Title:  Movies.cpp
 *	Author:  April R Crockett, modified by Rus Hoffman
 *	Date:  11/7/2017
 *	Purpose:  Be able to create, manage, print, save & delete a movie library
 */
#include "Movies.h"
#include "Timer.h"
#include "Movie.h"
#include "LinkedList.h"
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>

#if defined(RUN_FAST)

#define MOVIES_RUN_FAST
#endif
int lower_case(char c) {
	return tolower(c);
}

bool isAlphaOrder(const char* A, const char* B) {
	string lowerA(A);
	string lowerB(B);
	return lowerA.compare(lowerB) <= 0 ? true : false;
}

bool isAlphaOrder(char* A, char* B) {
	string lowerA(A);
	string lowerB(B);
	return lowerA.compare(lowerB) <= 0 ? true : false;
}
bool isAlphaOrder(const string A, const string B) {
	string lowerA(A);
	string lowerB(B);
	return lowerA.compare(lowerB) <= 0 ? true : false;
}
bool isAlphaEqual(const string A, const string B) {
	string lowerA(A);
	string lowerB(B);
	return lowerA.compare(lowerB) == 0 ? true : false;
}

/*
 time_t getTime();
 double totalTime(time_t start, time_t end);
 */
void Movies::algorithmAnalysis() {
#if defined(DEBUG)
	clog << "starting benchmark" << endl;
#endif
	time_t benchmarkStartBuffer;
	Text* textBuffer = new Text("Llama");

	//cout << setw(40) << setfill(' ') << setw(40) << setfill(' ');

	this->movieList->shuffleNodes();
	benchmarkStartBuffer = getTime();
	this->sort_BubbleSort();
	cout << setw(30) << setfill(' ') << right << "Linear Search:    " << left << findDelta(benchmarkStartBuffer) << endl;

	this->sort_QuickSort();
	benchmarkStartBuffer = getTime();
	this->search_BinarySearch(textBuffer);
	cout << setw(30) << setfill(' ') << right << "Binary Search:    " << left << findDelta(benchmarkStartBuffer) << endl;

	this->movieList->shuffleNodes();
	benchmarkStartBuffer = getTime();
	this->sort_BubbleSort();
	cout << setw(30) << setfill(' ') << right << "Bubble Sort:    " << left << findDelta(benchmarkStartBuffer) << endl;

	this->movieList->shuffleNodes();
	benchmarkStartBuffer = getTime();
	this->sort_InsertionSort();
	cout << setw(30) << setfill(' ') << right << "Insertion Sort:    " << left << findDelta(benchmarkStartBuffer) << endl;

	this->movieList->shuffleNodes();
	benchmarkStartBuffer = getTime();
	this->sort_InsertionSortDescending();
	cout << setw(30) << setfill(' ') << right << "Reverse Insertion Sort:    " << left << findDelta(benchmarkStartBuffer) << endl;

	this->movieList->shuffleNodes();
	benchmarkStartBuffer = getTime();
	this->sort_SelectionSort();
	cout << setw(30) << setfill(' ') << right << "SelectionSort:    " << left << findDelta(benchmarkStartBuffer) << endl;

	this->movieList->shuffleNodes();
	benchmarkStartBuffer = getTime();
	this->sort_MergeSortParent();
	cout << setw(30) << setfill(' ') << right << "Merge Sort:    " << left << findDelta(benchmarkStartBuffer) << endl;

	this->movieList->shuffleNodes();
	benchmarkStartBuffer = getTime();
	this->sort_QuickSort();
	cout << setw(30) << setfill(' ') << right << "Quick Sort:    " << left << findDelta(benchmarkStartBuffer) << endl;




	cout << setw(30) << setfill(' ') << setw(0) << left;
}
long Movies::search_LinearSearch(Text* key) {
	string keyBuffer(key->getText());
	transform(keyBuffer.begin(), keyBuffer.end(), keyBuffer.begin(), lower_case);
	string comparisonBuffer;
	for (long i = 0; i < static_cast<long>(movieList->getLength()); i++) {
		comparisonBuffer = movieList->getNodeValue(i)->getMovieTitle()->getText();
		transform(comparisonBuffer.begin(), comparisonBuffer.end(), comparisonBuffer.begin(), lower_case);
		if(strcmp(comparisonBuffer.c_str(), keyBuffer.c_str()) == 0) {
			return i;
		}
	}
	return -1;
}
long Movies::search_BinarySearch(Text* key, long first, long last) {
	if(first == -1) {
		first = 0;
	}
	if(last == -1) {
		last = this->movieList->getLength() - 1;
	}
	string comparisonBuffer;
	string keyBuffer(key->getText());
	transform(keyBuffer.begin(), keyBuffer.end(), keyBuffer.begin(), lower_case);
	long middle;   // Mid point of search

	if(first > last) {   //value was not found
		return -1;
	}

	middle = (first + last) / 2;
	comparisonBuffer = movieList->getNodeValue(middle)->getMovieTitle()->getText();
	transform(comparisonBuffer.begin(), comparisonBuffer.end(), comparisonBuffer.begin(), lower_case);
	if(strcmp(comparisonBuffer.c_str(), keyBuffer.c_str()) == 0) {
		return middle;
	}

	comparisonBuffer = movieList->getNodeValue(middle)->getMovieTitle()->getText();
	transform(comparisonBuffer.begin(), comparisonBuffer.end(), comparisonBuffer.begin(), lower_case);
	if(strcmp(comparisonBuffer.c_str(), keyBuffer.c_str()) > 0) {
		//if(array[middle] < value) {   //value not found yet and it is to the right of the middle
		return search_BinarySearch(key, middle + 1, last);
	}
	else {
		//value not found yet and it is to the left of the middle
		return search_BinarySearch(key, first, middle - 1);
	}

}
void Movies::sort_BubbleSort() {
	string bufferA;
	string bufferB;
	for (size_t maxElement = movieList->getLength() - 1; maxElement > 0; maxElement--) {
		for (size_t i = 0; i < maxElement; i++) {
			//swap the two adjacent elements if the one on the left is greater than the one on the right
			bufferA = movieList->getNodeValue(i)->getMovieTitle()->getText();
			bufferB = movieList->getNodeValue(i + 1)->getMovieTitle()->getText();
			transform(bufferA.begin(), bufferA.end(), bufferA.begin(), lower_case);
			transform(bufferB.begin(), bufferB.end(), bufferB.begin(), lower_case);
			if(strcmp(bufferA.c_str(), bufferB.c_str()) > 0) {
				movieList->swapNodes(i, i + 1);
			}
		}
	}
}
void Movies::sort_InsertionSort() {

	size_t indexOfCurrentLowest;
	Movie* temp;   //temporary variable for swap
	string comparisonBuffer;
	string currentKeyBuffer;
	Movie** moviesBootlegArray = new Movie*[this->movieList->getLength()];
	for (size_t i = 0; i < this->movieList->getLength(); i++) {
		moviesBootlegArray[i] = this->movieList->getNodeValue(i);
	}

	for (size_t start = 0; start < (this->movieList->getLength() - 1); start++) {
		indexOfCurrentLowest = start;
		currentKeyBuffer = moviesBootlegArray[indexOfCurrentLowest]->getMovieTitle()->getText();
		transform(currentKeyBuffer.begin(), currentKeyBuffer.end(), currentKeyBuffer.begin(), lower_case);
		//find the minimum value in the array starting from start and going through the end of the array
		//using i for "index"
		for (size_t i = start + 1; i < this->movieList->getLength(); i++) {
			comparisonBuffer = moviesBootlegArray[i]->getMovieTitle()->getText();
			transform(comparisonBuffer.begin(), comparisonBuffer.end(), comparisonBuffer.begin(), lower_case);
			if(strcmp(comparisonBuffer.c_str(), currentKeyBuffer.c_str()) < 0){
				currentKeyBuffer = moviesBootlegArray[i]->getMovieTitle()->getText();
				indexOfCurrentLowest = i;
			}
		}
		//now we have the index of the smallest value so swap
		temp = moviesBootlegArray[indexOfCurrentLowest];
		moviesBootlegArray[indexOfCurrentLowest] = moviesBootlegArray[start];
		moviesBootlegArray[start] = temp;

	}

	for (size_t i = 0; i < this->movieList->getLength(); i++) {
		this->movieList->setNodeValue(i, moviesBootlegArray[i]);
	}
	delete[] moviesBootlegArray;
}
void Movies::sort_InsertionSortDescending() {
	this->sort_InsertionSort();
	size_t limit = static_cast<size_t>(floor(static_cast<double>(this->movieList->getLength()) / 2.0));
	for (size_t i = 0; i < limit; i++) {
		this->movieList->swapNodes(i, movieList->getLength() - i - 1);
	}
}
void Movies::sort_SelectionSort() {
	size_t minIndex;
	string minValue;
	string comparisonBuffer;

	for (size_t start = 0; start < (this->movieList->getLength() - 1); start++) {
		minIndex = start;
		minValue = this->movieList->getNodeValue(start)->getMovieTitle()->getText();
		transform(minValue.begin(), minValue.end(), minValue.begin(), lower_case);

		//find the minimum value in the array starting from start and going through the end of the array
		//using i for "index"
		for (size_t i = start + 1; i < this->movieList->getLength(); i++) {
			comparisonBuffer = this->movieList->getNodeValue(i)->getMovieTitle()->getText();
			transform(minValue.begin(), minValue.end(), minValue.begin(), lower_case);

			if(strcmp(comparisonBuffer.c_str(), minValue.c_str()) <= 0) {
				minValue = this->movieList->getNodeValue(i)->getMovieTitle()->getText();
				transform(minValue.begin(), minValue.end(), minValue.begin(), lower_case);
				minIndex = i;
			}
		}
		//now we have the index of the smallest value so swap
		this->movieList->swapNodes(start, minIndex);
	}
}

void Movies::sort_MergeSortParent() {
	this->sort_MergeSort(0, movieList->getLength());
}

void Movies::sort_MergeSort(size_t start = -1, size_t endpoint = -1) {
	static bool hasRun = false;
	if(hasRun == false) {
		hasRun = true;
		start = 0;
		endpoint = this->movieList->getLength() - 1;

	}
	if(start < endpoint) {
		// Find the midpoint in the partition
		size_t midpoint = (start + endpoint) / 2;

		// Recursively sort left and right partitions
		this->sort_MergeSort(start, midpoint);
		this->sort_MergeSort(midpoint + 1, endpoint);

		// Merge left and right partition in sorted order
		this->sortHelper_MergeSort_Merge(start, midpoint, endpoint);
	}
}

void Movies::sortHelper_MergeSort_Merge(size_t start, size_t midpoint, size_t endpoint) {
	string leftPosString;
	string rightPosString;

	size_t mergedSize = endpoint - start + 1;                // Size of merged partition
	size_t mergePos = 0;                          // Position to insert merged number
	size_t leftPos = 0;                           // Position of elements in left partition
	size_t rightPos = 0;                          // Position of elements in right partition
	Movie** mergedMovies = new Movie*[mergedSize];

	leftPos = start;                               // Initialize left partition position
	rightPos = midpoint + 1;                          // Initialize right partition position

	// Add smallest element from left or right partition to merged arr
	while (leftPos <= midpoint && rightPos <= endpoint) {
		leftPosString = this->movieList->getNodeValue(leftPos)->getMovieTitle()->getText();
		rightPosString = this->movieList->getNodeValue(rightPos)->getMovieTitle()->getText();
		transform(leftPosString.begin(), leftPosString.end(), leftPosString.begin(), lower_case);
		transform(rightPosString.begin(), rightPosString.end(), rightPosString.begin(), lower_case);

		//	mergedMovies[mergePos++] = this->movieList->getNodeValue((strcmp(leftPosString.c_str(), rightPosString.c_str()) <= 0) ? leftPos++ : rightPos++);
		if(strcmp(leftPosString.c_str(), rightPosString.c_str()) <= 0) {
			mergedMovies[mergePos++] = this->movieList->getNodeValue(leftPos++);
		}
		else {
			mergedMovies[mergePos++] = this->movieList->getNodeValue(rightPos++);

		}
	}

	// If left partition is not empty, add remaining elements to merged numbers
	while (leftPos <= midpoint) {
		mergedMovies[mergePos++] = this->movieList->getNodeValue(leftPos++);


	}

	// If right partition is not empty, add remaining elements to merged numbers
	while (rightPos <= endpoint) {
		mergedMovies[mergePos++] = this->movieList->getNodeValue(rightPos++);

	}

	// Copy merge number back to arr
	for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
		this->movieList->setNodeValue(start + mergePos, mergedMovies[mergePos]);
	}

	delete[] mergedMovies;

}

void Movies::sort_QuickSort() {
	this->sort_QuickSort_Worker(0, this->movieList->getLength() - 1);
}
void Movies::sort_QuickSort_Worker(long low, long high) {
	if(low < high) {
		// pi is partitioning index, arr[pi] is now
		// at right place
		long pi = sortHelper_Partition(low, high);

		this->sort_QuickSort_Worker(low, pi - 1);		// Before pi
		this->sort_QuickSort_Worker(pi + 1, high);		// After pi
	}

}
long Movies::sortHelper_Partition(long low, long high) {
// pivot (Element to be placed at right position)
	string pivot(this->movieList->getNodeValue(high)->getMovieTitle()->getText());

	long i = (low - 1);
// Index of smaller element

	for (long j = low; j <= high - 1; j++) {
		// If current element is smaller than or
		// equal to pivot
		if(isAlphaOrder(this->movieList->getNodeValue(j)->getMovieTitle()->getString(), pivot)) {
			i++;    // increment index of smaller element
			this->movieList->swapNodes(i, j);
		}
	}
	this->movieList->swapNodes(i + 1, high);
	return (i + 1);
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
	cin.ignore();    //remove the \n from the keyboard buffer
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
			title = new Text(inputBuffer.c_str());   //create a text for the movie title
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore();   //get rid of \n in the inFile buffer

			getline(inFile, inputBuffer);   //read in genre
			genre = new Text(inputBuffer.c_str());   //create a text for genre
			getline(inFile, inputBuffer);   //read in rating
			rating = new Text(inputBuffer.c_str());   //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore();   //get rid of \n in the inFile buffer

			//one movie has been read from the file.  Now create a movie object
			oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);

			//add the movie to the list (library)
			movieList->appendNode(oneMovie);

			//confirm addition to user
#define MOVIES_RUN_FAST
#if !defined(MOVIES_RUN_FAST)
			cout << "\n" << title->getString() << " was added to the movie library!\n";
#endif
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
