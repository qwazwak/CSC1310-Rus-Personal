/*
	Title:  Movies.cpp
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"
#include "LinkedList.h"
#include <cstring>

Movies::Movies()
{
	movieList = new LinkedList<Movie*>;
}


Movies::~Movies()
{
	delete movieList;
}

void Movies::addMovieToList() 
{
	char tempString[100];
	int length, year, numOscars;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//add a movie
	cin.ignore();  //remove the \n from the keyboard buffer
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

void Movies::removeMovieFromList()
{
	int movieChoice;
	
	if(movieList->getLength() <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:\n";
		displayMovieTitles();
		cout << "\nChoose a movie to remove between 1 & " << movieList->getLength() << ":  ";
		cin >> movieChoice;
		
		while(movieChoice < 1 || movieChoice > movieList->getLength())
		{
			cout << "\nOops!  You must enter a number between 1 & " << movieList->getLength() << ":  ";
			cin >> movieChoice;
		}
		cout << "\n\nThe movie \"";
		movieList->getNodeValue(movieChoice-1)->getMovieTitle()->displayText();
		cout << "\" has been successfully deleted.\n";	
		
		movieList->deleteNode(movieChoice-1);
		
	}
}

void Movies::editMovieInList()
{
	int movieChoice;
	
	cout << "\n\nChoose from the following movies to edit:\n";
	displayMovieTitles();
	
	cout << "\nChoose a movie to edit between 1 & " << movieList->getLength() << ":  ";
	cin >> movieChoice;
	
	while(movieChoice < 1 || movieChoice > movieList->getLength())
	{
		cout << "\nOops!  You must enter a number between 1 & " << movieList->getLength() << ":  ";
		cin >> movieChoice;
	}
	
	Movie* oneMovie = movieList->getNodeValue(movieChoice-1);
	
	oneMovie->editMovie();
}

void Movies::displayMovies()
{
	if(movieList->getLength() > 0)
	{
		for(int x=0; x < (movieList->getLength()); x++)
		{
			cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
			movieList->getNodeValue(x)->printMovieDetails(); 
		}
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}

void Movies::displayMovieTitles()
{
	Text* movieTitle;
	
	for(int x=0; x<movieList->getLength(); x++)
	{
		cout << "\nMOVIE " << (x+1) <<": ";
		movieList->getNodeValue(x)->getMovieTitle()->displayText();
	}
}

void Movies::readMoviesFromFile(char *filename)
{
	int numMoviesReadFromFile = 0;
	ifstream inFile;
	char temp[100];
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	int movieOscars; //number of oscars won
	float movieNumStars; //from IMDB out of 10 stars
	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{	
			title = new Text(temp);//create a text for the movie title
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			inFile.getline(temp, 100); //read in genre
			genre = new Text(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = new Text(temp); //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
	
			//one movie has been read from the file.  Now create a movie object
			oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);
			
			//add the movie to the list (library)
			movieList->appendNode(oneMovie); 
			
			//confirm addition to user
			cout << endl;
			title->displayText();
			cout << " was added to the movie library!\n";
				
						
			inFile.getline(temp, 100); //read in the next movie title if there is one
			
			numMoviesReadFromFile++;
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

void Movies::saveToFile(char *filename)
{
	ofstream outFile;
	
	outFile.open(filename);
	
	for(int x=0; x < movieList->getLength(); x++)
	{
		movieList->getNodeValue(x)->printMovieDetailsToFile(outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}


int Movies::getNumMovies() const
{
	return movieList->getLength();
}



