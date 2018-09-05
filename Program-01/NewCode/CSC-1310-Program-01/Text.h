#if !defined(TEXT_H)
	#define TEXT_H
/* * * * * * * * * * * * * * * * * * * * * * * *
*
*	Title:      CSC1310 - Program 01 - Bootleg String Class
*	Author(s):  Rus Hoffman
*	Date:       September 4, 2018
*	Purpose:
*
* * * * * * * * * * * * * * * * * * * * * * * */



#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;



class Text {
	private:
		//Variables:
			const char* textArray;
			long textLength;
			bool textIsAllocated;
		//Private functions:


	public:
		//default Constructor
		Text() {
			textIsAllocated = false;
			textLength = 0;
		}
		//Overloading Constructor for quicker setup
		Text(const char* inputText) {
			textArray = inputText;
			textLength = 0;
			while (textArray[textLength] != '\0') {
				textLength = textLength + 1;
			}
			textIsAllocated = true;
		}

		//Destructor
		~Text() {
			if (textIsAllocated == true) {
				delete[] textArray;
			}
		}

		//Functions:
			/*
				Function Name:  displayText()
				Parameters:  nothing (void)
				Returns:  nothing (void)
				Purpose:  prints out the string (character array) with no formatting or new lines
			*/
			void displayText(){
				if (textIsAllocated == false) {
					cerr << "There is no text to display";
					return;
				}
				cout << textArray;
			}

			/*
				Function Name:  getText()
				Parameters:  none
				Returns:  pointer to a constant character array
			*/
			const char* getText(){
				if (textIsAllocated == false) {
					cerr << "error attempting to return undefined text" << endl;
					return -1;
				}
				return textArray;
			}

			/*
				Function Name:  getLength()
				Parameters:  nothing (void)
				Returns:  the length of the string
			*/
			long getLength() {
				if (textIsAllocated == flase) {
					cerr << "error attempting to return length of undefined text" << endl;
					return -1;
				}
				return textLength;
			}

			/*
				Function Name:  editText()
				Parameters:  Send a pointer to a c-string
				Returns:  nothing (void)
			*/
			void editText(const char* newCharArray) {
				if (textIsAllocated == true) {
					delete[] textArray;
				}
				textIsAllocated = false;

				textArray = newCharArray;
				textLength = 0;
				while (textArray[textLength] != '\0') {
					textLength = textLength + 1;
				}
				textIsAllocated = true;
			}

};


#endif
