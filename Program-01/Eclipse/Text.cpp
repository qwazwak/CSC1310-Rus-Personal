/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:      CSC1310 - Program 01 - Bootleg String Class
 *	Author(s):  Rus Hoffman
 *	Date:       September 4, 2018
 *	Purpose:
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
#define DEBUG
#include "Text.h"

using namespace std;
ostream& operator<< (ostream& outputStream, Text* textToOutput) {
#if defined(DEBUG)
	clog << "Text CLASS DEBUG: " << "Overloading << with Text*" << endl;
#endif
	outputStream << textToOutput->getTextString();
	return outputStream;
}

//default Constructor
Text::Text () {
#if defined(DEBUG)
	clog << "Text CLASS DEBUG: " << "Initializing a Text class with default constructor" << endl;
#endif
	textArray = NULL;
	textIsAllocated = false;
	textLength = 0;
}

//Overloading Constructor for quicker setup
Text::Text (const char* inputText) {
#if defined(DEBUG)
	clog << "Initializing a Text class with faster constructor (char)" << endl;
#endif
	textArray = inputText;
	textLength = 0;
	while (textArray[textLength] != '\0') {
		textLength = textLength + 1;
	}
	textIsAllocated = true;
}

Text::Text (string inputText) {
#if defined(DEBUG)
	clog << "Initializing a Text class with faster constructor (string)" << endl;
#endif
	textArray = inputText.c_str();
	textLength = inputText.length();
	textIsAllocated = true;
}

//Destructor
Text::~Text () {
#if defined(DEBUG)
	clog << "Text CLASS DEBUG: " << "Deallocating Text class" << endl;
#endif
	if(textIsAllocated == true) {
		delete[] textArray;
	}
}

void Text::displayText () {
#if defined(DEBUG)
	clog << "Text CLASS DEBUG: " << "Using cout built in function" << endl;
#endif
	if(textIsAllocated == false) {
		cerr << "There is no text to display";
		return;
	}
	cout << textArray;
}

const char* Text::getText () {
#if defined(DEBUG)
	clog << "Text CLASS DEBUG: " << "getting char text" << endl;
#endif
	if(textIsAllocated == false) {
		cerr << "error attempting to return undefined text" << endl;
	}
	return textArray;
}

string Text::getTextString () {
#if defined(DEBUG)
	clog << "Text CLASS DEBUG: " << "getting string" << endl;
#endif
	if(textIsAllocated == false) {
		cerr << "error attempting to return undefined text" << endl;
	}
	string str(textArray);
	return str;
}

long Text::getLength () {
#if defined(DEBUG)
	clog << "Text CLASS DEBUG: " << "getting length" << endl;
#endif
	if(textIsAllocated == false) {
		cerr << "error attempting to return length of undefined text" << endl;
		return -1;
	}
	return textLength;
}

void Text::editText (const char* newCharArray) {
#if defined(DEBUG)
	clog << "Text CLASS DEBUG: " << "replacing text" << endl;
#endif
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
