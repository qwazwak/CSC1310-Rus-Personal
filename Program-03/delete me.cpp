#include "Random.h"

using namespace std;

void sortArray(size_t* arr, size_t arraySize){
	for (size_t maxElement = arraySize - 1; maxElement > 0; maxElement--){
		for (size_t i = 0; i < maxElement; i++) {
			if(arr[i] > arr[i + 1]) {
				arr[i] = arr[i] + arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1]; 
				arr[i] = arr[i] - arr[i + 1];
			}
		}
	}
}

bool isInArray(size_t* arr, size_t key, size_t first, size_t last){
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
		return isInArray(arr, key, middle + 1, last);
	}
	else {
		//value not found yet and it is to the left of the middle
		return isInArray(arr, key, first, middle - 1);
	}
}

int main(){
	
	srand();
	string userInput[5];
	int winningNumber;
	winningNumber = 0;
	winningNumber += (rand() % 10);
	winningNumber += 10 *(rand() % 10);
	winningNumber += 100 * (rand() % 10);
	winningNumber += 1000 * (rand() % 10);
	winningNumber += 10000 * (rand() % 10);
	
	cout << "Mrs. Crockett, enter in your lucky numbers!" << "\n" << endl;
	cout << "1.  ";
	getline(cin, userInput[0]);
	while(cin.fail() || userInput[0].getLength() != 6 ||
	!isAlpha(userInput.at(0)) || 
	!isAlpha(userInput.at(1)) || 
	!isAlpha(userInput.at(2)) || 
	!isAlpha(userInput.at(3)) || !isAlpha(userInput.at(4))){
	if(cin.fail()){
		cin.clear();
		cin.ignore();
		cout << "Error, try again" << endl;
	}
	
	}
		
	                                                                                              
                                                                                              
cout << "    ,---,.    ,---,  ,----..                                                                  " << endl;
cout << "  ,'  .'  \,`--.' | /   /   \                                                                 " << endl;
cout << ",---.' .' ||   :  :|   :     :                                                                " << endl;
cout << "|   |  |: |:   |  '.   |  ;. /                                                                " << endl;
cout << ":   :  :  /|   :  |.   ; /--`                                                                 " << endl;
cout << ":   |    ; '   '  ;;   | ;  __                                                                " << endl;
cout << "|   :     \|   |  ||   : |.' .'                                                               " << endl;
cout << "|   |   . |'   :  ;.   | '_.' :                                                               " << endl;
cout << "'   :  '; ||   |  ''   ; : \  |                        ,--.         ,--.                      " << endl;
cout << "|   |  | ; '   :  |'   | '/  .'  .---.   ,---,       ,--.'|       ,--.'|    ,---,.,-.----.    " << endl;
cout << "|   :   /  ;   |.' |   :    /   /. ./|,`--.' |   ,--,:  : |   ,--,:  : |  ,'  .' |\    /  \   " << endl;
cout << "|   | ,'   '---'    \   \ .'.--'.  ' ;|   :  :,`--.'`|  ' :,`--.'`|  ' :,---.'   |;   :    \  " << endl;
cout << "`----'               `---` /__./ \ : |:   |  '|   :  :  | ||   :  :  | ||   |   .'|   | .\ :  " << endl;
cout << "                       .--'.  '   \' .|   :  |:   |   \ | ::   |   \ | ::   :  |-,.   : |: |  " << endl;
cout << "                      /___/ \ |    ' ''   '  ;|   : '  '; ||   : '  '; |:   |  ;/||   |  \ :  " << endl;
cout << "                      ;   \  \;      :|   |  |'   ' ;.    ;'   ' ;.    ;|   :   .'|   : .  /  " << endl;
cout << "                       \   ;  `      |'   :  ;|   | | \   ||   | | \   ||   |  |-,;   | |  \  " << endl;
cout << "                        .   \    .\  ;|   |  ''   : |  ; .''   : |  ; .''   :  ;/||   | ;\  \ " << endl;
cout << "                         \   \   ' \ |'   :  ||   | '`--'  |   | '`--'  |   |    \:   ' | \.' " << endl;
cout << "                          :   '  |--" ;   |.' '   : |      '   : |      |   :   .':   : :-'   " << endl;
cout << "                           \   \ ;    '---'   ;   |.'      ;   |.'      |   | ,'  |   |.'     " << endl;
cout << "                            '---"             '---'        '---'        `----'    `---'       " << endl;
cout << "                                                                                              " << endl;

	return 0;
}