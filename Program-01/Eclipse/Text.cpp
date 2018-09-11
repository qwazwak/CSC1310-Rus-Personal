/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:      CSC1310 - Program 01 - Bootleg String Class
 *	Author(s):  Rus Hoffman
 *	Date:       September 4, 2018
 *	Purpose:
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "Text.h"

using namespace std;

//default Constructor
Text::Text () {

	textArray = NULL;
	textIsAllocated = false;
	textLength = 0;
}

//Overloading Constructor for quicker setup
Text::Text (const char* inputText) {
	textArray = inputText;
	textLength = 0;
	while (textArray[textLength] != '\0') {
		textLength = textLength + 1;
	}
	textIsAllocated = true;
}

Text::Text (string inputText) {
	textArray = inputText.c_str();
	textLength = inputText.length();
	textIsAllocated = true;
}

//Destructor
Text::~Text () {
	if(textIsAllocated == true) {
		delete[] textArray;
	}
}

void Text::displayText () {
	if(textIsAllocated == false) {
		cerr << "There is no text to display";
		return;
	}
	cout << textArray;
}

const char* Text::getText () {
	if(textIsAllocated == false) {
		cerr << "error attempting to return undefined text" << endl;
		return -1;
	}
	return textArray;
}

long Text::getLength () {
	if(textIsAllocated == false) {
		cerr << "error attempting to return length of undefined text" << endl;
		return -1;
	}
	return textLength;
}

void Text::editText (const char* newCharArray) {
	if(textIsAllocated == true) {
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
