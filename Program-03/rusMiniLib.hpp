#include "Random.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void sortArray(size_t* arr, size_t arraySize) {
	for (size_t maxElement = arraySize - 1; maxElement > 0; maxElement--) {
		for (size_t i = 0; i < maxElement; i++) {
			if(arr[i] > arr[i + 1]) {
				arr[i] = arr[i] + arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] = arr[i] - arr[i + 1];
			}
		}
	}
}

bool binarySearchArray(size_t* arr, size_t key, size_t first, size_t last) {

	size_t middle;   // Mid point of search

	if(first > last) {   //value was not found
		return false;
	}

	middle = (first + last) / 2;
	if(middle == key) {
		return true;
	}

	if(middle > key) {
		//value not found yet and it is to the right of the middle
		return binarySearchArray(arr, key, middle + 1, last);
	}
	else {
		//value not found yet and it is to the left of the middle
		return binarySearchArray(arr, key, first, middle - 1);
	}
}

bool isInArray(size_t* arr, size_t size, size_t key) {
	sortArray(arr, size);
	return binarySearchArray(arr, key, 0, size - 1);
}

int main() {
	string winnerString = ",---,. ,---, ,----.. \" ,---,. ,---, ,----.. "
			"  ,'  .'  \\,`--.' | /   /   \\                                                                 " "\n"
			",---.' .' ||   :  :|   :     :                                                                " "\n"
			"|   |  |: |:   |  '.   |  ;. /                                                                " "\n"
			":   :  :  /|   :  |.   ; /--`                                                                 " "\n"
			":   |    ; '   '  ;;   | ;  __                                                                " "\n"
			"|   :     \\|   |  ||   : |.' .'                                                               " "\n"
			"|   |   . |'   :  ;.   | '_.' :                                                               " "\n"
			"'   :  '; ||   |  ''   ; : \\  |                        ,--.         ,--.                      " "\n"
			"|   |  | ; '   :  |'   | '/  .'  .---.   ,---,       ,--.'|       ,--.'|    ,---,.,-.----.    " "\n"
			"|   :   /  ;   |.' |   :    /   /. ./|,`--.' |   ,--,:  : |   ,--,:  : |  ,'  .' |\\    /  \\   " "\n"
			"|   | ,'   '---'    \\   \\ .'.--'.  ' ;|   :  :,`--.'`|  ' :,`--.'`|  ' :,---.'   |;   :    \\  " "\n"
			"`----'               `---` /__./ \\ : |:   |  '|   :  :  | ||   :  :  | ||   |   .'|   | .\\ :  " "\n"
			"                       .--'.  '   \\' .|   :  |:   |   \\ | ::   |   \\ | ::   :  |-,.   : |: |  " "\n"
			"                      /___/ \\ |    ' ''   '  ;|   : '  '; ||   : '  '; |:   |  ;/||   |  \\ :  " "\n"
			"                      ;   \\  \\;      :|   |  |'   ' ;.    ;'   ' ;.    ;|   :   .'|   : .  /  " "\n"
			"                       \\   ;  `      |'   :  ;|   | | \\   ||   | | \\   ||   |  |-,;   | |  \\  " "\n"
			"                        .   \\    .\\  ;|   |  ''   : |  ; .''   : |  ; .''   :  ;/||   | ;\\  \\ " "\n"
			"                         \\   \\   ' \\ |'   :  ||   | '`--'  |   | '`--'  |   |    \\:   ' | \\.' " "\n"
			"                          :   '  |--\"; |.' ' : | '  : | | : .': : :-'  " "\n"
			"                           \\   \\ ;    '---'   ;   |.'      ;   |.'      |   | ,'  |   |.'     " "\n"
			"                            '---\" '---'  '---'  `----'  `---'  " "\n";
	srand(time(NULL));
	string userInput[5];
	size_t usersNumbers[5];
	int winningNumber;
	winningNumber = 0;
	winningNumber += (rand() % 10);
	winningNumber += 10 * (rand() % 10);
	winningNumber += 100 * (rand() % 10);
	winningNumber += 1000 * (rand() % 10);
	winningNumber += 10000 * (rand() % 10);

	cout << "Mrs. Crockett, enter in your lucky numbers!" << "\n" << endl;
	for (size_t i = 0; i < 5; i++) {
		cout << i + 1 << ".  ";
		getline(cin, userInput[i]);
		while (cin.fail() || userInput[i].length() != 5 || !isdigit(userInput[i].at(0)) || !isdigit(userInput[i].at(1)) || !isdigit(userInput[i].at(2)) || !isdigit(userInput[i].at(3)) || !isdigit(userInput[i].at(4))) {
			clog << " dddd" << endl;
			if(cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Error, try again" << endl;
			}
			else {
				cout << "Be sure to enter a 5 digit (including zeros) number" << endl;
			}
			cout << i + 1 << ".  ";
			getline(cin, userInput[i]);
		}
	}
	clog << " out" << endl;

	for (size_t i = 0; i < 5; i++) {
		usersNumbers[i] = 0;

		usersNumbers[i] += (userInput[i].at(0) - 48);
		usersNumbers[i] += 10 * (userInput[i].at(1) - 48);
		usersNumbers[i] += 100 * (userInput[i].at(2) - 48);
		usersNumbers[i] += 1000 * (userInput[i].at(3) - 48);
		usersNumbers[i] += 10000 * (userInput[i].at(4) - 48);
	}

	if(isInArray(usersNumbers, 5, winningNumber)) {
		cout << winnerString << endl;
	}
	else {
		cout << "you lost" << endl;
	}

	return 0;
}
