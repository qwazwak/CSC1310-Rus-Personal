/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Program 01 - Bootleg String Class
 *	Author(s):	Rus Hoffman
 *	Date:		September 4, 2018
 *	Purpose:		Practice usage of classes and overloading of operators
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
#include "Text.h"

#include <cstring>

using namespace std;

//Overloads the '<<' operator allowing the usage of cout << TextClassObject; to work
#if defined(STREAMOVERLOAD)
ostream& operator<< (ostream& outputStream, Text* textToOutput) {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "Overloading << with Text*" << endl;
#endif
	outputStream << textToOutput->getText();
	return outputStream;
}
#endif

//Default constructor
Text::Text () {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "Initializing a Text class with default constructor" << endl;
#endif
	textArray = "";
	textIsAllocated = true;
	textLength = 0;
}

//Overloading Constructor for quicker setup with a constant char array
Text::Text (const char* inputText) {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "Initializing a Text class with faster constructor (char)" << endl;
#endif
	textArray = inputText;
	textLength = 0;
	while (textArray[textLength] != '\0') {
		textLength = textLength + 1;
	}
	textIsAllocated = true;
}

//Overloading Constructor for quicker setup with a string
Text::Text (string inputText) {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "Initializing a Text class with faster constructor (string)" << endl;
#endif
	textArray = inputText.c_str();
	textLength = inputText.length();
	textIsAllocated = true;
}

//Destructor
Text::~Text () {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "Deallocating Text class" << endl;
#endif
	//If the memory is allocated when it comes time to deallocate, deallocate it
	if(textIsAllocated == true) {
		delete[] textArray;
	}
}

void Text::displayText () {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "Using cout built in function" << endl;
#endif
	cout << textArray;
}

const char* Text::getText () {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "getting char text" << endl;
#endif
	return textArray;
}

string Text::getTextString () {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "getting string" << endl;
#endif
	string str(textArray);
	return str;
}

long Text::getLength () {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "getting length" << endl;
#endif
	return strlen(textArray);
}

void Text::editText (string newText) {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "replacing text with string" << endl;
#endif
	editText(newText.c_str());
}

void Text::editText (const char* newCharArray) {
#if defined(TEXT_H_DEBUG)
	clog << "Text CLASS TEXT_H_DEBUG: " << "replacing text with char array" << endl;
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
