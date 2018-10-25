/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Program 02 - Driver source
 *	Author:	Rus Hoffman
 *	Date:	September264, 2018
 *	Purpose:	learn usage of stacks, queues, and ADTs
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "Queue.h"
#include "Stack.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

#define DEBUG_LOGGING

double worstCharToDouble (char input) {
	char aBootlegChar[2];
	aBootlegChar[0] = input;
	aBootlegChar[1] = '\n';
	return atof(aBootlegChar);
}

bool isLowerPriority (const char &firstChar, const char &secondChar) {
	int charAPri;
	int charBPri;
	switch (firstChar) {
		case '(':
			charAPri = 0;
			break;
		case '+':
		case '-':
			charAPri = 1;
			break;
		case '*':
		case '/':
			charAPri = 2;
			break;
		case ')':
			charAPri = 3;
			break;
		default:
			charAPri = -1;
			break;
	}
	switch (secondChar) {
		case '(':
			charBPri = 0;
			break;
		case '+':
		case '-':
			charBPri = 1;
			break;
		case '*':
		case '/':
			charBPri = 2;
			break;
		case ')':
			charBPri = 3;
			break;
		default:
			charBPri = -1;
			break;
	}
	if(charAPri == -1 || charBPri == -1) {
		string errorMessage = "Invalid char in isLowerPriority";
		throw (errorMessage);
	}
	return charAPri <= charBPri ? true : false;
}

string infixToPostfix (string inputExpression) {
	string stupidStringBuffer = "";
	MyQueue<char> infixQueue;
	for (size_t i = 0; i < inputExpression.length(); i++) {
		if(inputExpression.at(i) != ' ') {
			infixQueue.push(inputExpression.at(i));
		}
	}
	string outputString = "";
	MyStack<char> opStack;
	char currentToken;
	while (infixQueue.isEmpty() == false) {
		currentToken = infixQueue.pop();

		switch (currentToken) {
			case '(':
				opStack.push('(');
				break;
			case ')':
				while (opStack.isEmpty() == false && opStack.peek() != '(') {
					stupidStringBuffer = opStack.pop();
					outputString += stupidStringBuffer;
				}
				opStack.pop();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if(opStack.isEmpty() == false) {
					while (opStack.isEmpty() == false && isLowerPriority(currentToken, opStack.peek())) {
						stupidStringBuffer = opStack.pop();
						outputString += stupidStringBuffer;
					}
				}
				opStack.push(currentToken);
				break;
			default:
				outputString += currentToken;
				break;
		}

	}
	while (opStack.isEmpty() == false) {
		stupidStringBuffer = opStack.pop();
		outputString += stupidStringBuffer;
	}
	return outputString;
}

double calculatePostfixExpression (string inputString) {
	MyStack<double> numberStack;
	MyQueue<char> postfixEquation;
	double firstNumber;
	double secondNumber;
	char currentToken;
	string stringBuffer;
	for (size_t i = 0; i < inputString.length(); i++) {
		if(inputString.at(i) != ' ') {
			postfixEquation.push(inputString.at(i));
		}
	}

	while (postfixEquation.isEmpty() == false) {
		currentToken = postfixEquation.pop();
		if(isdigit(currentToken)) {
			numberStack.push(worstCharToDouble(currentToken));
		}
		else {
			firstNumber = numberStack.pop();
			secondNumber = numberStack.pop();
			switch (currentToken) {
				case '+':

					numberStack.push(secondNumber + firstNumber);
					break;
				case '-':
					numberStack.push(secondNumber - firstNumber);
					break;
				case '*':
					numberStack.push(secondNumber * firstNumber);
					break;
				case '/':
					numberStack.push(secondNumber / firstNumber);
					break;
				default:
					string error = "INVALID CHARS IN POSTFIX CALCULATOR";
					cerr << error << endl;
					throw (error);
			}
		}
	}
	return numberStack.pop();
}

int main () {
	string menuChoice;
	string inputBufferString;
	string infixString;
	string postfixString;
	double calculatedValue = 0;

	cout << "Infix to Postfix Converter" << endl;
	do {
		cout << "Enter an expression in postfix format" << endl;
		getline(cin, infixString);
		while (infixString.empty()) {
			cout << endl << endl;
			cout << "Error: be sure to enter an equation" << endl;
			cout << "Enter an expression in postfix format" << endl;
			getline(cin, infixString);
		}
		postfixString = infixToPostfix(infixString);

		//Remove spaces in string
		infixString.erase(std::remove(infixString.begin(), infixString.end(), ' '), infixString.end());
		{
			string infixWithSpacesTemp = "";
			for (size_t i = 0; i < infixString.length(); i++) {
				infixWithSpacesTemp += infixString.at(i);
				if(i + 1 < infixString.length()) {
					infixWithSpacesTemp += ' ';
				}
			}
			infixString = infixWithSpacesTemp;
		}

		postfixString.erase(std::remove(postfixString.begin(), postfixString.end(), ' '), postfixString.end());
		{
			string postfixWithSpacesTemp = "";
			for (size_t i = 0; i < postfixString.length(); i++) {
				postfixWithSpacesTemp += postfixString.at(i);
				if(i + 1 < postfixString.length()) {
					postfixWithSpacesTemp += ' ';
				}
			}
			postfixString = postfixWithSpacesTemp;
		}
		calculatedValue = calculatePostfixExpression(postfixString);


		cout << "Infix notation:" << endl << "\t" << infixString << endl << "Postfix notation:" << endl << "\t" << postfixString << endl << "Calculated Value:" << endl << "\t" << calculatedValue << endl << endl << endl;
		cout << "Would you like to run the program again? (Y\\N)" << "\n";
		getline(cin, menuChoice);

		while (cin.fail() || menuChoice.length() != 1 || (menuChoice.at(0) == 'Y' || menuChoice.at(0) == 'y') ? false : ((menuChoice.at(0) == 'N' || menuChoice.at(0) == 'n') ? false : true)) {
			if(cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "an error has occurred, try again" << "\n";
			}
			else {
					cout << "only enter Y for yes, or N for no" << "\n";
			}
			cout << "Would you like to run the program again? (Y\\N)" << "\n" << flush;
			getline(cin, menuChoice);
		}
	} while (menuChoice.at(0) == 'Y' || menuChoice.at(0) == 'y');
	cout << "\n" << "Goodbye!" << "\n" << flush;
	return 0;
}
