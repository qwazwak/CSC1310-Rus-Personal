/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:	CSC1310 - Program 02 - Driver source
 *	Author:	Rus Hoffman
 *	Date:	September264, 2018
 *	Purpose:	learn usage of stacks, queues, and ADTs
 *
 * * * * * * * * * * * * * * * * * * * * * * * */


#include <Queue.h>
#include <Stack.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

int worstCharToInt (char input) {
	switch (input) {
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
		default:
			return -1;
	}
}
/*
void removeSpaces (string &theString) {
	string newString = "";
	for (size_t i = 0; i < theString.length(); i++){
		if(theString.at(i) != ' '){
			newString += theString[i];
		}
	}
	theString = newString;
}

string makeStringCopyNoSpace (string theString) {
	string newString = "";
	for (size_t i = 0; i < theString.length(); i++){
		if(theString.at(i) != ' '){
			newString += theString.at(i);
		}
	}
	return newString;
}


void reverseString (string &theString) {
	for (size_t i = 0; i < theString.length(); i++) {
		theString += (theString[i] == ' ') ? 0 : 1;
	}
	while (theString.find(' ') != string::npos) {
		theString.erase(theString.find(' '));
	}
}
*/

bool isLowerPriority (const char &firstChar, const char &secondChar) {
	string errorMessage = "Invalid char in isLowerPriority";
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
		throw (errorMessage);
	}
	return charAPri < charBPri ? true : false;
}

MyQueue<char>* fuglyConverter (const string inputString) {
	MyQueue<char> inputDataQ;
	for (size_t i = 0; i < inputString.length(); i++) {
		inputDataQ.push_back(inputString[i]);
	}

	MyQueue<char>* postfixQueue = new MyQueue<char>;

	MyStack<char> opStack;
	char currentToken;


	while (inputDataQ.empty() == false) {
		currentToken = inputDataQ.pop();
		switch (currentToken) {
			case '(':
				opStack.push('(');
				break;
			case ')':
				while (opStack.peek() != '(') {
					postfixQueue->push(opStack.pop());
				}
				opStack.pop();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (opStack.isEmpty() == false && isLowerPriority(currentToken, opStack.peek())) {
					postfixQueue->push(opStack.pop());
				}
				opStack.push(currentToken);
				break;
			default:     //Value is operand
				postfixQueue->push(currentToken);
				break;
		}
		while (opStack.empty() == false) {
			postfixQueue->push(opStack.pop());
		}
	}
	return postfixQueue;
}

/*
calculateExpression
this function accepts a string as a parameter and will return a double, which holds the result of the
calculation. This function will create a Stack<double> object. Then, it will parse through the string, one character at a time.
o If the character is a digit, then convert the character to a double and then push it on the stack.
o Otherwise, the character is an operator, so pop two nodes from the stack, saving their values in two different
temporary variables. Then, if the character is a ‘+’, then get the addition of these two values. If the character is a
‘-‘ then get the subtraction of the first one from the second one. Do this for addition, subtraction, multiplication,
and division. No other operator is supported in this program. Last, push this result on the stack.
Once you parse through the entire string, you can return the final result from this function.
 */
double calculateExpression (const string inputString) {
	double finalValue;
	MyQueue<char>* valuesToProcess = new MyQueue<char>;
	MyStack<long>* numberStack = new MyStack<long>;
	for(size_t i = 0; i < inputString.length(); i++){
		valuesToProcess->push(inputString.at(i));
	}
	char currentChar;
	long numberToWorkWithA;
	long numberToWorkWithB;

	while(inputString.length() > 0){
		currentChar = valuesToProcess->pop();
		if(isdigit(currentChar)){
			numberStack->push(static_cast<long>(worstCharToInt(currentChar)));
		}
		else{
			numberToWorkWithA = numberStack->pop();
			numberToWorkWithB = numberStack->pop();
			switch(currentChar){
				case '+':
					numberStack->push(numberToWorkWithB + numberToWorkWithA);
					break;
				case '-':
					numberStack->push(numberToWorkWithB - numberToWorkWithA);
					break;
				case '*':
					numberStack->push(numberToWorkWithB * numberToWorkWithA);
					break;
				case '/':
					numberStack->push(numberToWorkWithB / numberToWorkWithA);
					break;
				default:
					string badError = "INVALID OPERATOR";
					throw(badError);
					break;
			}
		}


	}
	delete valuesToProcess;
	delete numberStack;
	return finalValue;
}

double calculatePostfixExpression (const string &inputText) {
	char currentChar;
	string singleCharBuffer;
	string newEditableString = inputText;
	double result = 0;
	MyStack<double> theStack;


	double memeOne;
	double yeetTwo;
	removeSpaces(newEditableString);
	while (newEditableString.empty() == false) {
		currentChar = newEditableString[0];
		newEditableString.erase(0, 1);


		if(isdigit(currentChar) != 0) {
			theStack.push(static_cast<double>(worstCharToInt(currentChar)));
		}
		else {
			memeOne = theStack.pop();
			yeetTwo = theStack.pop();
			switch (currentChar) {
				case '+':
					theStack.push(yeetTwo + memeOne);
					break;
				case '-':
					theStack.push(yeetTwo - memeOne);
					break;
				case '*':
					theStack.push(yeetTwo * memeOne);
					break;
				case '/':
					theStack.push(yeetTwo / memeOne);
					break;
				default:
					cout << "well fuck" << endl;
					break;
			}
		}
	}
	return result;
}

int main () {
	int menuChoice;
	string inputBufferString;
	string infixString;
	string postfixString;
	MyQueue<char>* postfixQueue = new MyQueue<char>;
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
#if defined(DEBUG_LOGGING)
	clog << "Input loaded, about to remove space" << endl;
#endif
		removeSpaces(infixString);

#if defined(DEBUG_LOGGING)
	clog << "removed spaces" << endl;
#endif
		cout << endl;
		cout << "Infix notation: " << endl;
		cout << "\t";
		for (size_t i = 0; i < infixString.length(); i++) {
			cout << infixString.at(i) << " ";
		}
		cout << endl;
#if defined(DEBUG_LOGGING)
	clog << "done with infix" << endl;

	cout << "postfix" << endl;
	postfixQueue->display(true);
#endif
		delete postfixQueue;
		postfixQueue = fuglyConverter(infixString);

		cout << endl;
		postfixString = "";
		while(postfixQueue->empty() != false){
			postfixString += postfixQueue->pop();
		}
#if defined(DEBUG_LOGGING)
	clog << "made postfixString" << endl;
#endif
		calculatedValue = calculatePostfixExpression(postfixString);

		cout << "Postfix notation:" << endl;
		cout << "\t";
		cout << postfixString << endl;
		cout << endl;
		cout << "Calculated Value: " << calculatedValue << endl;

		cin.clear();
		cout << "\n" << "\n";
		cout << "Repeat or exit program?" << "\n";
		cout << "1.  do another equation" << "\n";
		cout << "2.  exit program" << "\n";
		cout << "CHOOSE 1 or 2:  " << flush;
		cin >> menuChoice;
		while (cin.fail() || menuChoice < 1 || menuChoice > 2) {
			if(cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "an error has occurred, try again" << "\n";
			}
			else {
				if(menuChoice < 1 || menuChoice > 2) {
					cout << "only enter a number  1 or 2" << "\n";
				}
			}
			cout << "CHOOSE 1-2:  " << flush;
			cin >> menuChoice;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n";
	} while (menuChoice != 2);

	cout << "\n" << "Goodbye!" << "\n" << flush;
	return 0;
}
