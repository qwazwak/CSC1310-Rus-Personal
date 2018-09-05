/*
	Title:  Movies.cpp
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"

Movies* createMovies(int max)
{
	//dynamically create a new Movies structure
	Movies* myMovies = new Movies;
	myMovies->maxMovies = max;
	myMovies->numMovies = 0;
	
	//dynamically create the array that will hold the movies
	myMovies->moviesArray = new Movie*[max];
	
	return myMovies;
}

void resizeMovieArray(Movies* myMovies)
{
	int max = myMovies->maxMovies * 2; //increase size by 2
	
	//make an array that is twice as big as the one I've currently got
	Movie** newMoviesArray = new Movie*[max];
	for(int x = 0; x < myMovies->numMovies; x++)
	{
		newMoviesArray[x] = myMovies->moviesArray[x];
	}
	
	//delete the original array from memory
	delete [] myMovies->moviesArray;
	
	myMovies->moviesArray = newMoviesArray;
	myMovies->maxMovies = max;
}

void addMovieToArray(Movies* myMovies) 
{
	char tempString[100];
	int length, year, numOscars;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//get movie data from the user
	cin.ignore();  //remove the \n from the keyboard buffer
	cout << "\n\nMOVIE TITLE: ";
	cin.getline(tempString, 100);
	title = createText(tempString);
	cout << "\nMOVIE LENGTH (in minutes): ";
	cin >> length;
	cout << "\nMOVIE YEAR: ";
	cin >> year;
	cin.ignore();
	cout << "\nMOVIE GENRE: ";
	cin.getline(tempString, 100);
	genre = createText(tempString);
	cout << "\nMOVIE RATING: ";
	cin.getline(tempString, 100);
	rating = createText(tempString);
	cout << "\nNUMBER OF OSCARS WON: ";
	cin >> numOscars;
	cout << "\nSTAR RATING (out of 10): ";
	cin >> numStars;
	
	//create the movie
	Movie* oneMovie = createMovie(title, length, year, genre, rating, numOscars, numStars);
					
	//add the movie to the library	
	if(myMovies->numMovies == myMovies->maxMovies)
		resizeMovieArray(myMovies);	//increase size by 2

	myMovies->moviesArray[myMovies->numMovies] = oneMovie;

	(myMovies->numMovies)++;
}

void removeMovieFromArray(Movies* myMovies)
{
	int movieChoice;
	cout << myMovies->numMovies << endl << endl;
	//delete a movie if there is more than one movie in the library.
	if((myMovies->numMovies) <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:\n";
		displayMovieTitles(myMovies);
		cout << "\nChoose a movie to remove between 1 & " << myMovies->numMovies << ":  ";
		cin >> movieChoice;
		while(movieChoice < 1 || movieChoice > myMovies->numMovies)
		{
			cout << "\nOops!  You must enter a number between 1 & " << myMovies->numMovies << ":  ";
			cin >> movieChoice;
		}
		int movieIndexToBeRemoved = movieChoice-1;
		Text* movieTitle;
		movieTitle = myMovies->moviesArray[movieIndexToBeRemoved]->movieTitle;
		
		
		//destroy this movie
		destroyMovie(myMovies->moviesArray[movieIndexToBeRemoved]);
		
		int numElementsToMoveBack = (myMovies->numMovies) - 1;
		
		for(int x = movieIndexToBeRemoved; x < numElementsToMoveBack; x++)
		{
			myMovies->moviesArray[x] = myMovies->moviesArray[x+1]; //move array elements!
		}
		
		//set the last movie to a null pointer
		myMovies->moviesArray[numElementsToMoveBack] = NULL;
		
		//decrement the current number of movies
		(myMovies->numMovies)--;
		
		cout << "\n\nThe movie \"";
		displayText(movieTitle);
		cout << "\" has been successfully deleted.\n";	
	}
}

void editMovieInArray(Movies* myMovies)
{
	int movieChoice;
	
	cout << "\n\nChoose from the following movies to edit:\n";
	displayMovieTitles(myMovies);
	cout << "\nChoose a movie to remove between 1 & " << myMovies->numMovies << ":  ";
	cin >> movieChoice;
	while(movieChoice < 1 || movieChoice > myMovies->numMovies)
	{
		cout << "\nOops!  You must enter a number between 1 & " << myMovies->numMovies << ":  ";
		cin >> movieChoice;
	}
	Movie* oneMovie = myMovies->moviesArray[movieChoice-1];
	editMovie(oneMovie);
}

void destroyMovies(Movies* myMovies)
{
	//delete each movie
	for(int x=0; x< myMovies->numMovies; x++)
	{
		//delete myMovies->moviesArray[x];
		destroyMovie(myMovies->moviesArray[x]);
	}
	
	//delete movies array
	delete [] myMovies->moviesArray;
	
	//delete myMovies
	delete myMovies;
}

void displayMovies(Movies* myMovies)
{
	if(myMovies->numMovies > 0)
	{
		for(int x=0; x < (myMovies->numMovies); x++)
		{
			cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
			printMovieDetails(myMovies->moviesArray[x]); //function is in Movie.cpp
		}
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}

void displayMovieTitles(Movies* myMovies)
{
	Text* movieTitle;
	
	for(int x=0; x < (myMovies->numMovies); x++)
	{
		cout << "\nMOVIE " << (x+1) <<": ";
		movieTitle = myMovies->moviesArray[x]->movieTitle;
		displayText(movieTitle);
	}
}

void readMoviesFromFile(char *filename, Movies* myMovies)
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
			title = createText(temp);//create a text for the movie title
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			inFile.getline(temp, 100); //read in genre
			genre = createText(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = createText(temp); //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			//one movie has been read from the file.  Now create a movie object
			oneMovie = createMovie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);
			
			//now add this movie to the library
			if(myMovies->numMovies == myMovies->maxMovies)
				resizeMovieArray(myMovies);	//increase size by 2
			myMovies->moviesArray[myMovies->numMovies] = oneMovie;
			(myMovies->numMovies)++;
			
			//confirm addition to the user
			cout << endl;
			displayText(title);
			cout << " was added to the movie library!\n";
			
			
			inFile.getline(temp, 100); //read in the next movie title if there is one
			
			numMoviesReadFromFile++;
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

void saveToFile(char *filename, Movies* myMovies)
{
	ofstream outFile;
	
	outFile.open(filename);
	
	for(int x=0; x < (myMovies->numMovies); x++)
	{
		printMovieDetailsToFile(myMovies->moviesArray[x], outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}




