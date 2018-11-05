/*
 Title:  Movie.cpp
 Author:  April Crockett, modified by Rus Hoffman
 Date:  11/7/2017
 Purpose:  Be able to create, manage, print & delete a single movie.
 */
#include "Movie.h"
#include "Text.h"

Movie::Movie(Text* title, size_t length) {
	//assign parameter data to structure memebers
	movieTitle = title;
	movieLength = length;
}

Movie::Movie(Text* title, size_t length, size_t year, Text* genre, Text* rating, size_t nom, float stars) {
	//assign parameter data to structure members
	movieTitle = title;
	movieLength = length;
	movieYear = year;
	movieGenre = genre;
	movieRating = rating;
	movieOscars = nom;
	movieNumStars = stars;

}

Movie::~Movie() {
	delete movieTitle;
	delete movieGenre;
	delete movieRating;
}

void Movie::printMovieDetails() {
	cout << endl;
	cout << right << setw(30) << "Movie Title:  " << left << movieTitle->getString() << "\n";
	cout << right << setw(30) << "Length (minutes):  " << left << movieLength << "\n";
	cout << right << setw(30) << "Year Released:  " << left << movieYear << "\n";
	cout << right << setw(30) << "Genre:  " << left << movieGenre->getString() << "\n";
	cout << right << setw(30) << "Rating:  " << left << movieRating->getString() << "\n";
	cout << right << setw(30) << "Number of Oscars Won:  " << left << movieOscars << "\n";
	cout << right << setw(30) << "Number of Stars:  " << left << movieNumStars << "\n" << "\n";
	cout << flush;
}

void Movie::printMovieDetailsToFile(ofstream &outFile) {
	outFile << movieTitle << "\n";
	outFile << movieLength << "\n";
	outFile << movieYear << "\n";
	outFile << movieGenre << "\n";
	outFile << movieRating << "\n";
	outFile << movieOscars << "\n";
	outFile << movieNumStars << "\n" << flush;
}

void Movie::editMovie() {
	size_t choice;
	//Text* tempText;
	//char temp[100];
	string inputBuffer;
	
	do {
		cout << "\n\nWhich detail do you wish to edit?\n";
		cout << "1.  Title\n";
		cout << "2.  Length\n";
		cout << "3.  Year\n";
		cout << "4.  Genre\n";
		cout << "5.  Rating\n";
		cout << "6.  Number of Oscars Won\n";
		cout << "7.  Number of Stars\n";
		cout << "8.  DONE EDITING\n";
		cout << "CHOOSE 1-8:  ";
		cin >> choice;
		while (choice < 1 || choice > 8) {
			cout << "\nOOPS!  Enter choice 1 through 8:  ";
			cin >> choice;
		}
		cin.ignore();
		
		switch (choice) {
		case 1:
			cout << "\nCurrent Title: " << movieTitle << "\n";
			cout << "NEW TITLE:  " << flush;
			getline(cin, inputBuffer);
			movieTitle->editText(inputBuffer.c_str());
			break;

		case 2:
			cout << "\nCurrent Length: " << movieLength << "\n";
			cout << "NEW LENGTH:  " << flush;
			cin >> movieLength;
			break;

		case 3:
			cout << "\nCurrent Year: " << movieYear << "\n";
			cout << "NEW LENGTH:  " << flush;
			cin >> movieYear;
			break;

		case 4:
			cout << "\nCurrent Genre: " << movieGenre << "\n";
			cout << "NEW GENRE:  " << flush;
			getline(cin, inputBuffer);
			movieGenre->editText(inputBuffer.c_str());
			break;

		case 5:
			cout << "\nCurrent Rating: " << movieRating << "\n";
			cout << "NEW GENRE:  ";
			getline(cin, inputBuffer);
			movieRating->editText(inputBuffer.c_str());
			break;
			
		case 6:
			cout << "\nCurrent Number of Oscars Won: " << movieOscars << "\n";
			cout << "NEW NUMBER OF OSCARS:  " << flush;
			cin >> movieOscars;
			break;
			
		case 7:
			cout << "\nCurrent Star Rating from IMDB: " << movieNumStars << "\n";
			cout << "NEW STAR RATING:  " << flush;
			cin >> movieNumStars;
			break;
		}
	}while (choice != 8);
}

Text* Movie::getMovieTitle() const {
	return movieTitle;
}
/*
string Movie::getMovieTitleAsString() const {
	return string(this->movieTitle->getText());
}
*/
size_t Movie::getMovieLength() const {
	return movieLength;
}

size_t Movie::getMovieYear() const {
	return movieYear;
}

Text* Movie::getMovieGenre() const {
	return movieGenre;
}

Text* Movie::getMovieRating() const {
	return movieRating;
}

size_t Movie::getMovieOscars() const {
	return movieOscars;
}

float Movie::getMovieNumStars() const {
	return movieNumStars;
}

void Movie::setMovieTitle(Text* title) {
	movieTitle = title;
}

void Movie::setMovieLength(size_t length) {
	movieLength = length;
}

void Movie::setMovieYear(size_t year) {
	movieYear = year;
}

void Movie::setMovieGenre(Text* genre) {
	movieGenre = genre;
}

void Movie::setMovieRating(Text* rating) {
	movieRating = rating;
}

void Movie::setMovieOscars(size_t oscars) {
	movieOscars = oscars;
}

void Movie::setMovieNumStars(size_t stars) {
	movieNumStars = stars;
}
