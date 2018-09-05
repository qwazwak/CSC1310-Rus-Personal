#include <iostream>
#include "Text.h"

using namespace std;

int main()
{
	Text* name;
	name = createText("Llama");
	displayText(name);
	cout << endl;
	destroyText(name);
	
	return 0;
}