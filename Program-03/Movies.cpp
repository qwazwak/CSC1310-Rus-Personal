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
#if defined(RUN_FAST)

#define MOVIES_RUN_FAST
#endif
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
	string compareBuffer;
	for (long i = 0; i < static_cast<long>(movieList->getLength()); i++) {
		compareBuffer = string(key->getText());
		if(compareBuffer.compare(movieList->getNodeValue(i)->getMovieTitle()->getText()) == 0) {
			return i;
		}
	}
	return -1;
}
long Movies::search_BinarySearch(Text* key) {
	return search_BinarySearch(key, 0, this->movieList->getLength());
}
long Movies::search_BinarySearch(Text* key, long first, long last) {
	if(last < first) {
		return -1;   // value would be inserted at index "low"
	}
	long mid = static_cast<long>(floor(static_cast<double>(first + last) / 2.0));
	if(true == isAlphaEqual(movieList->getNodeValue(mid)->getMovieTitle()->getText(), key->getText())) {
		return mid;
	}
	if(false == isAlphaOrder(movieList->getNodeValue(mid)->getMovieTitle()->getText(), key->getText())) {
		return search_BinarySearch(key, first, mid - 1);
	}
	else if(true == isAlphaOrder(movieList->getNodeValue(mid)->getMovieTitle()->getText(), key->getText())) {
		return search_BinarySearch(key, mid + 1, last);
	}
	else {
		return mid;
	}

	/*

	 if(last == -1) {
	 last = this->movieList->getLength();
	 }
	 if(first == last) {
	 return first;
	 }
	 string stringKey(key->getText());
	 string first_string(this->movieList->getNodeValue(first)->getMovieTitle()->getText());
	 string last_string(this->movieList->getNodeValue(last)->getMovieTitle()->getText());
	 long midpointBOT = static_cast<long>(floor((first + last) / 2.0));
	 string midpointBOT_string(this->movieList->getNodeValue(midpointBOT)->getMovieTitle()->getText());
	 long midpointTOP = static_cast<long>(ceil((first + last) / 2.0));
	 string midpointTOP_string(this->movieList->getNodeValue(midpointTOP)->getMovieTitle()->getText());
	 if(midpointBOT == first && midpointTOP == last) {
	 if(first_string.compare(midpointBOT_string) == 0) {
	 return midpointBOT;
	 }
	 if(last_string.compare(midpointTOP_string) == 0) {
	 return midpointTOP;
	 }
	 }
	 if(stringKey.compare(midpointBOT_string) > 0) {
	 return this->search_BinarySearchWorker(key, midpointBOT, last);
	 }
	 if(stringKey.compare(midpointBOT_string) < 0) {
	 return this->search_BinarySearchWorker(key, first, midpointBOT);
	 }
	 return NULL;
	 */
}

size_t Movies::search_BinarySearchWorker(Text* key, size_t first, size_t last) {
	clog << "GOT LEVEL" << endl;
	size_t midpoint = static_cast<size_t>(floor(static_cast<double>(first + last) / 2.0));
	string stringKey(key->getText());

	string stringMidpoint(movieList->getNodeValue(midpoint)->getMovieTitle()->getText());
	if(last - 1 == first && first + 1 == last) {
		return -1;
	}
	if(stringKey.compare(movieList->getNodeValue(midpoint + 1)->getMovieTitle()->getText()) == 0) {
		return midpoint + 1;
	}
	if(stringKey.compare(movieList->getNodeValue(midpoint - 1)->getMovieTitle()->getText()) == 0) {
		return midpoint - 1;
	}
	if(stringKey.compare(movieList->getNodeValue(midpoint)->getMovieTitle()->getText()) == 0) {
		return midpoint;
	}
	if(stringKey.compare(stringMidpoint) == 0) {
		return midpoint;
	}
	if(stringKey.compare(stringMidpoint) > 0) {
		return this->search_BinarySearchWorker(key, midpoint, last);
	}
	if(stringKey.compare(stringMidpoint) < 0) {
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
	if(start >= endpoint   //&& start != end
	) {
		return;
	}
	size_t midpoint = static_cast<size_t>(floor((static_cast<double>(start) + static_cast<double>(endpoint)) / 2.0));
	if(start + 1 != endpoint) {
		sortHelper_MergeSort_MergeSort(start, midpoint);
		sortHelper_MergeSort_MergeSort(midpoint + 1, endpoint);
	}
	sortHelper_MergeSort_Merge(start, midpoint, midpoint + 1, endpoint);

}

void Movies::sortHelper_MergeSort_Merge(size_t startOfA, size_t endOfA, size_t startOfB, size_t endOfB) {

	size_t increment_A = 0;
	size_t sizeOfA = endOfA - startOfA + 1;
	size_t remaingValuesA = sizeOfA;
	size_t increment_B = 0;
	size_t sizeOfB = endOfB - startOfB + 1;
	size_t remaingValuesB = sizeOfB;

	Movie** mergedArray = new Movie*[sizeOfA + sizeOfB];
	size_t currentMergedArrayIndex = 0;

	while (remaingValuesA > 0 && remaingValuesB > 0) {
		mergedArray[currentMergedArrayIndex] = movieList->getNodeValue(isAlphaOrder(movieList->getNodeValue(increment_A)->getMovieTitle()->getString(), movieList->getNodeValue(increment_B)->getMovieTitle()->getString()) ? increment_A++ : increment_B++);
		currentMergedArrayIndex++;

	}
	while (remaingValuesA > 0) {
		mergedArray[currentMergedArrayIndex] = movieList->getNodeValue(increment_A++);
		currentMergedArrayIndex++;
	}
	while (remaingValuesB > 0) {
		mergedArray[currentMergedArrayIndex] = movieList->getNodeValue(increment_B++);
		currentMergedArrayIndex++;
	}

	for (size_t i = 0; i < sizeOfA + sizeOfB; i++) {
		movieList->setNodeValue(startOfA + i, mergedArray[i]);
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
