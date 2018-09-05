/*
	Title:  Movie.cpp
	Author:  April Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#include "Movie.h"
#include "Text.h"

Movie* createMovie(Text* title, int length)
{
	//dynamically allocate a new Movie
	Movie* myMovie = new Movie;
	
	//assign parameter data to structure memebers
	myMovie->movieTitle = title;
	myMovie->movieLength = length;
	
	return myMovie;
}

Movie* createMovie(Text* title, int length, int year, Text* genre, Text* rating, int nom, float stars) //all info is know
{
	//dynamically allocate a new Movie
	Movie* myMovie = new Movie;
	
	//assign parameter data to structure members
	myMovie->movieTitle = title;
	myMovie->movieLength = length;
	myMovie->movieYear = year;
	myMovie->movieGenre = genre;
	myMovie->movieRating = rating;
	myMovie->movieOscars = nom;
	myMovie->movieNumStars = stars;
	
	return myMovie;
}
void destroyMovie(Movie* myMovie)
{
	destroyText(myMovie->movieTitle);
	destroyText(myMovie->movieGenre);
	destroyText(myMovie->movieRating);
	delete myMovie;
}

void printMovieDetails(Movie* myMovie)
{
	cout << endl;
	cout << right << setw(30) << "Movie Title:  " << left;
	displayText(myMovie->movieTitle);
	cout << endl;
	cout << right << setw(30) << "Length (minutes):  " << left << myMovie->movieLength << endl;
	cout << right << setw(30) << "Year Released:  " << left << myMovie->movieYear << endl;
	cout << right << setw(30) << "Genre:  " << left;
	displayText(myMovie->movieGenre);
	cout << endl;
	cout << right << setw(30) << "Rating:  " << left;
	displayText(myMovie->movieRating);
	cout << endl;
	cout << right << setw(30) << "Number of Oscars Won:  " << left << myMovie->movieOscars << endl;
	cout << right << setw(30) << "Number of Stars:  " << left << myMovie->movieNumStars << endl << endl;
}

void printMovieDetailsToFile(Movie* myMovie, ofstream &outFile)
{
	char temp[1000];
	strncpy(temp, getText(myMovie->movieTitle), 1000);
	outFile << temp << endl;
	outFile << myMovie->movieLength << endl;
	outFile << myMovie->movieYear << endl;
	strncpy(temp, getText(myMovie->movieGenre), 1000);
	outFile << temp << endl;
	strncpy(temp, getText(myMovie->movieRating), 1000);
	outFile << temp << endl;
	outFile << myMovie->movieOscars << endl;
	outFile << myMovie->movieNumStars << endl;
}


void editMovie(Movie* myMovie)
{
	int choice;
	Text* tempText;
	char temp[100];
	
	do
	{
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
		while(choice < 1 || choice > 8)
		{
			cout << "\nOOPS!  Enter choice 1 through 8:  ";
			cin >> choice;
		}
		cin.ignore();
		
		switch(choice)
		{
			case 1: cout << "\nCurrent Title: ";
					displayText(myMovie->movieTitle);
					destroyText(myMovie->movieTitle);
					cout << "\nNEW TITLE:  ";
					cin.getline(temp, 100);
					tempText = createText(temp);
					myMovie->movieTitle = tempText;
					break;
			
			case 2:	cout << "\nCurrent Length: " << myMovie->movieLength;
					cout << "\nNEW LENGTH:  ";
					cin >> myMovie->movieLength;
					break;
					
			case 3: cout << "\nCurrent Year: " << myMovie->movieYear;
					cout << "\nNEW LENGTH:  ";
					cin >> myMovie->movieYear;
					break;
					
			case 4:	cout << "\nCurrent Genre: ";
					displayText(myMovie->movieGenre);
					destroyText(myMovie->movieGenre);
					cout << "\nNEW GENRE:  ";
					cin.getline(temp, 100);
					tempText = createText(temp);
					myMovie->movieGenre = tempText;
					break;
					
			case 5: cout << "\nCurrent Rating: ";
					displayText(myMovie->movieRating);
					destroyText(myMovie->movieRating);
					cout << "\nNEW GENRE:  ";
					cin.getline(temp, 100);
					tempText = createText(temp);
					myMovie->movieRating = tempText;
					break;
			
			case 6: cout << "\nCurrent Number of Oscars Won: " << myMovie->movieOscars;
					cout << "\nNEW NUMBER OF OSCARS:  ";
					cin >> myMovie->movieOscars;
					break;
					
			case 7:	cout << "\nCurrent Star Rating from IMDB: " << myMovie->movieNumStars;
					cout << "\nNEW STAR RATING:  ";
					cin >> myMovie->movieNumStars;
					break;
		}
	}while(choice != 8);
}

Text* getMovieTitle(Movie* myMovie)
{
	return myMovie->movieTitle;
}

int getMovieLength(Movie* myMovie)
{
	return myMovie->movieLength;
}

int getMovieYear(Movie* myMovie)
{
	return myMovie->movieYear;
}

Text* getMovieGenre(Movie* myMovie)
{
	return myMovie->movieGenre;
}

Text* getMovieRating(Movie* myMovie)
{
	return myMovie->movieRating;
}

int getMovieOscars(Movie* myMovie)
{
	return myMovie->movieOscars;
}

float getMovieNumStars(Movie* myMovie)
{
	return myMovie->movieNumStars;
}

void setMovieTitle(Movie* myMovie, Text* title)
{
	myMovie->movieTitle = title;
}

void setMovieLength(Movie* myMovie, int length)
{
	myMovie->movieLength = length;
}

void setMovieYear(Movie* myMovie, int year)
{
	myMovie->movieYear = year;
}

void setMovieGenre(Movie* myMovie, Text* genre)
{
	myMovie->movieGenre = genre;
}

void setMovieRating(Movie* myMovie, Text* rating)
{
	myMovie->movieRating = rating;
}

void setMovieOscars(Movie* myMovie, int oscars)
{
	myMovie->movieOscars = oscars;
}

void setMovieNumStars(Movie* myMovie, float stars)
{
	myMovie->movieNumStars = stars;
}
