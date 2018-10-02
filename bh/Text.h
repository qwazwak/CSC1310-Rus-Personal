/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Program 01 - Bootleg String Class
 *	Author(s):	Rus Hoffman
 *	Date:		September 4, 2018
 *	Purpose:		Practice usage of classes and overloading of operators
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#if !defined(TEXT_H)
#define TEXT_H


#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Text {
	private:
		//Variables:



		string theText;

	public:
		//default Constructor
		Text ();

		//Overloading Constructor for quicker setup
		Text (const char*);
		Text (string);

		//Destructor
		~Text ();

		/*
		 Function Name:	displayText()
		 Parameters:		nothing (void)
		 Returns:			nothing (void)
		 Purpose:			prints out the text with no formatting, new lines, or flushing of the cout buffer
		 */
		void displayText ();

		/*
		 Function Name:	getText()
		 Parameters:		nothing (void)
		 Returns:			pointer to a constant character array
		 */
		string getText ();

		/*
		 Function Name:	getLength()
		 Parameters:		nothing (void)
		 Returns:			a long containing the length of the string
		 */
		long getLength ();

		/*
		 Function Name:	editText()
		 Parameters:		a pointer to a c-string or a string
		 Returns:			nothing (void)
		 */
		void editText (string newText);
		void editText (const char* newCharArray);
};

#endif
